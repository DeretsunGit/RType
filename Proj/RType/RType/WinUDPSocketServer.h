#pragma once

#ifdef _WIN32

# include <map>
# include "Mutex.h"
# include "Socket.h"
# include "WinUDPSocketClient.h"

class WinUDPSocketServer : public ISocket
{
private:
	bool			_live;
	SocketId		_sock;
	unsigned short	_port;
	char*			_ip;
	std::map<struct sockaddr_in, IOBuff<>> _host;
	Mutex						_lock;
public:
	WinUDPSocketServer(unsigned short);
	virtual ~WinUDPSocketServer();
	SocketId	getId() const;
	bool		wantToWrite() const;
	void	    readFromSock();
	void	    writeToSock();
	bool		createSocket();
	bool		configSocket(unsigned short);
	bool		isLive() const;
};

#endif // _WIN32