#pragma once

#ifdef _WIN32

# include "IUDPSocket.h"
# include "IOBuff.h"
# include "Mutex.h"

class WinUDPSocketClient : public IUDPSocket
{
private:
	SocketId	 _sock;
	bool	  	 _live;
	BuffMap		 _map;
	Mutex		 _m;
	unsigned short	_port;

	WinUDPSocketClient();
	WinUDPSocketClient(const WinUDPSocketClient&);
	WinUDPSocketClient& operator=(const WinUDPSocketClient&);

public:
	WinUDPSocketClient(unsigned short);
	virtual	      ~WinUDPSocketClient();
	unsigned int  readableFor(const in_addr& from) const;
	unsigned int  readFrom(char* buff, unsigned int size, const in_addr& from);
	unsigned int  recvFrom(char* buff, unsigned int size, in_addr& from);
	void	      sendTo(const char* buff, unsigned int size, const in_addr& to);
	SocketId      getId() const;
	bool	      wantToWrite() const;
	void	      readFromSock();
	void	      writeToSock();
	bool	      isLive() const;
};

#endif // _WIN32
