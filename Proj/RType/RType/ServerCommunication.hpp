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
//#include "Room.h"
#include "Player.h"

#define HEADSIZE sizeof(char) + sizeof(short) // taille du "header" opcode + datasize

/* TCP BLOCK STRUCTURES DEFINITION */
struct s_say_hello
{
	char opcode;
	short datasize;
	char magic[6];
	char nickname[32];
	short resolution[2];
};

struct s_room_list_content
{
	char roomName[32];
	char roomId;
	char nbPlayer;
};

struct s_room_list
{
	char opcode;
	short datasize;
	s_room_list_content* rooms;
};

struct s_set_room
{
	char opcode;
	short datasize;
	char roomName[32];
};

struct s_select_room
{
	char opcode;
	char roomId;
};

struct s_leave_room
{
	char opcode;
};

struct s_room_state
{
	char opcode;
	short datasize;
	char roomName[32];
	char playerNames[4][32];
	bool playerStates[4];
	char difficulty;
	bool mapStatus; // random or file
	char map[128]; // map name
};

struct s_change_difficulty
{
	char opcode;
	char difficulty;
};

struct s_set_map
{
	char opcode;
	short datasize;
	bool mapStatus;
	char filename[128];
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
	char filename[128];
	char md5[32];
};

struct s_start_loading
{
	char opcode;
	short datasize;
	unsigned short port;
	struct s_ressource *ressources;
};

struct s_download_ressource
{
	char opcode;
	short datasize;
	char filename[128];
};

struct s_file_trunk
{
	char opcode;
	short datasize;
	char filename[128];
	char data[1024];
};

struct s_sprite
{
	char idSprite;
	short coord[4];
};

struct s_assoc_sprites
{
	char opcode;
	short datasize;
	char filename[128];
	s_sprite *sprites;
};

struct s_lets_play
{
	char opcode;
};

struct s_save_map
{
	char opcode;
	short datasize;
	char mapName[128];
};

struct s_send_error
{
	char opcode;
	short datasize;
	char errorCode;
	char errorDesc[256];
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
	s_sprite *sprites;
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

class Room;

template<typename T>
class ServerCommunication
{
private:
	std::map<char, bool (ServerCommunication::*)(IReadableSocket&)> _commandMap;
	std::map<char, void (T::*)(void*)> _callableMap;

	T* _handler;
	void (T::*_defaultCallback)(char, IReadableSocket&);

public:
	ServerCommunication()
	{
		_handler = NULL;
		_defaultCallback = NULL;
		_commandMap[0x01] = &ServerCommunication::TCPsayHello;			// 0x01 - RTypeServer
		_commandMap[0x02] = &ServerCommunication::TCPsetRoom;			// 0x02 -
		_commandMap[0x03] = &ServerCommunication::TCPselectRoom;		// 0x03 -
		_commandMap[0x04] = &ServerCommunication::TCPleaveRoom;			// 0x04 -
		_commandMap[0x05] = &ServerCommunication::TCPchangeDifficulty;	// 0x05 - Room
		_commandMap[0x06] = &ServerCommunication::TCPsetMap;			// 0x06 -
		_commandMap[0x07] = &ServerCommunication::TCPgetFileTrunk;		// 0x07 -
		_commandMap[0x08] = &ServerCommunication::TCPsetReady;			// 0x08 -
		_commandMap[0x09] = &ServerCommunication::TCPdownloadRessource;	// 0x09 -
		_commandMap[0x0A] = &ServerCommunication::UDPReady;				// 0x0A -
		_commandMap[0x0B] = &ServerCommunication::TCPletsPlay;			// 0x0B -
		_commandMap[0x0C] = &ServerCommunication::TCPsaveMap;			// 0x0C -
		_commandMap[0x0D] = &ServerCommunication::UDPinputs;			// 0x0D - Game
		_commandMap[0x0E] = &ServerCommunication::UDPpauseOk;			// 0x0E - 
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

	void interpretCommand(IReadableSocket& socket)
	{
	  typename std::map<char, bool (ServerCommunication::*)(IReadableSocket&) >::const_iterator ite;
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
				(this->_handler->*_defaultCallback)(opcode, socket);
		}
	}

	// les fonctions ayant disparues se trouvent dans ServerCommunication.cpp .
	//pas mal de problemes d'include nous ont forcés a faire ca.

	/* SERVER TO CLIENT */
	void TCProomList(Packet& packet, std::list<Room *>& rooms); // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
	void TCProomState(Packet& packet, Room& room);
	void TCPwrongMap(Packet& packet);
	void TCPstartLoading(Packet& packet, std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport); // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
	void TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size);
	void TCPassocSprites(Packet& packet, const char* filename, std::list<char>& idSprites, std::list<short[4]>& coords);
	void UDPok(Packet& packet);
	void TCPsendError(Packet& packet, char errorCode, const char* errorMsg);
	void UDPscreenState(Packet& packet, int score, std::list<Element>& elements); // elements pour idSprite et CoordSprite
	void UDPendOfGame(Packet& packet, int score);
	void UDPpause(Packet& packet);
	void UDPspawn(Packet& packet);
	void UPDdeath(Packet& packet);
	/* CLIENT TO SERVER */
	bool TCPsayHello(IReadableSocket& socket);
	bool TCPsetRoom(IReadableSocket& socket);
	bool TCPselectRoom(IReadableSocket& socket);
	bool TCPleaveRoom(IReadableSocket& socket);
	bool TCPchangeDifficulty(IReadableSocket& socket);
	bool TCPsetMap(IReadableSocket& socket);
	bool TCPgetFileTrunk(IReadableSocket& socket);
	bool TCPsetReady(IReadableSocket& socket);
	bool TCPdownloadRessource(IReadableSocket& socket);
	bool UDPReady(IReadableSocket& socket);
	bool TCPletsPlay(IReadableSocket& socket);
	bool TCPsaveMap(IReadableSocket& socket);
	bool UDPinputs(IReadableSocket& socket);
	bool UDPpauseOk(IReadableSocket& socket);
};
