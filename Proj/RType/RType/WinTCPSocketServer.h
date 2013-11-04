#pragma once

#ifdef _WIN32

# include <queue>
# include <mutex>
# include "ATCPSock.h"
# include "WinTCPSocketClient.h"

# define LOCALHOST	1
# define LOCAL		2

class WinTCPSocketServer : public ATCPSock
{
private:
	bool			_live;
	SocketId		_sock;
	unsigned short	_port;
	char*			_ip;
	std::queue<WinTCPSocketClient*> _winTCPSocketClient;
	std::mutex						_lock;
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
	bool		isLive() const;
};

#endif // _WIN32