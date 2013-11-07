#include <iostream>
#include <sstream>
#include "Debugger.h"

Debugger::Debugger(const char* hostname, unsigned short port)
  : _th(*this, &Debugger::networkThread), _tcp(hostname, port), _udp(NULL), _live(true)
{}

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
    if ((ret = this->_tcp.recv(buff, sizeof(buff))) > 0)
    {
      std::ostringstream  stream;
      buff[ret] = 0;
      stream << "TCP received: [" << buff << "]\n";      
      std::cout << stream.str() << std::flush;
    }
    if (this->_udp && (ret = this->_udp->recv(buff, sizeof(buff))) > 0)
    {
      std::ostringstream  stream;
      buff[ret] = 0;
      stream << "TCP received: [" << buff << "]\n";      
      std::cout << stream.str() << std::flush;
    }
  }
}