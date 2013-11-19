#ifdef _WIN32

#include<iostream>
#include <stdexcept>
#include <winsock2.h>
#include "WinUDPSocketServer.h"
#include  "WSAException.h"

#define READ_SIZE 500

WinUDPSocketServer::WinUDPSocketServer(unsigned short port)
  : _sock(WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0)), _live(true)
{
  struct sockaddr_in	sin;
  int			len;

  if (_sock == INVALID_SOCKET)
    throw WSAException("UDPSocketServer: WSASocket");
  ZeroMemory(&sin, sizeof(sin));
  sin.sin_addr.S_un.S_addr = INADDR_ANY;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (bind(this->_sock, reinterpret_cast<const sockaddr*>(&sin), sizeof(sin)) == SOCKET_ERROR)
    throw WSAException("UDPSocketServer: bind");
  len = sizeof(sin);
  if (getsockname(this->_sock, reinterpret_cast<sockaddr*>(&sin), &len) == SOCKET_ERROR)
    throw WSAException("UDPSocketServer: getsockname");
  this->_port = ntohs(sin.sin_port);
}

WinUDPSocketServer::~WinUDPSocketServer()
{
  closesocket(this->_sock);
}

unsigned int		  WinUDPSocketServer::readableFor(const in_addr& from) const
{
  unsigned int		  sent(0);
  BuffMap::const_iterator it(this->_map.find(from.S_un.S_addr));

  if (it != this->_map.end())
    sent = it->second._input.readableSize();
  return (sent);
}

unsigned int		  WinUDPSocketServer::readFrom(char* buff, unsigned int size, const in_addr& from)
{
  ScopedLock	    lock(this->_m);
  unsigned int	    sent(0);
  BuffMap::iterator it(this->_map.find(from.S_un.S_addr));

  if (it != this->_map.end())
    sent = it->second._input.readSome(buff, size);
  return (sent);
}

unsigned int  WinUDPSocketServer::recvFrom(char* buff, unsigned int size, in_addr& from)
{
  ScopedLock	    lock(this->_m);
  unsigned int	sent(0);
  BuffMap::iterator it(this->_map.begin());

  if (it != this->_map.end())
  {
    from.S_un.S_addr = it->first;
    sent = it->second._input.readSome(buff, size);
  }
  return (sent);
}

void  WinUDPSocketServer::sendTo(const char* buff, unsigned int size, const in_addr& to)
{
  ScopedLock	    lock(this->_m);
  this->_map[to.S_un.S_addr]._output.writeSome(buff, size);
}

void  WinUDPSocketServer::sendTo(const Packet& p, const in_addr& to)
{
  unsigned int			    size(p.getSize());
  std::list<char*>::const_iterator  it(p.getBuffer().begin());
  unsigned int			    sent;

  while (size >= 0)
  {
    sent = std::min<unsigned int>(size, 1024);
    this->sendTo(*it, sent, to);
    size -= sent;
    ++it;
  }
}

void	WinUDPSocketServer::broadcast(const char* buff, unsigned int size)
{
  ScopedLock	lock(this->_m);
  BuffMap::iterator	it(this->_map.begin());
  BuffMap::iterator	end(this->_map.end());

  while (it != end)
    {
      it->second._output.writeSome(buff, size);
      ++it;
    }
}

void	WinUDPSocketServer::broadcast(const Packet& packet)
{
  ScopedLock	lock(this->_m);
  BuffMap::iterator	it(this->_map.begin());
  BuffMap::iterator	end(this->_map.end());

  while (it != end)
    {
      this->sendTo(packet, reinterpret_cast<const in_addr&>(it->first));
      ++it;
    }
}

ISocket::SocketId WinUDPSocketServer::getId() const
{
  return (this->_sock);
}

bool			  WinUDPSocketServer::wantToWrite() const
{
  bool			  sent(false);
  BuffMap::const_iterator it(this->_map.begin());
  BuffMap::const_iterator end(this->_map.end());

  while (!sent && it != end)
  {
    sent = !!it->second._output.readableSize();
    ++it;
  }
  return (sent);
}

void		      WinUDPSocketServer::readFromSock()
{
  WSABUF	      buff;
  char		      buf[READ_SIZE];
  struct sockaddr_in  sin;
  DWORD		      red;
  DWORD		      opt(0);
  INT		      size(sizeof(sin));

  buff.buf = buf;
  buff.len = READ_SIZE;
  if (WSARecvFrom(this->_sock, &buff, 1, &red, &opt, reinterpret_cast<struct sockaddr*>(&sin), &size, NULL, NULL) == SOCKET_ERROR)
    this->_live = false;
  else
  {
    this->_m.lock();
    this->_map[sin.sin_addr.S_un.S_addr]._input.writeSome(buff.buf, red);
    this->_map[sin.sin_addr.S_un.S_addr]._port = sin.sin_port;
    this->_m.unlock();
  }
}

void	WinUDPSocketServer::writeToSock()
{
  BuffMap::iterator   it(this->_map.begin());
  BuffMap::iterator   end(this->_map.end());
  WSABUF	      buff;
  char		      buf[READ_SIZE];
  struct sockaddr_in  sin;

  buff.buf = buf;
  while (it != end && !it->second._output.readableSize())
    ++it;
  if (it != end)
  {
    ZeroMemory(&sin, sizeof(sin));
    sin.sin_addr.S_un.S_addr = it->first;
    sin.sin_family = AF_INET;
    this->_m.lock();
    sin.sin_port = it->second._port;
    buff.len = it->second._output.readSome(buf, READ_SIZE);
    if (WSASendTo(this->_sock, &buff, 1, &buff.len, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin), NULL, NULL) == SOCKET_ERROR)
      this->_map.erase(it);
    this->_m.unlock();
  }
}

unsigned short WinUDPSocketServer::getPort() const
{
  return (this->_port);
}

bool  WinUDPSocketServer::isLive() const
{
  return (this->_live);
}

IUDPSocketServer::UDPBindedClient&  WinUDPSocketServer::getClient(const in_addr& c)
{
  return (this->_map[c.S_un.S_addr]);
}

IUDPSocketServer::UDPBindedClient&  UnixUDPSocketServer::getClient(const in_addr& c)
{
  return (this->_map[c.s_addr]);
}

IUDPSocketServer::BuffMap::iterator		WinUDPSocketServer::begin()
{
  return (this->_map.begin());
}

IUDPSocketServer::BuffMap::const_iterator	WinUDPSocketServer::begin() const
{
  return (this->_map.begin());
}

IUDPSocketServer::BuffMap::iterator		WinUDPSocketServer::end()
{
  return (this->_map.end());
}

IUDPSocketServer::BuffMap::const_iterator	WinUDPSocketServer::end() const
{
  return (this->_map.end());
}

#endif // _WIN32
