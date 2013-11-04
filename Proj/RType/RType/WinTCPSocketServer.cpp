#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketServer.h"

WinTCPSocketServer::WinTCPSocketServer(unsigned short port, bool localHost)
: _port(port)
{
	if (!this->createSocket())
		throw new std::exception();
	if (!this->configSocket(localHost))
		throw new std::exception();
}

WinTCPSocketServer::~WinTCPSocketServer()
{
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		WSACleanup();
		throw new std::exception();
	}

	WSACleanup();
}

bool		WinTCPSocketServer::createSocket()
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cerr << "WSAStartup() failed with error: " << WSAGetLastError() << std::endl;
		return (false);
	}

	if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		WSACleanup();
		return (false);
	}
	return (true);
}

bool		WinTCPSocketServer::configSocket(bool localHost)
{
	sockaddr_in	service;
	hostent*	thisHost;
	char		hostName[255];

	service.sin_family = AF_INET;
	WSAHtons(this->_sock, this->_port, &service.sin_port);
	localHost ? strcpy_s(hostName, "localhost") : gethostname(hostName, 255);
	thisHost = gethostbyname(hostName);
	this->_ip = inet_ntoa(*(struct in_addr *)*thisHost->h_addr_list);
	std::cout << "ip: " << this->_ip << " port: " << this->_port << std::endl;
	service.sin_addr.s_addr = inet_addr(this->_ip);

	if (bind(this->_sock, (SOCKADDR*) &service, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		std::cerr << "bind() failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		WSACleanup();
		return (false);
	}

	if (listen(this->_sock, 1) == SOCKET_ERROR)
	{
		std::cerr << "listen() failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		WSACleanup();
		return (false);
	}
	std::cout << "Listening..." << std::endl;

	return (true);
}

WinTCPSocketClient*		WinTCPSocketServer::accept()
{
	SocketId			sockAccept;
	struct sockaddr_in	client;
	int					clientSize = sizeof(client);
	WinTCPSocketClient	*winTCPSocketClient = new WinTCPSocketClient;

	if ((sockAccept = WSAAccept(this->_sock, (SOCKADDR*) &client, &clientSize, NULL, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSAAccept() function failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		WSACleanup();
		return (false);
	}
	winTCPSocketClient->setId(sockAccept);
	return (winTCPSocketClient);
}

void WinTCPSocketServer::send(char *buff, unsigned int size)
{
	this->_buff._output.writeSome(buff, size);
}

unsigned int WinTCPSocketServer::recv(char *buff, unsigned int size)
{
	return (this->_buff._input.readSome(buff, size));
}

WinTCPSocketServer::SocketId  WinTCPSocketServer::getId() const
{
	return (this->_sock);
}

bool		WinTCPSocketServer::wantToWrite() const
{
	return (this->_buff._input.readableSize() > 0 ? true : false); //TODO: ?
}

void	    WinTCPSocketServer::readFromSock()
{
	int		rc, err;
	DWORD	recvBytes, flags;
	WSABUF	dataBuf;
	char	buffer[1024] = { 0 };

	dataBuf.len = 1024;
	dataBuf.buf = buffer;
	memset(dataBuf.buf, 0, 1024);
	flags = 0;
	rc = WSARecv(this->_sock, &dataBuf, 1, &recvBytes, &flags, NULL, NULL);
	if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	{
		std::cerr << "WSARecv() failed with error: " << err << std::endl;
		return;
	}
	if (recvBytes == 0)
	{
		this->_accept++;
		std::cout << "this->_accept: " << this->_accept << std::endl;
	}
	else
		std::cout << dataBuf.buf << std::endl;
}

void	    WinTCPSocketServer::writeToSock()
{
	int		rc, err;
	DWORD	sendBytes;

	//rc = WSASend(sockAccept, &DataBuf, 1, &sendBytes, 0, NULL, NULL);
	//if ((rc == SOCKET_ERROR) && (WSA_IO_PENDING != (err = WSAGetLastError())))
	//{
	//	std::cerr << "WSASend() failed with error: " << err << std::endl;
	//}
}

#endif // _WIN32
