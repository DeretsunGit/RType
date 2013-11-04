//
// ClientCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#include <cstring>
#include "ClientCommunication.h"

ClientCommunication::ClientCommunication()
{
	_commandMap[0x01] = &ClientCommunication::TCPgetRoomList;
	_commandMap[0x02] = &ClientCommunication::TCPgetPlayerList;
	_commandMap[0x03] = &ClientCommunication::TCPgetFileList;
	_commandMap[0x04] = &ClientCommunication::TCPgetFile;
	_commandMap[0x05] = &ClientCommunication::TCPgetStartLoading;
	_commandMap[0x06] = &ClientCommunication::TCPgetStartGame;
	_commandMap[0x10] = &ClientCommunication::UDPgetGameElements;
}

ClientCommunication::~ClientCommunication()
{
	;
}

void	ClientCommunication::TCPgetRoomList(const char* data) const
{
	(void)data;
}

void	ClientCommunication::TCPgetPlayerList(const char* data) const
{
	(void)data;
}

void	ClientCommunication::TCPgetFileList(const char* data) const
{
	(void)data;
}

void	ClientCommunication::TCPgetFile(const char* data) const
{
	(void)data;
}

void	ClientCommunication::TCPgetStartLoading(const char* data) const
{
	(void)data;
}

void	ClientCommunication::TCPgetStartGame(const char* data) const
{
	(void)data;
}

void	ClientCommunication::UDPgetGameElements(const char* data) const
{
	int i = 0;
	std::list<s_element> elements;
	std::list<s_player> players;

	if (data == NULL)
		return ;

	while (i < 100 && strlen(&data[i*sizeof(s_element)]) >= sizeof(s_element))
	{
		s_element newElement;
		memcpy(&newElement, &data[i*sizeof(s_element)], sizeof(s_element));
		elements.push_back(newElement);
		++i;
	}

	while (i < 104 && strlen(&data[i*sizeof(s_player)]) >= sizeof(s_player))
	{
		s_player newPlayer;
		memcpy(&newPlayer, &data[i*sizeof(s_player)], sizeof(s_player));
		players.push_back(newPlayer);
		++i;
	}

	return ;
}

void	ClientCommunication::interpretCommand(const char* command) const
{
	std::map<char, void (ClientCommunication::*)(const char*) const>::const_iterator ite;

	if (command != NULL && ((ite = _commandMap.find(command[0])) != _commandMap.end()))
		(this->*(ite->second))(&command[1]);
}

Packet*	ClientCommunication::TCProomChoice(const std::string& nickname, int roomId)
{
	(void)nickname; (void)roomId;
	return (new Packet());
}

Packet*	ClientCommunication::TCPupdateNickname(const std::string& nickname)
{
	(void)nickname;
	return (new Packet());
}

Packet*	ClientCommunication::TCPupdateResolution(const std::string& resolution)
{
	(void)resolution;
	return (new Packet());
}

Packet*	ClientCommunication::TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions)
{
	(void)filenames; (void)versions;
	return (new Packet());
}

Packet*	ClientCommunication::TCPconfirmFileReception(const std::string& filename, const std::string& version)
{
	(void)filename; (void)version;
	return (new Packet());
}

Packet*	ClientCommunication::TCPsendReady()
{
	s_blocks block;
	Packet* packet = new Packet();
	char* buff = new char[3];

	block.opcode = 0x0c;
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

Packet*	ClientCommunication::TCPsendMapRequest()
{
	s_blocks block;
	Packet* packet = new Packet();
	char* buff = new char[3];

	block.opcode = 0x0d;
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

Packet*	ClientCommunication::TCPuploadMap(const std::string& filename, const char* filedata)
{
	(void)filename; (void)filedata;
	return (new Packet());
}

Packet*	ClientCommunication::UDPsendInputs(s_inputs& inputs) const
{
	Packet* packet = new Packet();
	char* buff = new char[sizeof(s_inputs) + 1];

	buff[0] = 0x12;
	memcpy(&buff[1], &inputs, sizeof(s_inputs));

	if (!packet->set(buff, sizeof(s_inputs) + 1))
	{
		delete buff;
		delete packet;
		return (NULL);
	}
	return (packet);
}
