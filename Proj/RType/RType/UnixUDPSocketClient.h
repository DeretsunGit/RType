#pragma once

#ifndef	_WIN32

# include "IUDPSocketClient.h"
# include "IOBuff.h"
# include "Mutex.h"

class UnixUDPSocketClient : public IUDPSocketClient
{
private:
  SocketId	 _sock;
  bool	  	 _live;
  UDPBuff<>	 _buff;
  Mutex		 _m;
  unsigned short	_port;
  IN_ADDR		_host;

  UnixUDPSocketClient();
  UnixUDPSocketClient(const UnixUDPSocketClient&);
  UnixUDPSocketClient& operator=(const UnixUDPSocketClient&);

public:
  UnixUDPSocketClient(const char* hostname, unsigned short port);
  virtual	      ~UnixUDPSocketClient();
  unsigned int  readable() const;
  unsigned int  recv(char* buff, unsigned int size);
  void	      send(const char* buff, unsigned int size);
  SocketId      getId() const;
  bool	      wantToWrite() const;
  void	      readFromSock();
  void	      writeToSock();
  bool	      isLive() const;
};

#endif	// !_WIN32
