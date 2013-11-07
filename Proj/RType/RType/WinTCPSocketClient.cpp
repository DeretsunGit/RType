#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>
# include "WinTCPSocketClient.h"
# include "SocketPool.h"

WinTCPSocketClient::WinTCPSocketClient(SocketId sock)
	: _sock(sock), _live(true)
{
}

WinTCPSocketClient::WinTCPSocketClient(const char *hostName, unsigned short port)
{
	sockaddr_in	clientService;
	struct hostent	*ent;

	if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
	if (!(ent = gethostbyname(hostName)))
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
	clientService.sin_family = AF_INET;
	clientService.sin_addr = *reinterpret_cast<struct in_addr*>(ent->h_addr);
//	if ((clientService.sin_addr.s_addr = inet_addr(hostName)) == INADDR_NONE)
//	{
//		std::cerr << "The target ip address entered must be a legal IPv4 address" << std::endl;
//		throw std::exception();
//	}
	WSAHtons(this->_sock, port, &clientService.sin_port);

	if (WSAConnect(this->_sock, (SOCKADDR *) & clientService, sizeof (clientService), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
	{
		std::cerr << "connect() function failed with error: " << WSAGetLastError() << std::endl;
		if (closesocket(this->_sock) == SOCKET_ERROR)
			std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
	this->_live = true;
}

WinTCPSocketClient::~WinTCPSocketClient()
{
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
	SocketPool::getInstance().releaseSocket(this);
}

void  WinTCPSocketClient::send(const Packet& p)
{
  this->send(p.getBuffer(), p.getSize());
}

void WinTCPSocketClient::send(const char *buff, unsigned int size)
{
	this->_lock.lock();
	this->_buff._output.writeSome(buff, size);
	this->_lock.unlock();
}

unsigned int WinTCPSocketClient::recv(char *buff, unsigned int size)
{
	unsigned int rc = 0;

	this->_lock.lock();
	rc = this->_buff._input.readSome(buff, size);
	this->_lock.unlock();
	return (rc);
}

WinTCPSocketClient::SocketId  WinTCPSocketClient::getId() const
{
	return (this->_sock);
}

unsigned int	WinTCPSocketClient::readable() const
{
  return (this->_buff._input.readableSize());
}

bool	WinTCPSocketClient::isLive() const
{
	return (this->_live);
}

bool		WinTCPSocketClient::wantToWrite() const
{
	if (!this->_live)
		return (false);
	return (this->_buff._output.readableSize() > 0 ? true : false);
}

void	    WinTCPSocketClient::readFromSock()
{
	int		rc, err;
	DWORD	recvBytes, flags;
	WSABUF	dataBuf;
	char	buffer[DATA_BUFSIZE] = { 0 };

	if (!this->_live)
		return ;
	dataBuf.len = DATA_BUFSIZE;
	dataBuf.buf = buffer;
	flags = 0;
	rc = WSARecv(this->_sock, &dataBuf, 1, &recvBytes, &flags, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		this->_live = false;
		return ;
	}
	if (recvBytes == 0)
	{
		this->_live = false;
		return ;
	}
	this->_lock.lock();
	this->_buff._input.writeSome(dataBuf.buf, recvBytes);
	this->_lock.unlock();
}

void	    WinTCPSocketClient::writeToSock()
{
	int		rc, err;
	DWORD	sendBytes;
	WSABUF	dataBuf;
	char	buffer[DATA_BUFSIZE] = { 0 };

	if (!this->_live)
		return ;
	this->_lock.lock();
	dataBuf.len = this->_buff._output.readSome(buffer, DATA_BUFSIZE);
	this->_lock.unlock();
  	dataBuf.buf = buffer;
	rc = WSASend(this->_sock, &dataBuf, 1, &sendBytes, 0, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		this->_live = false;
		return ;
	}
}

#endif // _WIN32
