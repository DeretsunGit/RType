#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketClient.h"
# include "SocketPool.h"

WinTCPSocketClient::WinTCPSocketClient(SocketId sock)
	: _sock(sock), _live(true)
{
	SocketPool::getInstance().watchSocket(this);
}

WinTCPSocketClient::WinTCPSocketClient(const char *hostName, unsigned short port)
{
	sockaddr_in clientService;

	if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}

	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr(hostName);
	WSAHtons(this->_sock, port, &clientService.sin_port);;

	if (WSAConnect(this->_sock, (SOCKADDR *) & clientService, sizeof (clientService), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
	{
		std::cerr << "connect() function failed with error: " << WSAGetLastError() << std::endl;
		if (closesocket(this->_sock) == SOCKET_ERROR)
			std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
	this->_live = true;
	SocketPool::getInstance().watchSocket(this);
}

WinTCPSocketClient::~WinTCPSocketClient()
{
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
}

void WinTCPSocketClient::send(char *buff, unsigned int size)
{
	this->_buff._output.writeSome(buff, size);
}

unsigned int WinTCPSocketClient::recv(char *buff, unsigned int size)
{
	return (this->_buff._input.readSome(buff, size));
}

WinTCPSocketClient::SocketId  WinTCPSocketClient::getId() const
{
	return (this->_sock);
}

bool	WinTCPSocketClient::isLive() const
{
	return (this->_live);
}

bool		WinTCPSocketClient::wantToWrite() const
{
	//std::cout << "size:" << this->_buff._output.readableSize() << std::endl;
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
		return;
	dataBuf.len = DATA_BUFSIZE;
	dataBuf.buf = buffer;
	flags = 0;
	rc = WSARecv(this->_sock, &dataBuf, 1, &recvBytes, &flags, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		std::cerr << "WSARecv() failed with error: " << err << std::endl;
		this->_live = false;
		return ;
	}
	std::cout << "read: " << dataBuf.buf << std::endl;
	this->_buff._input.writeSome(dataBuf.buf, dataBuf.len);
}

void	    WinTCPSocketClient::writeToSock()
{
	int		rc, err;
	DWORD	sendBytes;
	WSABUF	dataBuf;
	char	buffer[DATA_BUFSIZE] = { 0 };

	if (!this->_live)
		return ;
	this->_buff._output.readSome(buffer, DATA_BUFSIZE);
	dataBuf.buf = buffer;
	dataBuf.len = sizeof(dataBuf.buf);
	rc = WSASend(this->_sock, &dataBuf, 1, &sendBytes, 0, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		std::cerr << "WSASend() failed with error: " << err << std::endl;
		this->_live = false;
		return;
	}
	std::cout << "write: " << dataBuf.buf << std::endl;
}

#endif // _WIN32