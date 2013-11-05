#pragma once

#ifdef _WIN32

# include "IUDPSocketClient.h"
# include "IOBuff.h"

#define DATA_BUFSIZE	1024

class WinUDPSocketClient : public IUDPSocketClient
{
private:
	SocketId		_sock;
	bool			_live;
	IOBuff<>		_buff;
public:
	WinUDPSocketClient(const char *, unsigned short);
	WinUDPSocketClient(SocketId);
	virtual ~WinUDPSocketClient();
	void			send(char *buff, unsigned int size);
	unsigned int	recv(char *buff, unsigned int size);
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		isLive() const;
};

#endif // _WIN32
