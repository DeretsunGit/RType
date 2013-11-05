#pragma once

#ifdef _WIN32

# include "WinUDPSocketClient.h"

typedef WinUDPSocketClient  BasicUDPSocketClient;

#else

# include "UnixUDPSocketClient.h"

typedef UnixUDPSocketClient  BasicUDPSocketClient;

#endif // _WIN32

#include "SocketPool.h"

class UDPSocketClient: public BasicUDPSocketClient
{
public:
  UDPSocketClient(const char* hostname, unsigned short port)
    : BasicUDPSocketClient(hostname, port)
  {
    SocketPool::getInstance().watchSocket(this);
  }

  ~UDPSocketClient()
  {
    SocketPool::getInstance().releaseSocket(this);
  }

private:
  UDPSocketClient();
  UDPSocketClient(const UDPSocketClient&);
  UDPSocketClient&  operator=(const UDPSocketClient&);
};