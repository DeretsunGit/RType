#include "Client.h"


Client::Client(ITCPSocketClient* newSocket, const int id) : _id(id)
{
	this->_toDelete = false;
	this->_tcpSocket = newSocket;
	this->_isWaiting = true;
	this->_resolution._posX = 1600;
	this->_resolution._posY = 900;
	this->_name = new std::string("");
}

Client::~Client(void)
{
}

void		Client::setDelete(bool newState)
{
	this->_toDelete = newState;
}

void		Client::setWaiting(bool newState)
{
	this->_isWaiting = newState;
}

void		Client::setResolution(short int x, short int y)
{
	this->_resolution._posX = x;
	this->_resolution._posY	= y;
}

void		Client::setName(char *name)
{
	this->_name->replace(0, std::string::npos, name);
}

std::string		*Client::getName() const
{
	return (this->_name);
}

bool		Client::getDelete() const
{
	return (this->_toDelete);
}

t_coord		Client::getResolution() const
{
	return (this->_resolution);
}

ITCPSocketClient*	Client::getTCPSock()
{
	return (this->_tcpSocket);
}

int			Client::getId() const
{
	return (this->_id);
}

bool		Client::getWaiting() const
{
	return (this->_isWaiting);
}