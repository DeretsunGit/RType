#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>
# include <iostream>

# include "WinTCPSocketClient.h"

WinTCPSocketClient::WinTCPSocketClient()
{
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
	return (this->_buff._input.readableSize() > 0 ? true : false); //TODO: ?
}

void	    WinTCPSocketClient::readFromSock()
{

}

void	    WinTCPSocketClient::writeToSock()
{

}

#endif // _WIN32
