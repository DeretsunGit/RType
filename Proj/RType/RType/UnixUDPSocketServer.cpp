#pragma	once

#ifndef	_WIN32

#include <stdexcept>
#include <cstring>
#include "UnixUDPSocketServer.h"

#define READ_SIZE 500
#include<iostream>
UnixUDPSocketServer::UnixUDPSocketServer(unsigned short port)
  : _sock(socket(AF_INET, SOCK_DGRAM, 0)), _live(true)
{
  struct sockaddr_in	sin;
  socklen_t		len;

  if (this->_sock == -1)
    throw std::runtime_error("UDPSocketServer: failed to create socket");
  memset(&sin, 0, sizeof(sin));
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (bind(this->_sock, reinterpret_cast<const sockaddr*>(&sin), sizeof(sin)) == -1)
    throw std::runtime_error("UDPSocketServer: failed to create socket");
  len = sizeof(sin);
  if (getsockname(this->_sock, reinterpret_cast<sockaddr*>(&sin), &len) == -1)
    throw std::runtime_error("UDPSocketServer: failed to create socket");
  this->_port = ntohs(sin.sin_port);
}

UnixUDPSocketServer::~UnixUDPSocketServer()
{
  if (close(this->_sock))
    std::cerr << "UDPSocketServer: close failed" << std::endl;
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

  this->_map[to.s_addr]._output.writeSome(buff, size);
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
    sent = !!it->second._output.readableSize();
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
  char		      buff[READ_SIZE];
  struct sockaddr_in  sin;
  int		      len;

  while (it != end && !it->second._output.readableSize())
    ++it;
  if (it != end)
  {
    memset(&sin, 0, sizeof(sin));
    sin.sin_addr.s_addr = it->first;
    sin.sin_family = AF_INET;
    this->_m.lock();
    sin.sin_port = it->second._port;
    len = it->second._output.readSome(buff, READ_SIZE);
    this->_m.unlock();
    if (sendto(this->_sock, buff, len, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin)) == -1)
      this->_live = false;
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

#endif	// !_WIN32
