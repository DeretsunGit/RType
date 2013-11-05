#ifdef _WIN32

#include <stdexcept>
#include <winsock2.h>
#include "WinUDPSocketClient.h"

#define READ_SIZE 500

WinUDPSocketClient::WinUDPSocketClient(unsigned short port)
  : _sock(WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0)), _live(true), _port(port)
{
  if (_sock == INVALID_SOCKET)
    throw std::runtime_error("UDPSocketClient: failed to create socket");
}

WinUDPSocketClient::~WinUDPSocketClient()
{
  closesocket(this->_sock);
}

unsigned int		  WinUDPSocketClient::readableFor(const in_addr& from) const
{
  unsigned int		  sent(0);
  BuffMap::const_iterator it(this->_map.find(from.S_un.S_addr));

  if (it != this->_map.end())
    sent = it->second._input.readableSize();
  return (sent);
}

unsigned int		  WinUDPSocketClient::readFrom(char* buff, unsigned int size, const in_addr& from)
{
  ScopedLock	    lock(this->_m);
  unsigned int	    sent(0);
  BuffMap::iterator it(this->_map.find(from.S_un.S_addr));

  if (it != this->_map.end())
    sent = it->second._input.readSome(buff, size);
  return (sent);
}

unsigned int  WinUDPSocketClient::recvFrom(char* buff, unsigned int size, in_addr& from)
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

void  WinUDPSocketClient::sendTo(const char* buff, unsigned int size, const in_addr& to)
{
  ScopedLock	    lock(this->_m);
  this->_map[to.S_un.S_addr]._output.writeSome(buff, size);
}

ISocket::SocketId WinUDPSocketClient::getId() const
{
  return (this->_sock);
}

bool			  WinUDPSocketClient::wantToWrite() const
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

void		      WinUDPSocketClient::readFromSock()
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
    this->_m.unlock();
  }
}

void	WinUDPSocketClient::writeToSock()
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
    sin.sin_port = htons(this->_port);
    this->_m.lock();
    buff.len = it->second._output.readSome(buf, READ_SIZE);
    this->_m.unlock();
    if (WSASendTo(this->_sock, &buff, buff.len, &buff.len, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin), NULL, NULL) == SOCKET_ERROR)
      this->_live = false;
  }
}

bool  WinUDPSocketClient::isLive() const
{
  return (this->_live);
}

#endif // _WIN32
