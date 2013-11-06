#pragma once

#ifdef _WIN32

# include "WinUDPSocketServer.h"

typedef WinUDPSocketServer  BasicUDPSocketServer;

#else

# include "UnixUDPSocketServer.h"

typedef UnixUDPSocketServer  BasicUDPSocketServer;

#endif // _WIN32

#include "SocketPool.h"

class UDPSocketServer: public BasicUDPSocketServer
{
public:
  UDPSocketServer(unsigned short port)
    : BasicUDPSocketServer(port)
  {
    SocketPool::getInstance().watchSocket(this);
  }

  ~UDPSocketServer()
  {
    SocketPool::getInstance().releaseSocket(this);
  }

private:
  UDPSocketServer();
  UDPSocketServer(const UDPSocketServer&);
  UDPSocketServer&  operator=(const UDPSocketServer&);
};