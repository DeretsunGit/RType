#pragma once

#ifdef _WIN32

# include <queue>
# include "Mutex.h"
# include "Socket.h"
# include "WinTCPSocketClient.h"

# define LOCALHOST	1
# define LOCAL		2

class WinTCPSocketServer : public ISocket
{
private:
	bool			_live;
	SocketId		_sock;
	unsigned short	_port;
	char*			_ip;
	std::queue<WinTCPSocketClient*> _winTCPSocketClient;
	Mutex						_lock;
public:
	WinTCPSocketServer(unsigned short, bool = false);
	virtual ~WinTCPSocketServer();
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