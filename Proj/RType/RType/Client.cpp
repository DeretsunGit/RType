#include "Client.h"


Client::Client(ITCPSocketClient* newSocket, const int id) : _id(id)
{
	this->_toDelete = false;
	this->_isRoomLeaver = false;
	this->_tcpSocket = newSocket;
	this->_isWaiting = true;
	this->_resolution._posX = 1600;
	this->_resolution._posY = 900;
	this->_name = new std::string("");
	this->_inaddr = 0;
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

void		Client::setRoomLeaver(bool isleaver)
{
	this->_isRoomLeaver = isleaver;
}

void		Client::setInaddr(u_long newaddr)
{
	this->_inaddr = newaddr;
}

bool		Client::getRoomLeaver() const
{
	return (this->_isRoomLeaver);
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

ITCPSocketClient*	Client::getTCPSock() const
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

u_long		Client::getInaddr() const
{
	return (this->_inaddr);
}