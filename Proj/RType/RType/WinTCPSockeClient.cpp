#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketClient.h"
# include "SocketPool.h"

WinTCPSocketClient::WinTCPSocketClient()
{
	SocketPool::getInstance().watchSocket(this);
}

WinTCPSocketClient::~WinTCPSocketClient()
{
	if (closesocket(this->_sock) == SOCKET_ERROR)
	{
		std::cerr << "closesocket() function failed with error: " << WSAGetLastError() << std::endl;
		WSACleanup();
		throw new std::exception();
	}

	WSACleanup();
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

void  WinTCPSocketClient::setId(SocketId sock)
{
	this->_sock = sock;
}

bool		WinTCPSocketClient::wantToWrite() const
{
	std::cout << "size:" << this->_buff._output.readableSize() << std::endl;
	return (this->_buff._output.readableSize() > 0 ? true : false); //TODO: ?
}

void	    WinTCPSocketClient::readFromSock()
{
	std::cout << "readClient" << std::endl;
}

void	    WinTCPSocketClient::writeToSock()
{
	std::cout << "writeClient" << std::endl;
}

#endif // _WIN32
