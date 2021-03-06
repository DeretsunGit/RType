#include "RTypeServer.h"
#include "ServerCommunication.cpp"
#include "Opcodes.h"
template class ServerCommunication<RTypeServer>;

RTypeServer::RTypeServer(int port, char maxRoom, std::string blPath)
  : _port(port), _TCPsocket(port)
{
	std::cout << "1 on " << DEBUGSTATE << " RTypeServer Initialised." << std::endl;
	this->_isrunning = true;
	// convertir le blPath en ofstream
	this->_RTypeServerCom.setCallback(Opcodes::sayHello, &RTypeServer::sayHello);
	this->_RTypeServerCom.setCallback(Opcodes::setRoom, &RTypeServer::setRoom);
	this->_RTypeServerCom.setCallback(Opcodes::selectRoom, &RTypeServer::selectRoom);
	this->_RTypeServerCom.setCallback(Opcodes::leaveRoom, &RTypeServer::leaveRoom);
	this->_RTypeServerCom.setDefaultCallback(&RTypeServer::callBackError);
	this->_RTypeServerCom.setHandler(this);
	this->setMaxRoom(maxRoom);
	this->loadDynEnnemy("koukou");
	std::cout << "Starting server..." << std::endl;

}

RTypeServer::~RTypeServer()
{
	// quitter tous les clients proprement
}

void		RTypeServer::callBackError(char opcode, IReadableSocket& clientSock)
{
	std::cout << "- can't be done while _isWaiting = true" << std::endl;
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
	Clock	loopTimer;
	float	execTime;

	while (this->_isrunning)
	{

		if ((newClient = this->_TCPsocket.accept()) != NULL)
		{
			id = createValidId<int, Client *>(id, this->_clientList);
			if (this->_clientList.size() < MAXCLIENT)
				{
					this->_clientList.push_back(new Client(newClient, id));
				}
			else
				this->sendError(66, "No more client allowed.");
		}
		this->CheckClientAnswer();
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(SERVLOOPTIME - execTime));
	}
	return (1);
}

void		RTypeServer::CheckClientAnswer()
{
	Client		*temp;
	std::list<Client*>::iterator	it_client;

	for (it_client = (this->_clientList).begin(); (it_client != (this->_clientList).end()); it_client++)
		{
			if ((*it_client)->getDelete() == true)
			{
				temp = *it_client;
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
	s_say_hello *dataStruct = (reinterpret_cast<s_say_hello *>(data));
	std::string		magic(dataStruct->magic);
	

	if (magic.compare("KOUKOU\0") != 0)
	{
		std::cout << "You will be terminated. destroy ! destroy ! destroy !" << std::endl;
		this->_currentClient->setDelete(true);
	}
	else
	{
		this->_currentClient->setName(dataStruct->nickname);
		this->_currentClient->setResolution(dataStruct->resolution[1], dataStruct->resolution[2]);
		this->sendRoomList();
		//this->sendError(40, "lol ya un soucis");
	}
}

void		RTypeServer::setRoom(void *data)
{
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->getNbPlayer() == 0)
			{
				(*it_room)->setName(reinterpret_cast<char*>(data));
				(*it_room)->addClient(this->_currentClient);
				this->_currentClient->setWaiting(false);
				std::cout << "-" << *(this->_currentClient->getName()) <<
					" created Room " << ((*it_room)->getName()) << " of id : " <<
					static_cast<int>((*it_room)->getId()) << std::endl;
				(*it_room)->getThread()->start();
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
			if ((*it_room)->getId() == reinterpret_cast<char *>(data)[0])
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
	this->_currentClient->getTCPSock()->send(this->_pack);
}

void		RTypeServer::sendError(char errorCode, const char *message)
{
	this->_RTypeServerCom.TCPsendError(this->_pack, errorCode, message);
	this->_currentClient->getTCPSock()->send(this->_pack);
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
	std::vector<t_pattern>	pattern;

	this->_isrunning = _temp.getPattern();
	pattern = _temp.getPatternList();
	while (i < nbroom)
	{
		this->_roomPool.push_back(new Room(this->createValidId<char, Room *>(1, this->_roomPool), pattern));
		i ++;
	}
}

void		RTypeServer::delRoomPool(int nbRoom)
{
	Room	*temp;
	int		i = 0;
	std::list<Room*>::iterator	it_room;

	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end() && i < nbRoom); it_room++)
	{
		if ((*it_room)->getNbPlayer() == 0)
		{
			temp = *it_room;
			this->_roomPool.erase(it_room);
			delete temp;
			it_room--;
			i++;
		}
	}
}

template<class ret, class clist>
ret			RTypeServer::createValidId(ret id, std::list<clist> &checkList)
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
