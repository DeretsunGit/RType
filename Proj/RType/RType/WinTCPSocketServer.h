#pragma once

#ifdef _WIN32

# include <queue>
# include <mutex>
# include "Socket.h"
# include "WinTCPSocketClient.h"

# define LOCALHOST	1
# define LOCAL		2

class WinTCPSocketServer : public ASocket
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