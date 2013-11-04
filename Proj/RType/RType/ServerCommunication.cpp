//
// ServerCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#include <cstring>
#include "ServerCommunication.h"

ServerCommunication::ServerCommunication()
{
	_commandMap[0x07] = &ServerCommunication::TCProomAssignment;
	_commandMap[0x08] = &ServerCommunication::TCPupdateNickname;
	_commandMap[0x09] = &ServerCommunication::TCPupdateResolution;
	_commandMap[0x0a] = &ServerCommunication::TCPgetOwnedFiles;
	_commandMap[0x0b] = &ServerCommunication::TCPfileTransferConfirmation;
	_commandMap[0x0c] = &ServerCommunication::TCPgetReady;
	_commandMap[0x0d] = &ServerCommunication::TCPsendMap;
	_commandMap[0x0e] = &ServerCommunication::TCPgetMap;
	_commandMap[0x12] = &ServerCommunication::UDPinterpretInputs;
}

ServerCommunication::~ServerCommunication()
{
	;
}

void	ServerCommunication::TCProomAssignment(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPupdateNickname(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPupdateResolution(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPgetOwnedFiles(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPfileTransferConfirmation(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPgetReady(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPsendMap(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPgetMap(const char* data) const
{
	(void)data;
}

void	ServerCommunication::UDPinterpretInputs(const char* data) const
{
	s_inputs inputs;

	memcpy(&inputs, data, sizeof(s_inputs));
	// the inputs struct is filled from here
}

void	ServerCommunication::interpretCommand(const char* command) const
{
	std::map<char, void (ServerCommunication::*)(const char*) const>::const_iterator ite;

	if (command != NULL && ((ite = _commandMap.find(command[0])) != _commandMap.end()))
		(this->*(ite->second))(&command[1]);
}

Packet*	ServerCommunication::TCPsendRoomList(const std::list<int>& roomIds, const std::list<int>& playersInRoom, const std::list<int>& maxPlayersNb)
{
	(void)roomIds; (void)playersInRoom; (void)maxPlayersNb;
	return (new Packet());
}

Packet*	ServerCommunication::TCPsendPlayerList(int roomId, const std::list<std::string>& players)
{
	(void)roomId; (void)players;
	return (new Packet());
}

Packet*	ServerCommunication::TCPaskClientForFiles(const std::list<std::string>& filenames)
{
	(void)filenames;
	return (new Packet());
}

Packet*	ServerCommunication::TCPsendFile(const std::string& filename, const char* fileContent)
{
	(void)filename; (void)fileContent;
	return (new Packet());
}

Packet*	ServerCommunication::TCPsendStartLoading()
{
	s_blocks block;
	char* buff = new char[3];
	Packet* packet = new Packet();

	block.opcode = 0x05;
	block.datasize = 0;
	block.data = NULL;

	memcpy(buff, &block, 3);
	if (!packet->set(buff, 3))
	{
		delete buff;
		delete packet;
		return (NULL);
	}
	return (packet);
}

Packet*	ServerCommunication::TCPsendStartGame()
{
	s_blocks block;
	char* buff = new char[3];
	Packet* packet = new Packet();

	block.opcode = 0x06;
	block.datasize = 0;
	block.data = NULL;

	memcpy(buff, &block, 3);
	if (!packet->set(buff, 3))
	{
		delete buff;
		delete packet;
		return (NULL);
	}
	return (packet);
}

Packet*	ServerCommunication::UDPsendGameElements(const std::list<Element>& elements, const std::list<Player>& players)
{
	int i = 0;
	Packet* packet = new Packet();
	std::list<Element>::const_iterator elem_ite = elements.begin();
	std::list<Player>::const_iterator play_ite = players.begin();

	if (!elements.size() || !players.size())
	{
		delete packet;
		return NULL;
	}

	char* buffer = new char[UDPBLOCKS];
	char* ctmp;

	buffer[0] = 0x10;

	while (elem_ite != elements.end() && i < 100)
	{
		s_element newElement;
		newElement.posX = elem_ite->getPos()._posX;
		newElement.posY = elem_ite->getPos()._posY;
		newElement.spriteId = elem_ite->getSpriteId();
		memcpy(&buffer[(i*sizeof(s_element))+1], &newElement, sizeof(s_element));
		++i;
		++elem_ite;
	}

	ctmp = &buffer[501];
	i = 0;
	while (play_ite != players.end() && i < 4)
	{
		s_player newPlayer;
		newPlayer.alive = play_ite->isAlive();
		newPlayer.win = play_ite->isWinner();
		newPlayer.defeat = play_ite->isDefeated();
		newPlayer.shield = play_ite->getShield();
		memcpy(&buffer[i*sizeof(s_player)], &newPlayer, sizeof(s_player));
		++i;
		++play_ite;
	}

	if (!packet->set(buffer, UDPBLOCKS))
	{
		delete buffer;
		delete packet;
		return NULL;
	}
	return (packet);
}
