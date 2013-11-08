#pragma once

#include <list>
#include <iterator>
#include <ostream>
#include "rtype_common.h"
#include "TCPSocketServer.h"
#include "Thread.h"
#include "Room.h"
#include "Client.h"
#include "ServerCommunication.hpp"

class RTypeServer
{
	bool		_isrunning;
	int			_port;
	char		_maxRoom;
	Client *	_currentClient;

	std::list<Room *>		_roomPool;
	std::list<Client *>		_clientList;
	TCPSocketServer			_TCPsocket;
	ServerCommunication<RTypeServer>	_RTypeServerCom;
	//Packet&				pack;
	// std::ofstream _blFile;

public:
	RTypeServer(int, char, std::string);
	~RTypeServer();

	bool	start();
	bool	serverLoop();
	
	//CallBack gestion
	void	sayHello(void *);
	void	setRoom(void *);//(Client *, char*);
	void	selectRoom(void *);//(Client *, int);
	void	leaveRoom(void *);//(Client *);
	void	callBackError(char, IReadableSocket&);

	//Send Gestion
	void	sendRoomList();
	void	sendError(char, const char *);

	//Room gestion
	void	setMaxRoom(char);
	void	genRoomPool(int);
	void	delRoomPool(int);
	int		getMaxRoom();

	template<class ret, class clist>
	ret		createValidId(ret, std::list<clist>);
	bool	loadDynEnnemy(std::string);
	void	CheckClientAnswer();
};