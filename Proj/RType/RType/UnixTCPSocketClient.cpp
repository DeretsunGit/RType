#ifndef	_WIN32

# include	<iostream>
# include	<stdexcept>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>
# include	"UnixTCPSocketClient.h"
# include	"SocketPool.h"
# include	"Packet.hpp"
# include	"UnixSysException.h"
# include	"UnixHostException.h"

// TO REMOVE
# include	<stdio.h>

# define	READ_SIZE	1024

UnixTCPSocketClient::UnixTCPSocketClient(const char* hostname,
					 unsigned short port)
  : _sock(socket(AF_INET, SOCK_STREAM, 0)), _live(true)
{
  struct sockaddr_in	sin;
  struct hostent*	hostinfo;

  if (this->_sock == -1)
    throw UnixSysException("TCPSocketClient: socket");
  if (!(hostinfo = gethostbyname(hostname)))
    throw UnixHostException("TCPSocketClient: gethostbyname");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr = *reinterpret_cast<struct in_addr*>(hostinfo->h_addr);
  if (connect(this->_sock, reinterpret_cast<const struct sockaddr *>(&sin),
	      sizeof(sin)) == -1)
    throw UnixSysException("TCPSocketClient: connect");
}

UnixTCPSocketClient::UnixTCPSocketClient(SocketId id)
  : _sock(id), _live(true)
{}

UnixTCPSocketClient::~UnixTCPSocketClient()
{
  if (close(this->_sock) == -1)
    std::cerr << UnixSysException::GetError("~TCPSocketClient: close")
	      << std::endl;
  SocketPool::getInstance().releaseSocket(this);
}

void	      UnixTCPSocketClient::putback(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  this->_buff._input.putBack(buff, size);
}

void	UnixTCPSocketClient::send(const char* buff, unsigned int size)
{
  this->_m.lock();
  this->_buff._output.write(buff, size);
  this->_m.unlock();
}

void	UnixTCPSocketClient::send(const Packet& p)
{
  unsigned int			    size(p.getSize());
  std::list<char*>::const_iterator  it(p.getBuffer().begin());
  unsigned int			    sent;

  while (size > 0 && it != p.getBuffer().end())
  {
    sent = std::min<unsigned int>(size, 1024);
    this->send(*it, sent);
    size -= sent;
    ++it;
  }
}

unsigned int	UnixTCPSocketClient::recv(char* buff, unsigned int size)
{
  unsigned int	sent;

  this->_m.lock();
  sent = this->_buff._input.readSome(buff, size);
  this->_m.unlock();
  return (sent);
}

unsigned int	UnixTCPSocketClient::readable() const
{
  return (this->_buff._input.readableSize());
}

ISocket::SocketId	UnixTCPSocketClient::getId() const
{
  return (this->_sock);
}

bool		UnixTCPSocketClient::wantToWrite() const
{
  return (this->_buff._output.getSize() > 0);
}

void		UnixTCPSocketClient::readFromSock()
{
  char		buff[READ_SIZE];
  ssize_t	ret;

  if ((ret = ::recv(this->_sock, buff, READ_SIZE, 0)) <= 0)
    this->_live = false;
  else
    this->_buff._input.writeSome(buff, ret);
}

void		UnixTCPSocketClient::writeToSock()
{
  // char		buff[READ_SIZE];
  // unsigned int	ret(this->_buff._output.readSome(buff, READ_SIZE));
  unsigned int		ret(std::min<unsigned int>(1024, this->_buff._output.getSize()));

  if (::send(this->_sock, this->_buff._output.getBuffer().front(),
	     ret, 0) <= 0)
    this->_live = false;
  this->_buff._output.pop_front();
}

bool	UnixTCPSocketClient::isLive() const
{
  return (this->_live);
}

#endif	// !_WIN32
