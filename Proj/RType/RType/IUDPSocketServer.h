#pragma once

#ifdef	_WIN32

# include	<Windows.h>

#else

# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

#endif	// !_WIN32

#include <map>
#include "Socket.h"
#include "IOBuff.h"
#include "Packet.hpp"

class IUDPSocketServer : public ISocket
{
public:
  typedef std::map<u_long, UDPBuff<> > BuffMap;

  virtual ~IUDPSocketServer() {}

  virtual unsigned short  getPort() const = 0;
  virtual unsigned int	  readableFor(const in_addr& from) const = 0;
  virtual unsigned int	  readFrom(char* buff, unsigned int size,
				   const in_addr& from) = 0;
  virtual unsigned int	  recvFrom(char* buff, unsigned int size,
				   in_addr& from) = 0;
  virtual void		  sendTo(const char* buff, unsigned int size,
			         const in_addr& to) = 0;
  virtual void		  sendTo(const Packet* p, const in_addr& to) = 0;
};
