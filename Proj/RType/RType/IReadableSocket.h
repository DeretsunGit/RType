#pragma once

#include  "Socket.h"
#include  "Packet.hpp"

class IReadableSocket: public ISocket
{
public:
  virtual ~IReadableSocket() {}

  virtual void	        putback(const char* buff, unsigned int size) = 0;
  virtual unsigned int	recv(char* buff, unsigned int size) = 0;
  virtual unsigned int	readable() const = 0;
};