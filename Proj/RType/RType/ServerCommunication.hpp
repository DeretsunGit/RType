//
// ServerCommunication.hpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>
#include <list>
#include <map>
#include "IReadableSocket.h"
#include "Packet.hpp"
#include "Room.h"
#include "Player.h"

/* TCP BLOCK STRUCTURES DEFINITION */
struct s_say_hello
{
	char opcode;
	short datasize;
	char magic[6];
	char *nickname;
	short resolution[2];
};

struct s_room_list
{
	char opcode;
	short datasize;
	char **roomName;
	char *roomId;
	char *nbPlayer;
};

struct s_set_room
{
	char opcode;
	short datasize;
	char *roomName;
};

struct s_select_room
{
	char opcode;
	char roomId;
};

struct s_leave_room
{
	char opcode;
	char roomId;
};

struct s_room_state_content
{
	char *roomName;
	char *playerNames[4];
	bool playerStates[4];
	char difficulty;
	bool mapStatus; // random or file
	char *map; // map name
};

struct s_room_state
{
	char opcode;
	short datasize;
	struct s_room_state_content *content;
};

struct s_change_difficulty
{
	char opcode;
	bool difficulty;
};

struct s_set_map
{
	char opcode;
	short datasize;
	bool mapStatus;
	char *filename;
	char *fileContent;
};

struct s_wrong_map
{
	char opcode;
};

struct s_set_ready
{
	char opcode;
};

struct s_ressource
{
	char *filename;
	char *md5;
};

struct s_start_loading
{
	char opcode;
	short datasize;
	struct s_ressource *ressources;
	unsigned short UDPport;
};

struct s_download_ressource
{
	char opcode;
	short datasize;
	char *filename;
};

struct s_file_trunk
{
	char opcode;
	short datasize;
	char *filename;
	char *data;
};

struct s_assoc_sprites
{
	char opcode;
	short datasize;
	char *idSprite;
	char *filename;
	t_coord *coords;
};

struct s_lets_play
{
	char opcode;
};

struct s_save_map
{
	char opcode;
	short datasize;
	char *mapName;
};

struct s_send_error
{
	char opcode;
	char errorCode;
	char *errorDescr;
};

/* UPD BLOCK STRUCTURES DEFINITION */

struct s_udp_ready
{
	char opcode;
};

struct s_udp_ok
{
	char opcode;
};

struct s_inputs
{
	char opcode;
	char x;
	char y;
	bool fire;
	bool shield;
};

struct s_screen_state
{
	char opcode;
	short datasize;
	int score;
	char *idSprite;
	t_coord* coordSprite;
};

struct s_end_of_game
{
	char opcode;
	int score;
};

/* NOT INCLUDED UDP BLOCKS */

struct s_pause
{
	char opcode;
};

struct s_pause_ok
{
	char opcode;
};

struct s_spawn
{
	char opcode;
};

struct s_death
{
	char opcode;
};

/* END OF BLOCK STRUCTURES DEFINITION */

template<typename T>
class ServerCommunication
{
private:
	std::map<char, void (ServerCommunication::*)(IReadableSocket&) const> _commandMap;
	std::map<char, void (T::*)(void*)> _callableMap;

	T* _handler;
	void (T::*_defaultCallback)(char, IReadableSocket&);

	bool exempleOfDeserialisationFunction(IReadableSocket& socket)
	{
		s_coord tmp; // structure correspondant à chaque commande
		char* data;
		short datasize;
		int readSize = 0;

		if (socket.readable())
		{
			readSize += socket.recv(reinterpret_cast<char*>(&datasize), 2);
			if (readSize != 2)
			{
				socket.putback(reinterpret_cast<char*>(&datasize), readSize);
				return false;
			}
			data = new char[datasize];
			readSize += socket.recv(data, datasize);
			if (readSize != datasize + 2)
			{
				socket.putback(reinterpret_cast<char*>(&datasize), 2);
				socket.putback(data, readSize -2);
				return false;
			}
			else if (!_handler && _callableMap.find(0x01) != _callableMap.end())
			{
				// déserialisation dans tmp
				tmp._posX = 0;
				(_handler->*_callableMap[0x01])(&tmp);
			}
		}
		return true;
	}

public:
	ServerCommunication()
	{
		_handler = NULL;
		_defaultCallback = NULL;
		_commandMap[0x00] = &ServerCommunication::TCPsayHello;
		_commandMap[0x00] = &ServerCommunication::TCPsetRoom;
		_commandMap[0x00] = &ServerCommunication::TCPselectRoom;
		_commandMap[0x00] = &ServerCommunication::TCPleaveRoom;
		_commandMap[0x00] = &ServerCommunication::TCPchangeDifficulty;
		_commandMap[0x00] = &ServerCommunication::TCPsetMap;
		_commandMap[0x00] = &ServerCommunication::TCPgetFileTrunk;
		_commandMap[0x00] = &ServerCommunication::TCPsetReady;
		_commandMap[0x00] = &ServerCommunication::TCPdownloadRessource;
		_commandMap[0x00] = &ServerCommunication::UDPReady;
		_commandMap[0x00] = &ServerCommunication::TCPletsPlay;
		_commandMap[0x00] = &ServerCommunication::TCPsaveMap;
		_commandMap[0x00] = &ServerCommunication::UDPinputs;
		_commandMap[0x00] = &ServerCommunication::UDPpauseOk;
	}

	~ServerCommunication() {}

	void setCallback(char opcode, void (T::*mthd)(void* data))
	{
	  this->_callableMap[opcode] = mthd;
	}

	void setDefaultCallback(void (T::*cb)(char, IReadableSocket&))
	{
		_defaultCallback = cb;
	}

	void setHandler(T* handler)
	{
		this->_handler = handler;
	}

	void interpretCommand(IReadableSocket& socket) const
	{
	  typename std::map<char, void (ServerCommunication::*)(IReadableSocket&) const>::const_iterator ite;
		char opcode;

		if (socket.readable())
		{
			socket.recv(&opcode, 1);
			if ((ite = _commandMap.find(opcode)) != _commandMap.end())
			{
				if ((this->*(ite->second))(socket) == false)
					socket.putback(&opcode, 1);
			}
			else if (_handler != NULL && _defaultCallback != NULL)
				(this->*_defaultCallback(opcode, socket));
		}
	}

	/* SERVER TO CLIENT */
	void TCProomList(Packet& packet, std::list<Room>& rooms)
	{}

	void TCProomState(Packet& packet, Room& room)
	{}

	void TCPwrongMap(Packet& packet)
	{}

	void TCPstartLoading(Packet& packet, std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport) // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
	{}

	void TCPsendFileTrunk(Packet& packet, const char* filename, const char* data)
	{}

	void TCPassocSprites(Packet& packet, std::list<char>& idSprites, std::list<std::string>& filenames, std::list<t_coord>& coords)
	{}

	void UDPok(Packet& packet)
	{}

	void TCPsendError(Packet& packet, char errorCode, const char* errorMsg)
	{}

	void UDPscreenState(Packet& packet, int score, std::list<Element>& elements) // elements pour idSprite et CoordSprite
	{}

	void UDPendOfGame(Packet& packet, int score)
	{}

	void UDPpause(Packet& packet)
	{}

	void UDPspawn(Packet& packet)
	{}

	void UPDdeath(Packet& packet)
	{}

	/* CLIENT TO SERVER */
	bool TCPsayHello(IReadableSocket& socket)
	{ return true; }

	bool TCPsetRoom(IReadableSocket& socket)
	{ return true; }

	bool TCPselectRoom(IReadableSocket& socket)
	{ return true; }

	bool TCPleaveRoom(IReadableSocket& socket)
	{ return true; }

	bool TCPchangeDifficulty(IReadableSocket& socket)
	{ return true; }

	bool TCPsetMap(IReadableSocket& socket)
	{ return true; }

	bool TCPgetFileTrunk(IReadableSocket& socket)
	{ return true; }

	bool TCPsetReady(IReadableSocket& socket)
	{ return true; }

	bool TCPdownloadRessource(IReadableSocket& socket)
	{ return true; }

	bool UDPReady(IReadableSocket& socket)
	{ return true; }

	bool TCPletsPlay(IReadableSocket& socket)
	{ return true; }

	bool TCPsaveMap(IReadableSocket& socket)
	{ return true; }

	bool UDPinputs(IReadableSocket& socket)
	{ return true; }

	bool UDPpauseOk(IReadableSocket& socket)
	{ return true; }
};
