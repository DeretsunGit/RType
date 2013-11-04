#pragma once

#ifdef _WIN32

# include "Socket.h"
# include "IOBuff.h"

#define DATA_BUFSIZE	1024

class WinTCPSocketClient : public ASocket
{
private:
	SocketId		_sock;
	bool			_live;
	IOBuff<>		_buff;
public:
	WinTCPSocketClient();
	virtual ~WinTCPSocketClient();
	void			send(char *buff, unsigned int size);
	unsigned int	recv(char *buff, unsigned int size);
	SocketId	getId() const;
	void		setId(SocketId);
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		isLive() const;
};

#endif // _WIN32