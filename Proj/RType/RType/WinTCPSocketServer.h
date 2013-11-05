#pragma once

#ifdef _WIN32

# include <queue>
# include "Mutex.h"
# include "Socket.h"
# include "WinTCPSocketClient.h"

class WinTCPSocketServer : public ISocket
{
private:
	bool			_live;
	SocketId		_sock;
	std::queue<WinTCPSocketClient*> _winTCPSocketClient;
	Mutex						_lock;
public:
	WinTCPSocketServer(unsigned short);
	virtual ~WinTCPSocketServer();
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		createSocket();
	bool		configSocket(unsigned short);
	WinTCPSocketClient*		accept();
	bool		isLive() const;
};

#endif // _WIN32