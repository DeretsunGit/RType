#pragma once

#ifndef	_WIN32

# include	"Mutex.h"
# include	"IOBuff.h"
# include	"ITCPSocketClient.h"

class	UnixTCPSocketClient: public ITCPSocketClient
{
private:
  SocketId	_sock;
  bool		_live;
  IOBuff<>	_buff;
  Mutex		_m;

  UnixTCPSocketClient();
  UnixTCPSocketClient(const UnixTCPSocketClient&);
  UnixTCPSocketClient&	operator=(const UnixTCPSocketClient&);

public:
  UnixTCPSocketClient(const char* hostname, unsigned short port);
  UnixTCPSocketClient(SocketId id);
  ~UnixTCPSocketClient();

  void		putback(const char* buff, unsigned int size);
  void		send(const char* buff, unsigned int size);
  void		send(const Packet& p);
  unsigned int	recv(char* buff, unsigned int size);
  unsigned int	readable() const;
  SocketId	getId() const;
  bool		wantToWrite() const;
  void		readFromSock();
  void		writeToSock();
  bool		isLive() const;
};

#endif	// !_WIN32
