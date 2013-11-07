#include "RTypeServer.h"

RTypeServer::RTypeServer(int port, char maxRoom, std::string blPath)
  : _port(port), _TCPsocket(port)
{
	this->_isrunning = true;
	this->setMaxRoom(maxRoom);
	// convertir le blPath en ofstream
}

bool		RTypeServer::start()
{
	int id = 0;
	ITCPSocketClient*	newClient;
	// création du prompt
	// load des librairies dynamiques

	// gestion socket
	while (this->_isrunning)
	{
		if ((newClient = this->_TCPsocket.accept()) != NULL)
		{
			// on ne push que si le client dit koukou
			id = createValidId<int, Client *>(id, this->_clientList);
			if (this->_clientList.size() < MAXCLIENT)
				this->_clientList.push_back(new Client(newClient, id));
			else
			{
			// send error "U MAD ZER IS ALRIDI TO MUCH PLAIERS"
			}
		}
		// boucle pour verifier qu'il n'y a pas de client qui font des operations sur room, set resolution, etc...
	}
	return (1);
}

template<class ret, class clist>
ret			RTypeServer::createValidId(ret id, std::list<clist> checkList)
{
	//id = 0; // id random serait mieux
	std::list<clist>::iterator	it;
	
	for (it = (checkList).begin(); (it != (checkList).end()); it++)
		{
			if (id == (*it)->getId())
			{
				id ++;
				it = (checkList).begin();
			}
		}
	return id;
}

bool		RTypeServer::loadDynEnnemy(std::string filename)
{
	return (1);
}

bool		RTypeServer::setRoom(Client *roomMaster, char *name)
{
	// recup fichiers, etc...
	std::list<Room*>::iterator	it_room;
	
	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->getNbPlayer() == 0)
			{
				(*it_room)->setName(name); // send d'erreur si false
				(*it_room)->addClient(roomMaster);
				roomMaster->setWaiting(false);
				return (true);
			}
		}
	return (false);
}

bool		RTypeServer::selectRoom(Client *roomJoiner, int id)
{
	std::list<Room*>::iterator	it_room;
	
	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->getId() == id)
			{
				(*it_room)->addClient(roomJoiner);
				roomJoiner->setWaiting(false);
				return (true);
			}
		}
	return (false);
}

bool		RTypeServer::leaveRoom(Client * roomLeaver)
{
	std::list<Room*>::iterator	it_room;
	
	for (it_room = (this->_roomPool).begin(); (it_room != (this->_roomPool).end()); it_room++)
		{
			if ((*it_room)->removeClient(roomLeaver->getId()))
			{
				roomLeaver->setWaiting(true);
				return (true);
			}
		}
	return (false);
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

RTypeServer::~RTypeServer()
{
	// quitter tous les clients proprement
}
