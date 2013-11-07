#pragma once

#include <list>
#include <iterator>
#include <ostream>
#include "TCPSocketServer.h"
#include "Thread.h"
#include "Room.h"
#include "Client.h"

class RTypeServer
{
	bool _isrunning;
	int	_port;
	char	_maxRoom;
//	int _maxClient;

	std::list<Client *>		_clientList;
	TCPSocketServer			_TCPsocket;
	std::list<Room*>		_roomPool;

	// std::ofstream _blFile;

public:
	RTypeServer(int, char, std::string);
	~RTypeServer();

	bool	start();
	template<class ret, class clist>
	ret		createValidId(ret, std::list<clist>);
	bool	loadDynEnnemy(std::string);

	bool	setRoom(Client *, char*);
	bool	selectRoom(Client *, int);
	bool	leaveRoom(Client *);

	void	setMaxRoom(char);
	void	genRoomPool(int);
	void	delRoomPool(int);


	int		getMaxRoom();
};