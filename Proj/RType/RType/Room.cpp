#include <algorithm>
#include <cstring>
#include "Game.h"
#include "Room.h"
#include "rtype_common.h"

Room::Room(char id) : _id(id), _th(new Thread(*this, &Room::roomLoop))
{
	this->_isRandom = true;
	this->_difficulty = 1;
	this->_nbReady = 0;
	/*this->_RoomCom.setCallback(0x05, &Room::changeDifficulty);
	this->_RoomCom.setCallback(0x06, &Room::setMap);
	this->_RoomCom.setCallback(0x07, &Room::getFileTrunk);
	this->_RoomCom.setCallback(0x08, &Room::setReady);
	this->_RoomCom.setCallback(0x09, &Room::downloadRessource);
	this->_RoomCom.setCallback(0x0A, &Room::ready);
	this->_RoomCom.setCallback(0x0B, &Room::letsPlay);
	this->_RoomCom.setCallback(0x0C, &Room::saveMap);
	this->_RoomCom.setDefaultCallback(&Room::callBackError);
	this->_RoomCom.setHandler(this);*/
	this->_th->start();
}

Room::~Room(void)
{
}

void	callBackError(char, IReadableSocket&)
{

}

void	Room::setMap(void *newMapName)//(char *newName)
{
	this->_map = new std::string(reinterpret_cast<char *>(newMapName));
}

void	Room::changeDifficulty(void *newDifficulty)//(char newDifficulty)
{
	this->_difficulty = *(reinterpret_cast<char *>(newDifficulty));
}

void	Room::getFileTrunk(void *data)
{

}
void	Room::setReady(void *data)
{

}
void	Room::downloadRessource(void *data)
{

}
void	Room::ready(void *data)
{

}
void	Room::letsPlay(void *data)
{

}
void	Room::saveMap(void *data)
{

}
#include <iostream>
bool	Room::removeClient(int id)
{
	this->_m.lock();
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _party.size())
	{
		if (_party[i]->getClient()->getId() == id)
		{
			_party.erase(ite);
			return (true);
		}
		++i;
		++ite;
	}
	this->_m.unlock();
	return (false);
}

bool	Room::removePlayer(int id)
{
	this->_m.lock();
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
	this->_m.unlock();
	return (false);
}

bool	Room::addClient(Client* newClient)
{
  this->_m.lock();
  if (_party.size() < 2)
  {
    std::cout << "PUSH BACK" <<  std::endl;
    _party.push_back(new Player(newClient));
    this->_m.unlock();
    return (true);
  }
  this->_m.unlock();
  return (false);
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
  bool	ready(false);

  while (!ready)
  {
    Sleep(10);
    this->_m.lock();
    ready = this->_party.size() >= 2;
    this->_m.unlock();
  }
	Game newGame(this->_party);
	// on instancie une game
	return (true);
}

void	Room::roomLoop()
{
	/*
	while (this->_nbReady != _party.size())
	{
		// add les joueurs voulant join
		//	delete les joueurs qui partent / deco
	}*/
  while (this->_party.size() < 2)
    Sleep(10);
  startGame();
}

char	Room::getId() const
{
	return (this->_id);
}

char	Room::getNbPlayer() const
{
	return (static_cast<char>(_party.size()));
}

std::vector<Player*> Room::getPlayers() const
{
	return (this->_party);
}

std::string	Room::getName() const
{
	return(*this->_name);
}

char	Room::getDifficulty() const
{
	return (this->_difficulty);
}

bool	Room::setName(char *newName)
{
	std::string temp(newName);
	*this->_name = temp.size() <= 32 ? temp : *this->_name;
	return (temp.size() <= 32 ? true : false);
}

/*
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
}*/
