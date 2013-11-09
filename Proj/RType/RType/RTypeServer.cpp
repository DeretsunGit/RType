#include "RTypeServer.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<RTypeServer>;

RTypeServer::RTypeServer(int port, char maxRoom, std::string blPath)
  : _port(port), _TCPsocket(port)
{
	this->_isrunning = true;
	this->setMaxRoom(maxRoom);
	// convertir le blPath en ofstream
	this->_RTypeServerCom.setCallback(0x01, &RTypeServer::sayHello);
	this->_RTypeServerCom.setCallback(0x02, &RTypeServer::setRoom);
	this->_RTypeServerCom.setCallback(0x03, &RTypeServer::selectRoom);
	this->_RTypeServerCom.setCallback(0x04, &RTypeServer::leaveRoom);
	this->_RTypeServerCom.setDefaultCallback(&RTypeServer::callBackError);
	this->_RTypeServerCom.setHandler(this);
}

RTypeServer::~RTypeServer()
{
	// quitter tous les clients proprement
}

void		RTypeServer::callBackError(char opcode, IReadableSocket& clientSock)
{
	std::cout << "Impossible Action :" << std::hex << opcode;
	std::cout << "can't be done while _isWaiting = true" << std::endl;
	this->sendError(60, "You can't perform this action by now.");
}

bool		RTypeServer::start()
{
	this->serverLoop();
	return (true);
}

bool		RTypeServer::serverLoop()
{
	int		id = 0;
	ITCPSocketClient*	newClient;
	// création du prompt - commande de load des lib dynamiques

	while (this->_isrunning)
	{
		if ((newClient = this->_TCPsocket.accept()) != NULL)
		{
			id = createValidId<int, Client *>(id, this->_clientList);
			if (this->_clientList.size() < MAXCLIENT)
				this->_clientList.push_back(new Client(newClient, id));
			else
				this->sendError(66, "No more client allowed.");
		}
		this->CheckClientAnswer();
	}
	return (1);
}

void		RTypeServer::CheckClientAnswer()
{
	std::list<Client*>::iterator	it_client;

	for (it_client = (this->_clientList).begin(); (it_client != (this->_clientList).end()); it_client++)
		{
			if ((*it_client)->getDelete() == true)
			{
				this->_clientList.erase(it_client);
			}
			else if ((*it_client)->getWaiting() == true)
			{
				this->_currentClient = (*it_client);
				this->_RTypeServerCom.interpretCommand(*(this->_currentClient->getTCPSock()));
			}
		}
}

void		RTypeServer::sayHello(void *data)
{
	if ((reinterpret_cast<s_say_hello *>(data))->magic != "KOUKOU")
	{
		this->_currentClient->setDelete(true);
	}
	else
	{
		this->_currentClient->setName((reinterpret_cast<s_say_hello *>(data))->nickname);
		this->_currentClient->setResolution((reinterpret_cast<s_say_hello *>(data))->resolution[1],
											(reinterpret_cast<s_say_hello *>(data))->resolution[2]);
	}
}

void		RTypeServer::setRoom(void *data)
{
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->getNbPlayer() == 0)
			{
				(*it_room)->setName((reinterpret_cast<s_set_room *>(data))->roomName);
				(*it_room)->addClient(this->_currentClient);
				this->_currentClient->setWaiting(false);
				return;
			}
		}
	return;
}

void		RTypeServer::selectRoom(void *data)
{
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->getId() == (reinterpret_cast<s_select_room *>(data))->roomId)
			{
				(*it_room)->addClient(this->_currentClient);
				this->_currentClient->setWaiting(false);
				return;
			}
		}
	return;
}

void		RTypeServer::leaveRoom(void *data)
{
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->removeClient(this->_currentClient->getId()))
			{
				this->_currentClient->setWaiting(true);
				return;
			}
		}
	return;
}

void		RTypeServer::sendRoomList()
{
	this->_RTypeServerCom.TCProomList(this->_pack, (this->_roomPool));
}

void		RTypeServer::sendError(char errorCode, const char *message)
{
	this->_RTypeServerCom.TCPsendError(this->_pack, errorCode, message);
}

void		RTypeServer::setMaxRoom(char newMaxRoom)
{
	(newMaxRoom <= 100) ?
		this->_maxRoom = newMaxRoom : this->_maxRoom = MAXROOM;
	this->_maxRoom = newMaxRoom;
	(this->_roomPool.size() <= this->_maxRoom) ?
		this->genRoomPool(this->_maxRoom - static_cast<char>(this->_roomPool.size())) :
	this->delRoomPool(static_cast<char>(this->_roomPool.size()) - this->_maxRoom);
}

void		RTypeServer::genRoomPool(int nbroom)
{
	int		i = 0;

	while (i < nbroom)
	{
		this->_roomPool.push_back(new Room(this->createValidId<char, Room *>(0, this->_roomPool)));
		i ++;
	}
}

void		RTypeServer::delRoomPool(int nbRoom)
{
	int		i = 0;
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end() && i < nbRoom); it_room++)
		{
			if ((*it_room)->getNbPlayer() == 0)
			{
				this->_roomPool.erase(it_room);
				it_room--;
				i++;
			}
		}
}

template<class ret, class clist>
ret			RTypeServer::createValidId(ret id, std::list<clist> checkList)
{
  typename std::list<clist>::iterator	it;

	for (it = (checkList).begin(); (it != (checkList).end()); it++)
		{
			if (id == (*it)->getId())
			{
				id ++;
				it = (checkList).begin();
			}
		}
	return (id);
}

bool		RTypeServer::loadDynEnnemy(std::string filename)
{
	return (1);
}
