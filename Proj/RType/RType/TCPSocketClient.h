#pragma once

#include "SocketPool.h"

#ifdef	_WIN32

# include	"WinTCPSocketClient.h"

typedef WinTCPSocketClient	BasicTCPSocketClient;

#else

# include	"UnixTCPSocketClient.h"

typedef UnixTCPSocketClient	BasicTCPSocketClient;

#endif	// _WIN32

class	TCPSocketClient: public BasicTCPSocketClient
{
public:
  TCPSocketClient(const char* hostname, unsigned short port)
    : BasicTCPSocketClient(hostname, port)
  {
    SocketPool::getInstance().watchSocket(this);
  }

  ~TCPSocketClient()
  {
    SocketPool::getInstance().releaseSocket(this);
  }

private:
  TCPSocketClient();
  TCPSocketClient(const TCPSocketClient&);
  TCPSocketClient& operator=(const TCPSocketClient&);
};
