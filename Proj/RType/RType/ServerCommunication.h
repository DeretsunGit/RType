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

#define UDPBLOCKS 289
#define UDPDATASIZE 288
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
	char id;
};

struct s_player
{
	char alive;
	bool win;
	bool defeat;
	bool shield;
};

// declaration of Element class waiting for official one
class Element
{
public:
	short _x;
	short _y;
	char _spriteId;
	char _elementId;

	Element();
	~Element();
};
// declaration of Player class waiting for official one
class Player
{
public:
	bool alive;
	bool win;
	bool defeat;
	bool shield;

	Player();
	~Player();
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

	void TCPsendRoomList(const std::list<int>& roomIds, const std::list<int>& playersInRoom, const std::list<int>& maxPlayersNb); 
	void TCPsendPlayerList(int roomId, const std::list<std::string>& players);
	void TCPaskClientForFiles(const std::list<std::string>& filenames);
	void TCPsendFile(const std::string& filename, const char* fileContent);
	void TCPsendStartLoading();
	void TCPsendStartGame();
	void UDPsendGameMap(const char* map);
	void UDPsendGameElements(const std::list<Element>& elements);
	void UDPsendPlayersStatus(const std::list<Player>& players);
};