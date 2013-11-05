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
#include "Room.h"

#define UDPBLOCKS 517
#define UDPDATASIZE 516
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

	Packet* TCPsendRoomList(const std::list<Room>& rooms) const; 
	Packet* TCPsendPlayerList(int roomId, const std::vector<Player*>& players) const;
	Packet* TCPaskClientForFiles(const std::list<std::string>& filenames) const;
	Packet* TCPsendFile(const std::string& filename, const char* fileContent) const;
	Packet* TCPsendStartLoading() const;
	Packet* TCPsendStartGame() const;
	Packet* UDPsendGameElements(const std::list<Element*>& elements, const std::vector<Player*>& players) const;
};