#pragma once

#ifdef _WIN32

# include "Mutex.h"
# include "ITCPSocketClient.h"
# include "IOBuff.h"

#define DATA_BUFSIZE	1024

class WinTCPSocketClient : public ITCPSocketClient
{
private:
  SocketId		_sock;
  bool			_live;
  IOBuff<>		_buff;
  Mutex			_lock;
public:
  WinTCPSocketClient(const char *, unsigned short);
  WinTCPSocketClient(SocketId);
  virtual ~WinTCPSocketClient();
  void			send(const char *buff, unsigned int size);
  unsigned int	recv(char *buff, unsigned int size);
  unsigned int	readable() const;
  SocketId	getId() const;
  bool		wantToWrite() const;
  void	    readFromSock();
  void	    writeToSock();
  bool		isLive() const;
};

#endif // _WIN32
