#include <algorithm>
#include <cstring>
#include "Room.h"


Room::Room()
{
//	this->_id;
	this->_nbReady = 0;
}

Room::~Room(void)
{
}

bool	Room::addClient(Client* newClient)
{
	Player newPlayer;
	
	if (this->addPlayer(&newPlayer) == false)
		return (false);
	newPlayer.setClient(newClient);
}

bool	Room::addPlayer(Player* player)
{
	if (_party.size() < 4)
	{
		_party.push_back(player);
		return (true);
	}
	return (false);
}

bool	Room::startGame()
{
	Game newGame;
	// on instancie une game
	return (true);
}

bool	Room::removePlayer(int id)
{
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _party.size())
	{
		if (_party[i]->getId() == id)
		{
			_party.erase(ite);
			return (true);
		}
		++i;
		++ite;
	}
	return (false);
}

void	Room::roomLoop()
{
	/*
	while (this->_nbReady != _party.size())
	{
		// add les joueurs voulant join
		//	delete les joueurs qui partent / deco
	}*/
	startGame();
}

char	Room::getId() const
{
	return (this->_id);
}

char	Room::getNbPlayer() const
{
	return (_party.size());
}

Packet*	Room::TCPsendRoomList(const std::list<Room>& rooms) const
{
	if (!rooms.size())
		return (NULL);

	s_tcp_header block;
	Packet* packet = new Packet();
	std::list<Room>::const_iterator ite = rooms.begin();
	int i = 3;

	block.opcode = 0x01;
	block.datasize = ((short)rooms.size() * 2);
	char* buff = new char[TCPHEADSIZE + block.datasize];

	memcpy(buff, &block, TCPHEADSIZE);

	while (i < rooms.size() + TCPHEADSIZE)
	{
		buff[i] = ite->getId();
		buff[i+1] = ite->getNbPlayer();
		i += 2;
	}
	
	if (!packet->set(buff, TCPHEADSIZE + block.datasize))
	{
		delete buff;
		delete packet;
		return NULL;
	}
	
	return (packet);
}