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
#define DATASIZE 1000

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

	void	TCProomChoice(Packet& packet, const std::string& nickname, char roomId) const;
	void	TCPupdateNickname(Packet& packet, const std::string& nickname) const;
	void	TCPupdateResolution(Packet& packet, const std::string& resolution) const;
	void	TCPsendOwnedFiles(Packet& packet, const std::list<std::string>& filenames, const std::list<std::string>& versions) const;
	void	TCPconfirmFileReception(Packet& packet, const std::string& filename, const std::string& version) const;
	void	TCPsendReady(Packet& packet) const;
	void	TCPsendMapRequest(Packet& packet) const;
	void	TCPuploadMap(Packet& packet, const std::string& filename, const char* filedata) const;
	void	UDPsendInputs(Packet& packet, s_inputs& inputs) const;
};