//
// ServerCommunication.h for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>
#include <list>
#include <map>
#include "Packet.hpp"
#include "Player.h"
#include "Element.h"

#define UDPBLOCKS 517
#define UDPDATASIZE 516
#define OPCODESIZE 1

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
};

struct s_player
{
	bool alive;
	bool win;
	bool defeat;
	bool shield;
};

class ServerCommunication
{
private:
	std::map<char, void (ServerCommunication::*)(const char*) const> _commandMap;

	void TCProomAssignment(const char *data) const;
	void TCPupdateNickname(const char *data) const;
	void TCPupdateResolution(const char *data) const;
	void TCPgetOwnedFiles(const char *data) const;
	void TCPfileTransferConfirmation(const char *data) const;
	void TCPgetReady(const char *data) const;
	void TCPsendMap(const char *data) const;
	void TCPgetMap(const char *data) const;
	void UDPinterpretInputs(const char *data) const;

public:
	ServerCommunication();
	~ServerCommunication();

	void interpretCommand(const char* command) const;

	Packet* TCPsendRoomList(const std::list<int>& roomIds, const std::list<int>& playersInRoom, const std::list<int>& maxPlayersNb); 
	Packet* TCPsendPlayerList(int roomId, const std::list<std::string>& players);
	Packet* TCPaskClientForFiles(const std::list<std::string>& filenames);
	Packet* TCPsendFile(const std::string& filename, const char* fileContent);
	Packet* TCPsendStartLoading();
	Packet* TCPsendStartGame();
	Packet* UDPsendGameElements(const std::list<Element>& elements, const std::list<Player>& players);
};