#pragma once

#ifdef _WIN32

# include "ITCPSocketClient.h"
# include "IOBuff.h"

#define DATA_BUFSIZE	1024

class WinTCPSocketClient : public ITCPSocketClient
{
private:
	SocketId		_sock;
	bool			_live;
	IOBuff<>		_buff;

public:
	WinTCPSocketClient(const char *, unsigned short);
	WinTCPSocketClient(SocketId);
	virtual ~WinTCPSocketClient();
	void			send(char *buff, unsigned int size);
	unsigned int	recv(char *buff, unsigned int size);
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		isLive() const;
};

#endif // _WIN32
