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

#define TCPHEADSIZE 3
#define OPCODESIZE 1

struct s_tcp_header
{
	char opcode;
	short datasize;
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
	bool alive;
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


public:
	ClientCommunication();
	~ClientCommunication();

	void	interpretCommand(const char* command) const;
	unsigned short	TCPgetStartGame(const char *data) const;
	void	UDPgetGameElements(const char *data) const;

	Packet*	TCProomChoice(const std::string& nickname, char roomId) const;
	Packet*	TCPupdateNickname(const std::string& nickname) const;
	Packet*	TCPupdateResolution(const std::string& resolution) const;
	Packet*	TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions) const;
	Packet*	TCPconfirmFileReception(const std::string& filename, const std::string& version) const;
	Packet*	TCPsendReady() const;
	Packet*	TCPsendMapRequest() const;
	Packet*	TCPuploadMap(const std::string& filename, const char* filedata) const;
	Packet*	UDPsendInputs(const s_inputs& inputs) const;
};