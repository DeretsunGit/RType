#include "Client.h"


Client::Client(ITCPSocketClient* newSocket)
{
	this->_tcpSocket = newSocket;
}


Client::~Client(void)
{
}
