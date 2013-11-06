//
// ClientCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#include <cstring>
#include <vector>
#include "ClientCommunication.h"

ClientCommunication::ClientCommunication()
{
	_commandMap[0x01] = &ClientCommunication::TCPgetRoomList;
	_commandMap[0x02] = &ClientCommunication::TCPgetPlayerList;
	_commandMap[0x03] = &ClientCommunication::TCPgetFileList;
	_commandMap[0x04] = &ClientCommunication::TCPgetFile;
	_commandMap[0x05] = &ClientCommunication::TCPgetStartLoading;
	//_commandMap[0x06] = &ClientCommunication::TCPgetStartGame;
	_commandMap[0x10] = &ClientCommunication::UDPgetGameElements;
}

ClientCommunication::~ClientCommunication()
{
	;
}

void	ClientCommunication::TCPgetRoomList(const char* data) const
{
	s_tcp_header block;
	std::vector<char> rooms;
	std::vector<char> playerNb;
	memcpy(&block, data, TCPHEADSIZE);
	int i = TCPHEADSIZE, limit = TCPHEADSIZE+block.datasize;

	while (i < limit)
	{
		rooms.push_back(data[i]);
		playerNb.push_back(data[i+1]);
		i += 2;
	}

	//the two lists are filled and ready.
	
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
	s_tcp_header block;
	memcpy(&block, data, TCPHEADSIZE);
	if (block.opcode == 0x05)
		return /*bien !*/;
	return /*pas bien!*/;
}

unsigned short	ClientCommunication::TCPgetStartGame(const char* data) const
{
	s_tcp_header block;
	unsigned short port;
	memcpy(&block, data, TCPHEADSIZE);
	if (block.opcode == 0x06 && block.datasize == sizeof(unsigned short))
	{
		memcpy(&port, &data[TCPHEADSIZE], sizeof(unsigned short));
		return port;	
	}
	return 0;
}

void	ClientCommunication::UDPgetGameElements(const char* data) const
{
	int i = 0;
	data = &data[1];
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
	
	i = 100;
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
		(this->*(ite->second))(command);
}

Packet*	ClientCommunication::TCProomChoice(const std::string& nickname, char roomId) const
{
	s_tcp_header block;
	Packet* packet = new Packet();
	block.opcode = 0x07;
	block.datasize = (short)nickname.size() + 1;
	char* buff = new char[TCPHEADSIZE + block.datasize];

	memcpy(buff, &block, TCPHEADSIZE);
	memcpy(&buff[TCPHEADSIZE], nickname.c_str(), nickname.size());
	memcpy(&buff[TCPHEADSIZE+nickname.size()], &roomId, 1);

/*	if (!packet->set(buff, TCPHEADSIZE+block.datasize))
	{
		delete buff;
		delete packet;
		return (NULL);
	}*/

	return (packet);
}

Packet*	ClientCommunication::TCPupdateNickname(const std::string& nickname) const
{
	s_tcp_header block;
	Packet* packet = new Packet();
	block.opcode = 0x08;
	block.datasize = (short)nickname.size();
	char* buff = new char[TCPHEADSIZE + block.datasize];

	memcpy(buff, &block, TCPHEADSIZE);
	memcpy(&buff[TCPHEADSIZE], nickname.c_str(), nickname.size());

	/*if (!packet->set(buff, TCPHEADSIZE+block.datasize))
	{
		delete buff;
		delete packet;
		return (NULL);
	}*/

	return (packet);
}

Packet*	ClientCommunication::TCPupdateResolution(const std::string& resolution) const
{
	s_tcp_header block;
	Packet* packet = new Packet();
	block.opcode = 0x09;
	block.datasize = (short)resolution.size();
	char* buff = new char[TCPHEADSIZE + block.datasize];

	memcpy(buff, &block, TCPHEADSIZE);
	memcpy(&buff[TCPHEADSIZE], resolution.c_str(), resolution.size());

	/*if (!packet->set(buff, TCPHEADSIZE+block.datasize))
	{
		delete buff;
		delete packet;
		return (NULL);
	}*/

	return (packet);
}

Packet*	ClientCommunication::TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions) const
{
	(void)filenames; (void)versions;
	return (new Packet());
}

Packet*	ClientCommunication::TCPconfirmFileReception(const std::string& filename, const std::string& version) const
{
	s_tcp_header block;
	Packet* packet = new Packet();
	block.opcode = 0x0b;
	block.datasize = (short)(filename.size() + version.size());
	char* buff = new char[TCPHEADSIZE + block.datasize];

	memcpy(buff, &block, TCPHEADSIZE);
	memcpy(&buff[TCPHEADSIZE], filename.c_str(), filename.size());
	memcpy(&buff[TCPHEADSIZE+filename.size()], version.c_str(), version.size());

	/*if (!packet->set(buff, TCPHEADSIZE+block.datasize))
	{
		delete buff;
		delete packet;
		return (NULL);
	}*/

	return (packet);
}

void	ClientCommunication::TCPsendReady(Packet& packet) const
{
	s_tcp_header block;

	block.opcode = 0x0c;
	block.datasize = 0;

	packet.set(reinterpret_cast<char*>(&block), 0, TCPHEADSIZE);
}

Packet*	ClientCommunication::TCPsendMapRequest() const
{
	s_tcp_header block;
	Packet* packet = new Packet();
	char* buff = new char[TCPHEADSIZE];

	block.opcode = 0x0d;
	block.datasize = 0;

	memcpy(buff, &block, TCPHEADSIZE);
	/*if (!packet->set(buff, TCPHEADSIZE))
	{
		delete buff;
		delete packet;
		return (NULL);
	}*/
	return (packet);
}

Packet*	ClientCommunication::TCPuploadMap(const std::string& filename, const char* filedata) const
{
	(void)filename; (void)filedata;
	return (new Packet());
}

void	ClientCommunication::UDPsendInputs(Packet& packet, s_inputs& inputs) const
{
	char opcode = 0x12;
	packet.set(&opcode, 0, 1);
	packet.set(reinterpret_cast<char*>(&inputs), 1, sizeof(s_inputs));
}
