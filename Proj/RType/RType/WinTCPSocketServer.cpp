#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketServer.h"
# include "SocketPool.h"

WinTCPSocketServer::WinTCPSocketServer(unsigned short port, bool localHost)
: _port(port)
{
	if (!this->createSocket())
		throw new std::exception();
	if (!this->configSocket(localHost))
		throw new std::exception();
	this->_live = true;
	SocketPool::getInstance().watchSocket(this);
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
	std::cout << "hostName:" << hostName << std::endl;
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
	WinTCPSocketClient	*winTCPSocketClient = NULL;

	this->_lock.lock();
	if (!this->_winTCPSocketClient.empty())
	{
		winTCPSocketClient = this->_winTCPSocketClient.front();
		this->_winTCPSocketClient.pop();
	}
	this->_lock.unlock();
	return (winTCPSocketClient);
}

WinTCPSocketServer::SocketId  WinTCPSocketServer::getId() const
{
	return (this->_sock);
}

bool	WinTCPSocketServer::isLive() const
{
	return (this->_live);
}

bool		WinTCPSocketServer::wantToWrite() const
{
	return (false);
}

void	    WinTCPSocketServer::readFromSock()
{
	SocketId			sockAccept;
	struct sockaddr_in	client;
	int					clientSize = sizeof(client);
	WinTCPSocketClient	*winTCPSocketClient = NULL;

	if (!this->_live)
		return ;
	this->_lock.lock();
	winTCPSocketClient = new WinTCPSocketClient;
	std::cout << "accept !!!" << std::endl;
	if ((sockAccept = WSAAccept(this->_sock, (SOCKADDR*) &client, &clientSize, NULL, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSAAccept() function failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		delete winTCPSocketClient;
		this->_live = false;
		this->_lock.unlock();
		return;
	}
	winTCPSocketClient->setId(sockAccept);
	this->_winTCPSocketClient.push(winTCPSocketClient);
	this->_lock.unlock();
}

void	    WinTCPSocketServer::writeToSock()
{

}

#endif // _WIN32
