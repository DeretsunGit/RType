#include "Client.h"


Client::Client(ITCPSocketClient* newSocket, const int id) : _id(id)
{
	this->_tcpSocket = newSocket;
	this->_isWaiting = true;
//	this->_id = id;
}

ITCPSocketClient *Client::getTCPSock()
{
	return (this->_tcpSocket);
}

int			Client::getId()
{
	return (this->_id);
}

bool		Client::getWaiting()
{
	return (this->_isWaiting);
}

void		Client::setWaiting(bool newState)
{
	this->_isWaiting = newState;
}

Client::~Client(void)
{
}
