#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinUDPSocketServer.h"
# include "SocketPool.h"

WinUDPSocketServer::WinUDPSocketServer(unsigned short port)
{
	if (!this->createSocket())
		throw std::exception();
	if (!this->configSocket(port))
		throw std::exception();
	this->_live = true;
	SocketPool::getInstance().watchSocket(this);
}

WinUDPSocketServer::~WinUDPSocketServer()
{
	//while (!this->_winUDPSocketClient.empty())
	//{
	//	delete this->_winUDPSocketClient.front();
	//	this->_winUDPSocketClient.pop();
	//}
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		throw std::exception();
	}
}

bool		WinUDPSocketServer::createSocket()
{
	if ((this->_sock = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "WSASocket() function failed with error: " << WSAGetLastError() << std::endl;
		return (false);
	}
	return (true);
}

bool		WinUDPSocketServer::configSocket(unsigned short port)
{
	sockaddr_in	service;
	hostent*	thisHost;
	char		hostName[255];
	char*			ip;

	service.sin_family = AF_INET;
	WSAHtons(this->_sock, port, &service.sin_port);
	gethostname(hostName, 255);
	std::cout << "hostName:" << hostName << std::endl;
	thisHost = gethostbyname(hostName);
	ip = inet_ntoa(*(struct in_addr *)*thisHost->h_addr_list);
	std::cout << "ip: " << ip << " port: " << port << std::endl;
	if ((service.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
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
	std::cout << "Ready..." << std::endl;

	return (true);
}

WinUDPSocketServer::SocketId  WinUDPSocketServer::getId() const
{
	return (this->_sock);
}

bool	WinUDPSocketServer::isLive() const
{
	return (this->_live);
}

bool		WinUDPSocketServer::wantToWrite() const
{
	return (false);
}

void	    WinUDPSocketServer::readFromSock()
{
	//SocketId			sockAccept;
	//struct sockaddr_in	client;
	//int					clientSize = sizeof(client);
	//WinUDPSocketClient	*winUDPSocketClient = NULL;

	//if (!this->_live)
	//	return;
	//this->_lock.lock();
	//std::cout << "accept !!!" << std::endl;
	//if ((sockAccept = WSAAccept(this->_sock, (SOCKADDR*) &client, &clientSize, NULL, NULL)) == INVALID_SOCKET)
	//{
	//	std::cerr << "WSAAccept() function failed with error: " << WSAGetLastError() << std::endl;
	//	closesocket(this->_sock);
	//	delete winUDPSocketClient;
	//	this->_live = false;
	//	this->_lock.unlock();
	//	return;
	//}
	//winUDPSocketClient = new WinUDPSocketClient(sockAccept);
	//this->_winUDPSocketClient.push(winUDPSocketClient);
	//this->_lock.unlock();
}

void	    WinUDPSocketServer::writeToSock()
{

}

#endif // _WIN32
