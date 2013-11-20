#ifdef _WIN32

#include <iostream>
#include <stdexcept>
#include <winsock2.h>
#include "WinUDPSocketClient.h"
#include  "WSAException.h"

#define	READ_SIZE 1024

WinUDPSocketClient::WinUDPSocketClient(const char* hostname, unsigned short port)
  : _sock(WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, 0)), _live(true), _port(port)
{
  struct hostent* ent;

  if (this->_sock == INVALID_SOCKET)
    throw WSAException("UDPSocketClient: WSASocket");
  if (!(ent = gethostbyname(hostname)))
    throw WSAException("UDPSocketClient: gethostbyname");
  this->_host = *reinterpret_cast<IN_ADDR*>(ent->h_addr);
}

WinUDPSocketClient::~WinUDPSocketClient()
{
  if (closesocket(this->_sock))
    std::cerr << WSAException::GetError("~UDPSocketClient: closesocket") << std::endl;
}

unsigned int  WinUDPSocketClient::readable() const
{
  return (this->_buff._input.readableSize());
}

void	      WinUDPSocketClient::putback(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  this->_buff._input.putBack(buff, size);
}

unsigned int  WinUDPSocketClient::recv(char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);
  return (this->_buff._input.readSome(buff, size));
}

void  WinUDPSocketClient::send(const char* buff, unsigned int size)
{
  ScopedLock  lock(this->_m);

  this->_buff._output.write(buff, size);
}

void  WinUDPSocketClient::send(const Packet& p)
{
  unsigned int			    size(p.getSize());
  std::list<char*>::const_iterator  it(p.getBuffer().begin());
  unsigned int			    sent;

  while (size > 0)
  {
    sent = std::min<unsigned int>(size, 1024);
    this->send(*it, sent);
    size -= sent;
    ++it;
  }
}

ISocket::SocketId WinUDPSocketClient::getId() const
{
  return (this->_sock);
}

bool  WinUDPSocketClient::wantToWrite() const
{
  return (!!this->_buff._output.getSize());
}

void  WinUDPSocketClient::readFromSock()
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
  else if (sin.sin_addr.S_un.S_addr == this->_host.S_un.S_addr)
  {
    this->_m.lock();
    this->_buff._input.writeSome(buff.buf, red);
    this->_buff._port = sin.sin_port;
    this->_m.unlock();
  }
}

void	WinUDPSocketClient::writeToSock()
{
  WSABUF	      buff;
  //  char		      buf[READ_SIZE];
  struct sockaddr_in  sin;

  //  buff.buf = buf;
  ZeroMemory(&sin, sizeof(sin));
  sin.sin_addr.S_un.S_addr = this->_host.S_un.S_addr;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(this->_port);
  this->_m.lock();
  //  buff.len = this->_buff._output.readSome(buf, READ_SIZE);
  buff.len = std::min<unsigned int>(this->_buff._output.getSize(), 1024);
  buff.buf = this->_buff._output.getBuffer().front();
  if (WSASendTo(this->_sock, &buff, 1, &buff.len, 0, reinterpret_cast<struct sockaddr*>(&sin), sizeof(sin), NULL, NULL) == SOCKET_ERROR)
    this->_live = false;
  this->_buff._output.pop_front();
  this->_m.unlock();
}

bool  WinUDPSocketClient::isLive() const
{
  return (this->_live);
}

#endif // _WIN32
