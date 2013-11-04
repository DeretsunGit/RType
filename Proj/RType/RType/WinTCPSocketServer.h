#pragma once

#ifdef _WIN32

# include "ATCPSock.h"
# include "WinTCPSocketClient.h"

# define LOCALHOST	1
# define LOCAL		2

class WinTCPSocketServer : public ATCPSock
{
private:
	SocketId		_sock;
	unsigned short	_port;
	char*			_ip;
	int				_accept;
public:
	WinTCPSocketServer(unsigned short, bool = false);
	virtual ~WinTCPSocketServer();
	void send(char *buff, unsigned int size);
	unsigned int recv(char *buff, unsigned int size);
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		createSocket();
	bool		configSocket(bool);
	WinTCPSocketClient*		accept();
};

#endif // _WIN32