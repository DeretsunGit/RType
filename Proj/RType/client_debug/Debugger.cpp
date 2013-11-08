#include <iostream>
#include <sstream>
#include "Debugger.h"

Debugger::Debugger(const char* hostname, unsigned short port)
  : _th(*this, &Debugger::networkThread), _tcp(hostname, port), _udp(NULL), _live(true)
{
  _comm.setHandler(this);
  _comm.setDefaultCallback(&Debugger::defaultHandler);
  //_comm.setCallback
}

Debugger::~Debugger()
{
  this->_live = false;
  this->_th.join();
}

void	      Debugger::start()
{
  std::string line;
  this->_th.start();
  while (std::getline(std::cin, line))
  {
    line += '\n';
    // Treat command
    this->_tcp.send(line.c_str(), line.size());
  }
}

void	      Debugger::networkThread()
{
  char	      buff[255];
  int	      ret;

  while (this->_live)
  {
    this->_comm.interpretCommand(this->_tcp);
    if (this->_udp)
      this->_comm.interpretCommand(*this->_udp);
    Sleep(1);
  }
}

void	Debugger::defaultHandler(char opcode, IReadableSocket& sock)
{
  std::cout << "Received unknown opcode (" << static_cast<int>(opcode)
	    << ") on " << (&sock == this->_udp ? "UDP" : "TCP")
	    << " socket." << std::endl;
}
