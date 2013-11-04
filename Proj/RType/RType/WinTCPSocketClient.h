#pragma once

#ifdef _WIN32

# include "ATCPSock.h"

class WinTCPSocketClient : public ATCPSock
{
private:
	SocketId		_sock;
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
};

#endif // _WIN32