#pragma once

#ifdef	_WIN32

# include	<Inaddr.h>

#else

# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

#endif	// !_WIN32

#include <map>
#include "IReadableSocket.h"
#include "IOBuff.h"
#include "Packet.hpp"

class IUDPSocketClient : public IReadableSocket
{
public:
  virtual ~IUDPSocketClient() {}

  virtual void		  putback(const char* buff, unsigned int size) = 0;
  virtual unsigned int	  readable() const = 0;
  virtual unsigned int	  recv(char* buff, unsigned int size) = 0;
  virtual void		  send(const char* buff, unsigned int size) = 0;
  virtual void		  send(const Packet& p) = 0;
};
