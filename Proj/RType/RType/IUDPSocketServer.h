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
#include "IReadableSocket.h"
#include "IOBuff.h"
#include "Packet.hpp"

class IUDPSocketServer : public ISocket
{
public:
  class UDPBindedClient: public IReadableSocket, public UDPBuff<>
  {
  public:
    UDPBindedClient();
    ~UDPBindedClient();
    UDPBindedClient(const UDPBindedClient&);
    UDPBindedClient&  operator=(const UDPBindedClient&);

    void	  putback(const char* buff, unsigned int size);
    unsigned int  recv(char* buff, unsigned int size);
    unsigned int  readable() const;
    SocketId	  getId() const;
    bool	  wantToWrite() const;
    void	  readFromSock();
    void	  writeToSock();
    bool	  isLive() const;

  private:
  };

  typedef std::map<u_long, UDPBindedClient> BuffMap;

  virtual ~IUDPSocketServer() {}

  virtual unsigned short  getPort() const = 0;
  virtual unsigned int	  readableFor(const in_addr& from) const = 0;
  virtual unsigned int	  readFrom(char* buff, unsigned int size,
				   const in_addr& from) = 0;
  virtual unsigned int	  recvFrom(char* buff, unsigned int size,
				   in_addr& from) = 0;
  virtual void		  sendTo(const char* buff, unsigned int size,
			         const in_addr& to) = 0;
  virtual void		  sendTo(const Packet& p, const in_addr& to) = 0;
  virtual void		  broadcast(const char* buff, unsigned int size) = 0;
  virtual void		  broadcast(const Packet& p) = 0;
  virtual UDPBindedClient&  getClient(const in_addr&) = 0;
  virtual BuffMap::iterator		begin() = 0;
  virtual BuffMap::const_iterator	begin() const = 0;
  virtual BuffMap::iterator		end() = 0;
  virtual BuffMap::const_iterator	end() const = 0;
};
