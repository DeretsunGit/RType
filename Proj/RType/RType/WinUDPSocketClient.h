#pragma once

#ifdef _WIN32

# include "IUDPSocketClient.h"
# include "IOBuff.h"
# include "Mutex.h"

class WinUDPSocketClient : public IUDPSocketClient
{
private:
	SocketId	 _sock;
	bool	  	 _live;
	UDPBuff<>	 _buff;
	Mutex		 _m;
	unsigned short	_port;
	IN_ADDR		_host;

	WinUDPSocketClient();
	WinUDPSocketClient(const WinUDPSocketClient&);
	WinUDPSocketClient& operator=(const WinUDPSocketClient&);

public:
	WinUDPSocketClient(const char* hostname, unsigned short port);
	virtual	      ~WinUDPSocketClient();
	unsigned int  readable() const;
	unsigned int  recv(char* buff, unsigned int size);
	void	      send(const char* buff, unsigned int size);
	SocketId      getId() const;
	bool	      wantToWrite() const;
	void	      readFromSock();
	void	      writeToSock();
	bool	      isLive() const;
};

#endif // _WIN32
