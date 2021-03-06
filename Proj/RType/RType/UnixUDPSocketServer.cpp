#ifndef	_WIN32

# include <iostream>
# include <stdexcept>
# include <cstring>
# include "UnixUDPSocketServer.h"
# include "UnixSysException.h"

#define READ_SIZE 1024

UnixUDPSocketServer::UnixUDPSocketServer(unsigned short port)
  : _sock(socket(AF_INET, SOCK_DGRAM, 0)), _live(true)
{
  struct sockaddr_in	sin;
  socklen_t		len;

  if (this->_sock == -1)
    throw UnixSysException("UDPSocketServer: socket");
  memset(&sin, 0, sizeof(sin));
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (bind(this->_sock, reinterpret_cast<const sockaddr*>(&sin), sizeof(sin)) == -1)
    throw UnixSysException("UDPSocketServer: bind");
  len = sizeof(sin);
  if (getsockname(this->_sock, reinterpret_cast<sockaddr*>(&sin), &len) == -1)
    throw UnixSysException("UDPSocketServer: getsockname");
  this->_port = ntohs(sin.sin_port);
}

UnixUDPSocketServer::~UnixUDPSocketServer()
{
  if (close(this->_sock))
    std::cerr << UnixSysException::GetError("UDPSocketServer: close")
	      << std::endl;
}

unsigned int		  UnixUDPSocketServer::readableFor(const in_addr& from) const
{
  unsigned int		  sent(0);
  BuffMap::const_iterator it(this->_map.find(from.s_addr));

  if (it != this->_map.end())
    sent = it->second._input.readableSize();
  return (sent);
}

unsigned int		  UnixUDPSocketServer::readFrom(char* buff, unsigned int size, const in_addr& from)
{
  ScopedLock	    lock(this->_m);
  unsigned int	    sent(0);
  BuffMap::iterator it(this->_map.find(from.s_addr));

  if (it != this->_map.end())
    sent = it->second._input.readSome(buff, size);
  return (sent);
}

unsigned int  UnixUDPSocketServer::recvFrom(char* buff, unsigned int size, in_addr& from)
{
  ScopedLock	    lock(this->_m);
  unsigned int	sent(0);
  BuffMap::iterator it(this->_map.begin());

  if (it != this->_map.end())
  {
    from.s_addr = it->first;
    sent = it->second._input.readSome(buff, size);
  }
  return (sent);
}

void  UnixUDPSocketServer::sendTo(const char* buff, unsigned int size, const in_addr& to)
{
  ScopedLock	    lock(this->_m);

  this->_map[to.s_addr]._output.write(buff, size);
}

void  UnixUDPSocketServer::sendTo(const Packet& p, const in_addr& to)
{
  unsigned int			    size(p.getSize());
  std::list<char*>::const_iterator  it(p.getBuffer().begin());
  unsigned int			    sent;

  while (size > 0 && it != p.getBuffer().end())
  {
    sent = std::min<unsigned int>(size, 1024);
    this->sendTo(*it, sent, to);
    size -= sent;
    ++it;
  }
}

void			UnixUDPSocketServer::broadcast(const char* buff,
						       unsigned int size)
{
  ScopedLock		lock(this->_m);
  BuffMap::iterator	it(this->_map.begin());
  BuffMap::iterator	end(this->_map.end());

  while (it != end)
    {
      it->second._output.write(buff, size);
      ++it;
    }
}

void			UnixUDPSocketServer::broadcast(const Packet& p)
{
  BuffMap::iterator	it(this->_map.begin());
  BuffMap::iterator	end(this->_map.end());

  while (it != end)
    {
      this->sendTo(p, reinterpret_cast<const in_addr&>(it->first));
      ++it;
    }
}

ISocket::SocketId UnixUDPSocketServer::getId() const
{
  return (this->_sock);
}

bool			  UnixUDPSocketServer::wantToWrite() const
{
  bool			  sent(false);
  BuffMap::const_iterator it(this->_map.begin());
  BuffMap::const_iterator end(this->_map.end());

  while (!sent && it != end)
  {
    sent = !!it->second._output.getSize();
    ++it;
  }
  return (sent);
}

void		      UnixUDPSocketServer::readFromSock()
{
  char		      buff[READ_SIZE];
  struct sockaddr_in  sin;
  ssize_t	      red;
  socklen_t	      size = sizeof(sin);

  if ((red = recvfrom(this->_sock, buff, READ_SIZE, 0, reinterpret_cast<struct sockaddr*>(&sin), &size)) <= 0)
    this->_live = false;
  else
  {
    this->_m.lock();
    this->_map[sin.sin_addr.s_addr]._input.writeSome(buff, red);
    this->_map[sin.sin_addr.s_addr]._port = sin.sin_port;
    this->_m.unlock();
  }
}

void	UnixUDPSocketServer::writeToSock()
{
  BuffMap::iterator   it(this->_map.begin());
  BuffMap::iterator   end(this->_map.end());
  // char		      buff[READ_SIZE];
  struct sockaddr_in  sin;
  int		      len;

  while (it != end && !it->second._output.getSize())
    ++it;
  if (it != end)
  {
    memset(&sin, 0, sizeof(sin));
    sin.sin_addr.s_addr = it->first;
    sin.sin_family = AF_INET;
    this->_m.lock();
    sin.sin_port = it->second._port;
    len = std::min<unsigned int>(1024, it->second._output.getSize());
    // len = it->second._output.readSome(buff, READ_SIZE);
    if (sendto(this->_sock, it->second._output.getBuffer().front(), len, 0,
	       reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin)) == -1)
      this->_map.erase(it);
    else
      it->second._output.pop_front();
    this->_m.unlock();
  }
}

unsigned short UnixUDPSocketServer::getPort() const
{
  return (this->_port);
}

bool  UnixUDPSocketServer::isLive() const
{
  return (this->_live);
}

IUDPSocketServer::UDPBindedClient&  UnixUDPSocketServer::getClient(const in_addr& c)
{
  return (this->_map[c.s_addr]);
}

IUDPSocketServer::BuffMap::iterator		UnixUDPSocketServer::begin()
{
  return (this->_map.begin());
}

IUDPSocketServer::BuffMap::const_iterator	UnixUDPSocketServer::begin() const
{
  return (this->_map.begin());
}

IUDPSocketServer::BuffMap::iterator		UnixUDPSocketServer::end()
{
  return (this->_map.end());
}

IUDPSocketServer::BuffMap::const_iterator	UnixUDPSocketServer::end() const
{
  return (this->_map.end());
}


#endif	// !_WIN32
