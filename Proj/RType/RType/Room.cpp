#include <algorithm>
#include <cstring>
#include "Game.h"
#include "Room.h"
#include "rtype_common.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<Room>;


Room::Room(char id)
	: _id(id), _th(new Thread(*this, &Room::roomLoop))
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

	this->_script->LoadMap(this->_map);
	this->_game->startGame();
  // cree la game avec joueurs (UDP set) et un pointeur sur script
  // 
	return (true);
}

void	Room::roomLoop()
{
	this->_m.lock();
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
	this->_m.unlock();
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
	s_set_map *dataStruct = (reinterpret_cast<s_set_map *>(data));
	
	this->_m.lock();
	this->_script->setRandom(dataStruct->status);
	this->_map->replace(0, std::string::npos, (dataStruct->filename));
	this->_m.unlock();
}

void	Room::changeDifficulty(void *data)
{
//	s_change_difficulty *dataStruct = (reinterpret_cast<s_change_difficulty *>(data));

	this->_m.lock();
//	this->_difficulty = dataStruct->difficulty;
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
	this->_currentClient->getTCPSock()->send(this->_pack);
}

void		Room::startLoading()
{
	this->_udpSock = new UDPSocketServer(0);
	this->_port = this->_udpSock->getPort();
//	this->_RoomCom.sendStartLoading(this->_pack, errorCode, message);
//	this->_currentClient->getTCPSock()->send(this->_pack);
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
	if (this->_party.size() < 4)
	    _party.push_back(new Player(newClient, this->validId()));
	else
		std::cout << "This lobby is full." << std::endl;
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
	return(this->_name);
}

char	Room::getDifficulty() const
{
	return (this->_difficulty);
}

void	Room::setName(const char *newName)
{
	this->_name = newName;
}

const std::string& Room::getMap() const
{
	return (*this->_map);
}

bool	Room::getMapStatus() const
{
	return this->_script->getRandom();
}

Thread	*Room::getThread()
{
	return (this->_th);
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