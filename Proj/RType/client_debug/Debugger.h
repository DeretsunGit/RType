#pragma once

#include "ClientCommunication.hpp"
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
  Thread			_th;
  TCPSocketClient		_tcp;
  UDPSocketClient*		_udp;
  bool				_live;
  ClientCommunication<Debugger>	_comm;

  void	networkThread();

  Debugger();
  Debugger(const Debugger&);
  Debugger& operator=(const Debugger&);

  void	defaultHandler(char opcode, IReadableSocket& sock);
};
