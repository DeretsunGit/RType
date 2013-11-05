#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketServer.h"
# include "SocketPool.h"

WinTCPSocketServer::WinTCPSocketServer(unsigned short port)
{
	if (!this->createSocket())
		throw std::exception();
	if (!this->configSocket(port))
		throw std::exception();
	this->_live = true;
}

WinTCPSocketServer::~WinTCPSocketServer()
{
	while (!this->_winTCPSocketClient.empty())
	{
		delete this->_winTCPSocketClient.front();
		this->_winTCPSocketClient.pop();
	}
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
}

bool		WinTCPSocketServer::createSocket()
{
	if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		return (false);
	}
	return (true);
}

bool		WinTCPSocketServer::configSocket(unsigned short port)
{
	sockaddr_in	service;
	hostent*	thisHost;
	char		hostName[255];
	char*			ip;

	service.sin_family = AF_INET;
	WSAHtons(this->_sock, port, &service.sin_port);
	gethostname(hostName, 255);
	thisHost = gethostbyname(hostName);
	ip = inet_ntoa(*(struct in_addr *)*thisHost->h_addr_list);
	if ((service.sin_addr.s_addr = INADDR_ANY) == INADDR_NONE)
	{
		std::cerr << "The target ip address entered must be a legal IPv4 address" << std::endl;
		return (false);
	}

	if (bind(this->_sock, (SOCKADDR*) &service, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		std::cerr << "bind() failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		return (false);
	}

	if (listen(this->_sock, 1) == SOCKET_ERROR)
	{
		std::cerr << "listen() failed with error: " << WSAGetLastError() << std::endl;
		closesocket(this->_sock);
		return (false);
	}

	return (true);
}

WinTCPSocketClient*		WinTCPSocketServer::accept()
{
	WinTCPSocketClient	*winTCPSocketClient = NULL;

	if (!this->_winTCPSocketClient.empty())
	{
		this->_lock.lock();
		winTCPSocketClient = this->_winTCPSocketClient.front();
		this->_winTCPSocketClient.pop();
		this->_lock.unlock();
	}
	if (winTCPSocketClient)
		SocketPool::getInstance().watchSocket(winTCPSocketClient);
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
	if ((sockAccept = WSAAccept(this->_sock, (SOCKADDR*) &client, &clientSize, NULL, NULL)) == INVALID_SOCKET)
	{
		closesocket(this->_sock);
		delete winTCPSocketClient;
		this->_live = false;
		this->_lock.unlock();
		return ;
	}
	winTCPSocketClient = new WinTCPSocketClient(sockAccept);
	this->_lock.lock();
	this->_winTCPSocketClient.push(winTCPSocketClient);
	this->_lock.unlock();
}

void	    WinTCPSocketServer::writeToSock()
{

}

#endif // _WIN32
