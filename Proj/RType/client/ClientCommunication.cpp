//
// ClientCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#include "ClientCommunication.h"

ClientCommunication::ClientCommunication()
{
	_commandMap[0x01] = &ClientCommunication::TCPgetRoomList;
	_commandMap[0x02] = &ClientCommunication::TCPgetPlayerList;
	_commandMap[0x03] = &ClientCommunication::TCPgetFileList;
	_commandMap[0x04] = &ClientCommunication::TCPgetFile;
	_commandMap[0x05] = &ClientCommunication::TCPgetStartLoading;
	_commandMap[0x06] = &ClientCommunication::TCPgetStartGame;
	_commandMap[0x0f] = &ClientCommunication::UDPgetGameMap;
	_commandMap[0x10] = &ClientCommunication::UDPgetGameElements;
	_commandMap[0x11] = &ClientCommunication::UDPgetPlayerStatus;
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

void	ClientCommunication::UDPgetGameMap(const char* data) const
{
	std::string map(data);

	if (map.size() != 288)
		return /*error*/;
}

void	ClientCommunication::UDPgetGameElements(const char* data) const
{
	int i = 0;
	std::list<s_element> elements;

	if (data == NULL)
		return /*error*/;

	while (i < 48 && strlen(&data[i*sizeof(s_element)]) >= sizeof(s_element))
	{
		s_element newElement;
		memcpy(&newElement, &data[i*sizeof(s_element)], sizeof(s_element)); 
		elements.push_back(newElement);
		++i;
	}

	return ;
}

void	ClientCommunication::UDPgetPlayerStatus(const char* data) const
{
	int i = 0;
	std::list<s_player> players;

	if (data == NULL)
		return /*error*/;

	while (i < 4 && strlen(&data[i*sizeof(s_player)]), sizeof(s_player))
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

void	ClientCommunication::TCProomChoice(const std::string& nickname, int roomId)
{
	(void)nickname; (void)roomId;
}

void	ClientCommunication::TCPupdateNickname(const std::string& nickname)
{
	(void)nickname;
}

void	ClientCommunication::TCPupdateResolution(const std::string& resolution)
{
	(void)resolution;
}

void	ClientCommunication::TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions)
{
	(void)filenames; (void)versions;
}

void	ClientCommunication::TCPconfirmFileReception(const std::string& filename, const std::string& version)
{
	(void)filename; (void)version;
}

void	ClientCommunication::TCPsendReady()
{
	;
}

void	ClientCommunication::TCPsendMapRequest()
{
	;
}

void	ClientCommunication::TCPuploadMap(const std::string& filename, const char* filedata)
{
	(void)filename; (void)filedata;
}

void	ClientCommunication::UDPsendInputs(s_inputs& inputs) const
{
	char* buffer = (char*)malloc(sizeof(s_inputs) + 1);
	if (buffer == NULL)
		return ;
	buffer[0] = 0x12;
	memcpy(&buffer[1], &inputs, sizeof(s_inputs));

	//the buffer is filled and can be send
}