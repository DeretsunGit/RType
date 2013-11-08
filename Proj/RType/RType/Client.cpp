#include "Client.h"


Client::Client(ITCPSocketClient* newSocket, const int id) : _id(id)
{
	this->_tcpSocket = newSocket;
	this->_isWaiting = true;
	this->_resolution._posX = 1600;
	this->_resolution._posY = 900;
	this->_name = new std::string("");
}

Client::~Client(void)
{
}

ITCPSocketClient*	Client::getTCPSock()
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


