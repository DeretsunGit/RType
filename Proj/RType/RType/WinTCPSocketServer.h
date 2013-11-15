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
	Mutex			_lock;
	void		createSocket();
	void		configSocket(unsigned short);
public:
	WinTCPSocketServer(unsigned short);
	virtual ~WinTCPSocketServer();
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	WinTCPSocketClient*		accept();
	bool		isLive() const;
};

#endif // _WIN32