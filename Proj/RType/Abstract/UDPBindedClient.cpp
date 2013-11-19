#include  "IUDPSocketServer.h"

IUDPSocketServer::UDPBindedClient::UDPBindedClient()
{}

IUDPSocketServer::UDPBindedClient::UDPBindedClient(const UDPBindedClient& c)
  : UDPBuff<>(c)
{}

IUDPSocketServer::UDPBindedClient&  IUDPSocketServer::UDPBindedClient::operator=(const UDPBindedClient& c)
{
  if (this != &c)
    this->UDPBuff<>::operator=(c);
  return (*this);
}

IUDPSocketServer::UDPBindedClient::~UDPBindedClient()
{}

void  IUDPSocketServer::UDPBindedClient::putback(const char* buff, unsigned int size)
{
  this->_input.putBack(buff, size);
}

unsigned int  IUDPSocketServer::UDPBindedClient::recv(char* buff, unsigned int size)
{
  return (this->_input.readSome(buff, size));
}

unsigned int  IUDPSocketServer::UDPBindedClient::readable() const
{
  return (this->_input.readableSize());
}

ISocket::SocketId	  IUDPSocketServer::UDPBindedClient::getId() const
{
  return (0);
}

bool	  IUDPSocketServer::UDPBindedClient::wantToWrite() const
{
  return (false);
}

void	  IUDPSocketServer::UDPBindedClient::readFromSock()
{}

void	  IUDPSocketServer::UDPBindedClient::writeToSock()
{}

bool	  IUDPSocketServer::UDPBindedClient::isLive() const
{
  return (true);
}
