#pragma once

#include "Thread.h"
#include "TCPSocketClient.h"
#include "UDPSocketClient.h"

class Debugger
{
public:
  Debugger(const char* host, unsigned short port);
  ~Debugger();

  void	start();

private:
  Thread	    _th;
  TCPSocketClient   _tcp;
  UDPSocketClient*  _udp;
  bool		    _live;

  void	networkThread();

  Debugger();
  Debugger(const Debugger&);
  Debugger& operator=(const Debugger&);
};
