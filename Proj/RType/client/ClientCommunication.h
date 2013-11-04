//
// ClientCommunication.h for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>
#include <list>
#include <map>
#include "Packet.hpp"

struct s_blocks
{
	char opcode;
	short datasize;
	char *data;
};

struct s_inputs
{
	char X;
	char Y;
	bool fire;
	bool shield;
	bool pause;
};

struct s_element
{
	short posX;
	short posY;
	char spriteId;
	char id;
};

struct s_player
{
	char alive;
	bool win;
	bool defeat;
	bool shield;
};

class ClientCommunication
{
private:
	std::map<char, void (ClientCommunication::*)(const char*) const> _commandMap;

	void	TCPgetRoomList(const char *data) const;
	void	TCPgetPlayerList(const char *data) const;
	void	TCPgetFileList(const char *data) const;
	void	TCPgetFile(const char *data) const;
	void	TCPgetStartLoading(const char *data) const;
	void	TCPgetStartGame(const char *data) const;
	void	UDPgetGameElements(const char *data) const;

public:
	ClientCommunication();
	~ClientCommunication();

	void	interpretCommand(const char* command) const;

	Packet*	TCProomChoice(const std::string& nickname, int roomId);
	Packet*	TCPupdateNickname(const std::string& nickname);
	Packet*	TCPupdateResolution(const std::string& resolution);
	Packet*	TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions);
	Packet*	TCPconfirmFileReception(const std::string& filename, const std::string& version);
	Packet*	TCPsendReady();
	Packet*	TCPsendMapRequest();
	Packet*	TCPuploadMap(const std::string& filename, const char* filedata);
	Packet*	UDPsendInputs(s_inputs& inputs) const;
};