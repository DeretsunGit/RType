#include "Client.h"


Client::Client(ITCPSocketClient* newSocket)
{
	this->_tcpSocket = newSocket;
}

ITCPSocketClient *Client::getTCPSock()
{
	return (this->_tcpSocket);
}

Client::~Client(void)
{
}
