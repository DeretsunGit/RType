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

struct s_blocks
{
	char opcode;
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
	void	UDPgetGameMap(const char *data) const;
	void	UDPgetGameElements(const char *data) const;
	void	UDPgetPlayerStatus(const char *data) const;

public:
	ClientCommunication();
	~ClientCommunication();

	void	interpretCommand(const char* command) const;

	void	TCProomChoice(const std::string& nickname, int roomId);
	void	TCPupdateNickname(const std::string& nickname);
	void	TCPupdateResolution(const std::string& resolution);
	void	TCPsendOwnedFiles(const std::list<std::string>& filenames, const std::list<std::string>& versions);
	void	TCPconfirmFileReception(const std::string& filename, const std::string& version);
	void	TCPsendReady();
	void	TCPsendMapRequest();
	void	TCPuploadMap(const std::string& filename, const char* filedata);
	void	UDPsendInputs(s_inputs& inputs) const;
};