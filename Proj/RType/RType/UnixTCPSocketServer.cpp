//
// UnixTCPSocketServer.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Tue Nov  5 03:17:17 2013 julien edmond
// Last update Sun Nov 17 14:52:33 2013 julien edmond
//

#ifndef	_WIN32

# include	<iostream>
# include	<stdexcept>
# include	<netinet/ip.h>
# include	"UnixTCPSocketServer.h"
# include	"UnixTCPSocketClient.h"
# include	"SocketPool.h"
# include	"UnixSysException.h"
# include	"UnixHostException.h"

# define	MAX_LISTEN	20

UnixTCPSocketServer::UnixTCPSocketServer(unsigned short port)
  : _live(true), _sock(socket(AF_INET, SOCK_STREAM, 0))
{
  struct sockaddr_in	sin;

  if (this->_sock == -1)
    throw UnixSysException("TCPSocketServer: socket");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(this->_sock, reinterpret_cast<const struct sockaddr*>(&sin),
	   sizeof(sin)) == -1)
    throw UnixSysException("TCPSocketServer: bind");
  if (listen(this->_sock, 20) == -1)
    throw UnixSysException("TCPSocketServer: listen");
}

UnixTCPSocketServer::~UnixTCPSocketServer()
{
  if (close(this->_sock))
    std::cerr << UnixSysException::GetError("TCPSocketServer: close")
	      << std::endl;
  this->_m.lock();
  while (this->_clients.size())
    {
      delete this->_clients.front();
      this->_clients.pop();
    }
  this->_m.unlock();
}

ISocket::SocketId	UnixTCPSocketServer::getId() const
{
  return (this->_sock);
}

bool	UnixTCPSocketServer::wantToWrite() const
{
  return (false);
}

void	UnixTCPSocketServer::readFromSock()
{
  this->_m.lock();
  this->_clients.push(new UnixTCPSocketClient(::accept(this->_sock, NULL,
						       NULL)));
  this->_m.unlock();
}

void	UnixTCPSocketServer::writeToSock()
{}

ITCPSocketClient*	UnixTCPSocketServer::accept()
{
  ITCPSocketClient*	sent(NULL);

  if (!this->_clients.empty())
    {
      this->_m.lock();
      sent = this->_clients.front();
      this->_clients.pop();
      this->_m.unlock();
      SocketPool::getInstance().watchSocket(sent);
    }
  return (sent);
}

bool	UnixTCPSocketServer::isLive() const
{
  return (this->_live);
}

#endif	// !_WIN32
