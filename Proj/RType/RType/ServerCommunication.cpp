//
// ServerCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

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

void	ServerCommunication::TCPsendRoomList(const std::list<int>& roomIds, const std::list<int>& playersInRoom, const std::list<int>& maxPlayersNb)
{
	(void)roomIds; (void)playersInRoom; (void)maxPlayersNb;
}

void	ServerCommunication::TCPsendPlayerList(int roomId, const std::list<std::string>& players)
{
	(void)roomId; (void)players;
}

void	ServerCommunication::TCPaskClientForFiles(const std::list<std::string>& filenames)
{
	(void)filenames;
}

void	ServerCommunication::TCPsendFile(const std::string& filename, const char* fileContent)
{
	(void)filename; (void)fileContent;
}

void	ServerCommunication::TCPsendStartLoading()
{
	;
}

void	ServerCommunication::TCPsendStartGame()
{
	;
}

void	ServerCommunication::UDPsendGameMap(const char* map)
{
	if (map == NULL)
		return /*error*/;

	char* buffer = (char*)malloc(UDPBLOCKS);

	if (buffer == NULL)
		return /*error*/;

	buffer[0] = 0x0f;
	memcpy(&buffer[1], map, UDPDATASIZE);
	//buffer map is filled and ready to be sent
}

void	ServerCommunication::UDPsendGameElements(const std::list<Element>& elements)
{
	int i = 0;
	std::list<Element>::const_iterator ite = elements.begin();

	if (!elements.size())
		return ;

	char* buffer = (char*)malloc(sizeof(UDPBLOCKS));

	if (buffer == NULL)
		return ;

	buffer[0] = 0x10;

	while (ite != elements.end() && i < 48)
	{
		s_element newElement;
		newElement.posX = ite->_x;
		newElement.posY = ite->_y;
		newElement.spriteId = ite->_spriteId;
		newElement.id = ite->_elementId;
		memcpy(&buffer[(i*sizeof(s_element))+1], &newElement, sizeof(s_element));
		++i;
		++ite;
	}

	//buffer element is filled and ready to be sent.
}

void	ServerCommunication::UDPsendPlayersStatus(const std::list<Player>& players)
{
	int i = 0;
	std::list<Player>::const_iterator ite = players.begin();

	if (!players.size())
		return ;

	char* buffer = (char*)malloc(sizeof(UDPBLOCKS));

	if (buffer == NULL)
		return ;

	buffer[0] = 0x11;

	while (ite != players.end() && i < 4)
	{
		s_player newPlayer;
		newPlayer.alive = ite->alive;
		newPlayer.win = ite->win;
		newPlayer.defeat = ite->defeat;
		newPlayer.shield = ite->shield;
		memcpy(&buffer[(i*sizeof(s_player))+1], &newPlayer, sizeof(s_player));
		++i;
		++ite;
	}

	//buffer player is filled and ready to be sent.
}