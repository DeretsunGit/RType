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
	// faire un fichier qui resume les opcodes d'erreur
	std::cout << "Impossible Action : callback with opcode " << std::hex << opcode;
	std::cout << " can't be done while _isWaiting = true" << std::endl;
	this->sendError(61, "You can't perform this action by now.");
}

bool	Room::startGame()
{
	bool	ready(false);
	ready = false;
	std::vector<Player *>::iterator	ite = this->_party.begin();

	std::cout << "Room (id = " << this->_id << ", nb player = "<< this->_nbReady
				<<") attempt to create a game." << std::endl;
	//startloading
	while (ite != this->_party.end())
	{
		std::cout << "fail : "<< this->_udpSock->getPort() << std::endl;
		this->_RoomCom.TCPstartLoading(this->_pack, this->_udpSock->getPort());
		std::cout << "-----------" << std::endl;
		this->_currentClient->getTCPSock()->send(this->_pack);
		std::cout << "fail bis" << std::endl;

		++ite;
	}
	std::cout << "Start Loading send... Waiting UDP port confirmation ..." << std::endl;
	// on attend udpready des clients
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
	std::cout << "UDP is ok !" << std::endl;
	//on leur renvoie udpokay
	this->_RoomCom.UDPok(this->_pack);
	this->_udpSock->broadcast(this->_pack);
	std::cout << "sending UDPokay" << std::endl;
	//on attend lets play
	this->_nbReady = 0;
	ready = false;
	while (ready != true)
	{
		for (ite = this->_party.begin(); ite != this->_party.end(); ite++)
		{
			this->_RoomCom.interpretCommand(*(this->_currentClient->getTCPSock()));
		}
		if (this->_nbReady == this->_party.size())
			ready = true;
	}
	std::cout << "Everybody's ok ! Game Starting !" << std::endl;
	if (ready == true)
	{
		this->_script->LoadMap(this->_map);
		std::cout << "Script generation ok" << std::endl;
		//this->_game = new Game(this->_party, this->_script, this->_udpSock);
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
	bool finish = false;
	std::vector<Player*>::iterator	ite = this->_party.begin();
	
	std::cout << "Room " << this->_name << "Started to Loop" << std::endl;
	while (this->_party.size() > 0 && finish == false)
	{
		ite = (this->_party).begin();
		while ( (ite != (this->_party).end()))
		{
			this->_currentClient = (*ite)->getClient();
			this->_RoomCom.interpretCommand(*(this->_currentClient->getTCPSock()));
			if ((this->_currentClient->getRoomLeaver()) == true)
				ite = this->_party.erase(ite);
			else
				ite++;
		}
		if (this->_nbReady == this->_party.size() && this->_party.size() > 0)
		{
			std::cout << this->_nbReady <<" - "<< this->_party.size() << std::endl;
			this->startGame();
			finish = true;
		}
	}
	std::cout << "Room " << this->_name << ": no more player. exit..." << std::endl;
	this->_m.unlock();
}

void	Room::leaveRoom(void *data)
{
	std::cout << "LEAVER"<< std::endl;
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
//	s_change_difficulty *dataStruct = (reinterpret_cast<s_change_difficulty *>(data));
	std::cout << "Changing difficluty" << std::endl;
	this->_difficulty = *(reinterpret_cast<char *>(data));
}

void	Room::getFileTrunk(void *data)
{

}

void	Room::setReady(void *data)
{
	std::cout << "Player Ready" << std::endl;
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
	std::cout << "I HAZ BIN CALID, ME ZI     UDPREADY !" << std::endl;
	int i = 0;
	s_udp_ready *mydata = static_cast<s_udp_ready *>(data);

	std::cout << "name : " << mydata->nickname << std::endl;
	while (i < _party.size())
	{
		if (*(_party[i]->getClient()->getName()) == mydata->nickname)
		{
			if (_party[i]->getClient()->getInaddr() == 0)
			{
				std::cout << "LOL" << std::endl;
				this->_nbReady ++;
				_party[i]->getClient()->setInaddr(mydata->from);
			}
		}
		++i;
	}
}

void	Room::letsPlay(void *data)
{
	// launch game if all clients said it
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