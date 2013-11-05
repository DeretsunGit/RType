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
	//_commandMap[0x0c] = &ServerCommunication::TCPgetReady;
	_commandMap[0x0d] = &ServerCommunication::TCPsendMap;
	_commandMap[0x0e] = &ServerCommunication::TCPgetMap;
	//_commandMap[0x12] = &ServerCommunication::UDPinterpretInputs;
}

ServerCommunication::~ServerCommunication()
{
	;
}

void	ServerCommunication::TCProomAssignment(const char* data) const
{
	s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	std::string nickname;
	char roomId;

	nickname.assign(&data[TCPHEADSIZE], block.datasize -1);
	roomId = data[TCPHEADSIZE + block.datasize -1];

	//information filled in string nickname and char roomId
	
}

void	ServerCommunication::TCPupdateNickname(const char* data) const
{
	s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	std::string nickname;

	nickname.assign(&data[TCPHEADSIZE], block.datasize);

	//information filled in string nickname
}

void	ServerCommunication::TCPupdateResolution(const char* data) const
{
	s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	std::string resolution;

	resolution.assign(&data[TCPHEADSIZE], block.datasize);

	//information filled in string resolution
}

void	ServerCommunication::TCPgetOwnedFiles(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPfileTransferConfirmation(const char* data) const
{
	(void)data;
	/*s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	std::string filename;
	std::string version;
	*/
    // Need real separator between filename and version
}

bool	ServerCommunication::TCPgetReady(const char* data) const
{
	s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	if (block.opcode == 0x0c)
		return true;
	return false;
}

void	ServerCommunication::TCPsendMap(const char* data) const
{
	(void)data;
}

void	ServerCommunication::TCPgetMap(const char* data) const
{
	(void)data;
}

void	ServerCommunication::UDPinterpretInputs(s_inputs& inputs, const char* data) const
{
	if (data != NULL)
		memcpy(&inputs, &data[1], sizeof(s_inputs));
	return ;
}

void	ServerCommunication::interpretCommand(const char* command) const
{
	std::map<char, void (ServerCommunication::*)(const char*) const>::const_iterator ite;

	if (command != NULL && ((ite = _commandMap.find(command[0])) != _commandMap.end()))
		(this->*(ite->second))(command);
}

Packet*	ServerCommunication::TCPsendRoomList(const std::list<Room>& rooms) const
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

Packet*	ServerCommunication::TCPsendPlayerList(int roomId, const std::vector<Player*>& players) const
{
	(void)players;
	return (new Packet());
}

Packet*	ServerCommunication::TCPaskClientForFiles(const std::list<std::string>& filenames) const
{
	(void)filenames;
	return (new Packet());
}

Packet*	ServerCommunication::TCPsendFile(const std::string& filename, const char* fileContent) const
{
	(void)filename; (void)fileContent;
	return (new Packet());
}

Packet*	ServerCommunication::TCPsendStartLoading() const
{
	s_tcp_header block;
	char* buff = new char[TCPHEADSIZE];
	Packet* packet = new Packet();

	block.opcode = 0x05;
	block.datasize = 0;

	memcpy(buff, &block, TCPHEADSIZE);
	if (!packet->set(buff, TCPHEADSIZE))
	{
		delete buff;
		delete packet;
		return (NULL);
	}
	return (packet);
}

Packet*	ServerCommunication::TCPsendStartGame(unsigned short port) const
{
	s_tcp_header block;
	char* buff = new char[TCPHEADSIZE + sizeof(unsigned short)];
	Packet* packet = new Packet();

	block.opcode = 0x06;
	block.datasize = sizeof(unsigned short);

	memcpy(buff, &block, TCPHEADSIZE);
	memcpy(&buff[TCPHEADSIZE], &port, sizeof(unsigned short));
	if (!packet->set(buff, TCPHEADSIZE + block.datasize))
	{
		delete buff;
		delete packet;
		return (NULL);
	}
	return (packet);
}

Packet*	ServerCommunication::UDPsendGameElements(const std::list<Element*>& elements, const std::vector<Player*>& players) const
{
	int i = 0;
	Packet* packet = new Packet();
	std::list<Element*>::const_iterator elem_ite = elements.begin();
	std::vector<Player*>::const_iterator play_ite = players.begin();

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
		newElement.posX = (*elem_ite)->getPos()._posX;
		newElement.posY = (*elem_ite)->getPos()._posY;
		newElement.spriteId = (*elem_ite)->getSpriteId();
		memcpy(&buffer[(i*sizeof(s_element))+1], &newElement, sizeof(s_element));
		++i;
		++elem_ite;
	}

	ctmp = &buffer[501];
	i = 0;
	while (play_ite != players.end() && i < 4)
	{
		s_player newPlayer;
		newPlayer.alive = (*play_ite)->isAlive();
		newPlayer.win = (*play_ite)->isWinner();
		newPlayer.defeat = (*play_ite)->isDefeated();
		newPlayer.shield = (*play_ite)->getShield();
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
