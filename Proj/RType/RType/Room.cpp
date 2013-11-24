#include <algorithm>
#include <cstring>
#include "Game.h"
#include "Room.h"
#include "rtype_common.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<Room>;


Room::Room(char id, std::vector<t_pattern>pattern)
	: _id(id), _th(new Thread(*this, &Room::roomLoop))
{
	this->_script = new Script;
	this->_script->setRandom(true);
	this->_script->setPatternList(pattern);
	this->_udpSock = new UDPSocketServer(0);
	this->_difficulty = 1;
	this->_nbReady = 0;

	this->_RoomCom.setCallback(Opcodes::leaveRoom, &Room::leaveRoom);
	this->_RoomCom.setCallback(Opcodes::changeDifficulty, &Room::changeDifficulty);
	this->_RoomCom.setCallback(Opcodes::setMap, &Room::setMap);
	this->_RoomCom.setCallback(Opcodes::fileTrunk, &Room::getFileTrunk);
	this->_RoomCom.setCallback(Opcodes::setReady, &Room::setReady);
	this->_RoomCom.setCallback(Opcodes::downloadRsrc, &Room::downloadRessource);
	this->_RoomCom.setCallback(Opcodes::UDPReady, &Room::UDPReady);
	this->_RoomCom.setCallback(Opcodes::letsPlay, &Room::letsPlay);
	this->_RoomCom.setCallback(Opcodes::saveMap, &Room::saveMap);
	this->_RoomCom.setDefaultCallback(&Room::callBackError);
	this->_RoomCom.setHandler(this);
}

Room::~Room(void)
{
}

void	Room::callBackError(char opcode, IReadableSocket& client)
{
	/*std::cout << "Impossible Action : callback with opcode " << std::hex << opcode;
	std::cout << " can't be done while _isWaiting = true" << std::endl;*/
	this->sendError(61, "You can't perform this action by now.");
}

bool	Room::startGame()
{
	int		i = 0;
	bool	ready(false);
	ready = false;
	std::vector<Player *>::iterator	ite = this->_party.begin();

	std::cout << "Room (id = " << this->_id << ", nb player = "<< this->_nbReady
				<<") attempt to create a game." << std::endl;
	while (i < this->_party.size())
	{
		this->_RoomCom.TCPstartLoading(this->_pack, this->_udpSock->getPort());
		this->_party[i]->getClient()->getTCPSock()->send(this->_pack);
		i ++;
	}
	this->_nbReady = 0;
	while (ready != true)
	{
		for (ite = this->_party.begin(); ite != this->_party.end(); ite++)
		{
			this->_RoomCom.interpretCommand(*this->_udpSock);
		}
		if (this->_nbReady == this->_party.size())
			ready = true;
	}
	if (ready == true)
	{
		this->_script->LoadMap(this->_map);
		std::cout << "Script generation ok" << std::endl;
		this->_game = new Game(this->_party, this->_script, this->_udpSock);
		return (true);
	}
	return (false);
}

void	Room::prepareRoom()
{
std::cout << "Preparing room of id" << this->_id << std::endl;
}

void	Room::roomLoop()
{
	this->_m.lock();
	Clock	loopTimer;
	float	execTime;
	int		i = 0;

	bool finish = false;
	std::vector<Player*>::iterator	ite = this->_party.begin();
	
	std::cout << "Room " << this->_name << "Started to Loop" << std::endl;
	while (this->_party.size() > 0 && finish == false)
	{
		loopTimer.initialise();
		while (i != this->_party.size())
		{
			this->_RoomCom.TCProomState(this->_pack, *this);
			this->_party[i]->getClient()->getTCPSock()->send(this->_pack);
			i++;
		}
		ite = (this->_party).begin();
		while ( (ite != (this->_party).end()))
		{
			this->_currentClient = (*ite)->getClient();
			this->_RoomCom.interpretCommand(*(this->_currentClient->getTCPSock()));
			if ((this->_currentClient->getRoomLeaver()) == true)
				ite = this->_party.erase(ite);
			else if (this->_currentClient->getTCPSock()->isLive() == false)
			{
				(*ite)->getClient()->setDelete(true);
				ite = this->_party.erase(ite);
			}
			else
				ite++;
		}
		if (this->_nbReady == this->_party.size() && this->_party.size() > 0)
		{
			this->startGame();
			std::cout << "----------------------GAME ENDED-----------------------"<< std::endl;
			finish = true;
		}
		else
		{
			execTime = loopTimer.getTimeBySec();
			Sleep((unsigned long)(ROOMLOOPTIME - execTime));
		}
	}
	
	std::cout << "Room " << this->_name << ": no more player. exit..." << std::endl;
	this->_m.unlock();
}

void	Room::leaveRoom(void *data)
{
	this->_currentClient->setRoomLeaver(true);
	this->_currentClient->setWaiting(true);
	std::cout << "Leaver Ok" << std::endl;
}

void	Room::setMap(void *data)
{
	s_set_map *dataStruct = (reinterpret_cast<s_set_map *>(data));
	
	this->_script->setRandom(dataStruct->status);
	this->_map->replace(0, std::string::npos, (dataStruct->filename));
}

void	Room::changeDifficulty(void *data)
{
	this->_difficulty = *(reinterpret_cast<char *>(data));
}

void	Room::getFileTrunk(void *data)
{

}

void	Room::setReady(void *data)
{
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _party.size())
	{
		if (_party[i]->getClient()->getId() == 	this->_currentClient->getId())
		{
			(* ite)->setReady(!(* ite)->getReady());
			if ((* ite)->getReady() == true)
			{
				this->_nbReady++;
			}
			else
				this->_nbReady--;
			return;
		}
		++i;
		++ite;
	}
}

void	Room::downloadRessource(void *data)
{

}

void	Room::UDPReady(void *data)
{
	int i = 0;
	s_udp_ready *mydata = static_cast<s_udp_ready *>(data);

	while (i < _party.size())
	{
		if (*(_party[i]->getClient()->getName()) == mydata->nickname)
		{
			if (_party[i]->getClient()->getInaddr() == 0)
			{
				this->_nbReady ++;
				_party[i]->getClient()->setInaddr(mydata->from);
			}
		}
		++i;
	}
}

void	Room::letsPlay(void *data)
{
	this->_nbReady ++;
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
	return (false);
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

bool	Room::addClient(Client* newClient)
{
	if (this->_party.size() < 4)
	{
		_party.push_back(new Player(newClient, this->validId()));
		return (true);
	}
	else
	{
		std::cout << "This lobby is full." << std::endl;
		return (false);
	}
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