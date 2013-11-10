#include <algorithm>
#include <cstring>
#include "Game.h"
#include "Room.h"
#include "rtype_common.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<Room>;


Room::Room(char id) : _id(id), _th(new Thread(*this, &Room::roomLoop))
{
	this->_script = new Script;
	this->_script->setRandom(true);
	this->_difficulty = 1;
	this->_nbReady = 0;

	this->_RoomCom.setCallback(0x04, &Room::leaveRoom);
	this->_RoomCom.setCallback(0x05, &Room::changeDifficulty);
	this->_RoomCom.setCallback(0x06, &Room::setMap);
	this->_RoomCom.setCallback(0x07, &Room::getFileTrunk);
	this->_RoomCom.setCallback(0x08, &Room::setReady);
	this->_RoomCom.setCallback(0x09, &Room::downloadRessource);
	this->_RoomCom.setCallback(0x0A, &Room::ready);
	this->_RoomCom.setCallback(0x0B, &Room::letsPlay);
	this->_RoomCom.setCallback(0x0C, &Room::saveMap);
	this->_RoomCom.setDefaultCallback(&Room::callBackError);
	this->_RoomCom.setHandler(this);
	
	this->_th->start();
}

Room::~Room(void)
{
}

void	Room::callBackError(char opcode, IReadableSocket& client)
{
	// faire un fichier qui resume les opcodes d'erreur
	std::cout << "Impossible Action : callback with opcode " << std::hex << opcode;
	std::cout << " can't be done while _isWaiting = true" << std::endl;
	this->sendError(61, "You can't perform this action by now.");
}

bool	Room::startGame()
{
  bool	ready(false);

  std::cout << "Room (id = " << this->_id << ", nb player = "<< this->_nbReady
			<<") attempt to create a game." << std::endl;

  // cree la game avec joueurs (UDP set) et un pointeur sur Script
  // 

  /*
  while (!ready)
  {
    Sleep(10);
    this->_m.lock();
    ready = this->_party.size() >= 2;
    this->_m.unlock();
  }
	Game newGame(this->_party);
	*/
	// on instancie une game
	return (true);
}

void	Room::roomLoop()
{
		std::vector<Player*>::iterator	ite = this->_party.begin();

	while (this->_party.size() != 0)
	{
		for (ite = (this->_party).begin(); (ite != (this->_party).end()); ite++)
			{
				this->_currentClient = (*ite)->getClient();
				this->_RoomCom.interpretCommand(*(this->_currentClient->getTCPSock()));
				if (this->_nbReady == this->_party.size())
					this->startGame();
			}
	}
}

void	Room::leaveRoom(void *data)
{
	this->_m.lock();
	if (removeClient(this->_currentClient->getId()))
	{
		this->_currentClient->setWaiting(true);
	}
	this->_m.unlock();
}

void	Room::setMap(void *data)
{
	this->_m.lock();
	this->_script->setRandom((reinterpret_cast<s_set_map *>(data))->mapStatus);
	this->_map->replace(0, std::string::npos, (reinterpret_cast<s_set_map *>(data))->filename);
	this->_m.unlock();
}

void	Room::changeDifficulty(void *data)
{
	this->_m.lock();
	this->_difficulty = (reinterpret_cast<s_change_difficulty *>(data))->difficulty;
		this->_m.unlock();
}

void	Room::getFileTrunk(void *data)
{

}

void	Room::setReady(void *data)
{
	this->_m.lock();
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _party.size())
	{
		if (_party[i]->getClient()->getId() == 	this->_currentClient->getId())
		{
			(* ite)->setReady(!(* ite)->getReady());
			return;
		}
		++i;
		++ite;
	}
		this->_m.unlock();
}

void	Room::downloadRessource(void *data)
{

}

void	Room::ready(void *data)
{
	// init UDP ?
}

void	Room::letsPlay(void *data)
{
	// launch game if all clients said it

}

void	Room::saveMap(void *data)
{

}

void		Room::sendError(char errorCode, const char *message)
{
	this->_RoomCom.TCPsendError(this->_pack, errorCode, message);
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
    _party.push_back(new Player(newClient, this->validId()));
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

char	Room::getId() const
{
	return (this->_id);
}

char	Room::getNbPlayer() const
{
	return (static_cast<char>(_party.size()));
}

const std::vector<Player*>& Room::getPlayers() const
{
	return (this->_party);
}

const std::string&	Room::getName() const
{
	return(*this->_name);
}

char	Room::getDifficulty() const
{
	return (this->_difficulty);
}

bool	Room::setName(const char *newName)
{
	std::string temp(newName);
	*this->_name = temp.size() <= 32 ? temp : *this->_name;
	return (temp.size() <= 32 ? true : false);
}

const std::string& Room::getMap() const
{
	return (*this->_map);
}

bool	Room::getMapStatus() const
{
	return this->_script->getRandom();
}

int		Room::validId()
{
	int i = 1;
	std::vector<Player*>::iterator ite;

	while (i < _party.size())
	{
		ite = _party.begin();
		for (ite = (this->_party).begin(); (ite != (this->_party).end()); ite++)
		{
			if ((*ite)->getId() == i)
				i++;
		}
		++ite;
	}
	return (i);
}