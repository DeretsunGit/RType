#pragma once

#ifndef	_WIN32

# include	"IOBuff.h"
# include	"ATCPSocketClient.h"

class	UnixTCPSocketClient: public ATCPSocketClient
{
private:
  SocketId	_sock;
  bool		_live;
  IOBuff<>	_buff;

  UnixTCPSocketClient();
  UnixTCPSocketClient(const UnixTCPSocketClient&);
  UnixTCPSocketClient&	operator=(const UnixTCPSocketClient&);

public:
  UnixTCPSocketClient(const char* hostname, unsigned short port);
  UnixTCPSocketClient(SocketId id);
  ~UnixTCPSocketClient();

  void		send(char* buff, unsigned int size);
  unsigned int	recv(char* buff, unsigned int size);
  SocketId	getId() const;
  bool		wantToWrite() const;
  void		readFromSock();
  void		writeToSock();
  bool		isLive() const;
};

#endif	// !_WIN32
