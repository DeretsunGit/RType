#pragma once

#ifdef	_WIN32

# include	<Inaddr.h>

#else

# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

#endif	// !_WIN32

#include "Socket.h"

class IUDPSocket : public ISocket
{
public:
  virtual ~IUDPSocket() {}

  virtual unsigned int	readableFor(const in_addr& from) = 0;
  virtual unsigned int	readFrom(char* buff, unsigned int size,
				 const in_addr& from) = 0;
  virtual unsigned int	recvFrom(char* buff, unsigned int size,
				 in_addr& from) = 0;
  virtual void		sendTo(const char* buff, unsigned int size,
			       const in_addr& to) = 0;
};