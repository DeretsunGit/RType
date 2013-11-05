#pragma once

#include <list>
#include <ostream>
#include "TCPSocketServer.h"
#include "Thread.h"
#include "Room.h"

class RTypeServer
{
	int	_port;
	int	_maxRoom;

	std::list<Client *>		_waitingList;
	TCPSocketServer*		_TCPsocket;
	// std::ofstream _blFile;

public:
	RTypeServer(int, int, std::string);
	~RTypeServer();

	bool	start();
	bool	loadDynEnnemy(std::string);
	void	createRoom();
};