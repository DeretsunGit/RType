#pragma once

#ifdef _WIN32

# include "IUDPSocketServer.h"
# include "IOBuff.h"
# include "Mutex.h"

class WinUDPSocketServer : public IUDPSocketServer
{
private:
  SocketId	 _sock;
  bool	  	 _live;
  BuffMap		 _map;
  Mutex		 _m;
  unsigned short	_port;

  WinUDPSocketServer();
  WinUDPSocketServer(const WinUDPSocketServer&);
  WinUDPSocketServer& operator=(const WinUDPSocketServer&);

public:
  WinUDPSocketServer(unsigned short);
  virtual	      ~WinUDPSocketServer();
  unsigned short	getPort() const;
  unsigned int  readableFor(const in_addr& from) const;
  unsigned int  readFrom(char* buff, unsigned int size, const in_addr& from);
  unsigned int  recvFrom(char* buff, unsigned int size, in_addr& from);
  void		broadcast(const char* buff, unsigned int size);
  void		broadcast(const Packet& p);
  void	      sendTo(const char* buff, unsigned int size, const in_addr& to);
  void	      sendTo(const Packet& p, const in_addr& to);
  UDPBindedClient&  getClient(const in_addr&);
  SocketId      getId() const;
  bool	      wantToWrite() const;
  void	      readFromSock();
  void	      writeToSock();
  bool	      isLive() const;
};

#endif // _WIN32
