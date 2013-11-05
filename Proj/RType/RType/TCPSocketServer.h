//
// TCPSocketServer.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Tue Nov  5 03:36:00 2013 julien edmond
// Last update Tue Nov  5 03:38:39 2013 julien edmond
//

#pragma	once

#include	"SocketPool.h"

#ifdef	_WIN32

# include	"WinTCPSocketServer.h"

typedef WinTCPSocketServer	BasicTCPSocketServer;

#else

# include	"UnixTCPSocketServer.h"

typedef UnixTCPSocketServer	BasicTCPSocketServer;

#endif	// !_WIN32

class	TCPSocketServer: public BasicTCPSocketServer
{
public:
  TCPSocketServer(unsigned short port)
    : BasicTCPSocketServer(port)
  {
    SocketPool::getInstance().watchSocket(this);
  }

  ~TCPSocketServer()
  {
    SocketPool::getInstance().watchSocket(this);
  }

private:
  TCPSocketServer();
  TCPSocketServer(const TCPSocketServer&);
  TCPSocketServer&	operator=(const TCPSocketServer&);
};
