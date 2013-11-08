//
// ClientCommunication.hpp for RType
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
#include "Player.h"

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

template<typename T>
class ClientCommunication
{
private:
  typedef bool	(ClientCommunication::*Command)(IReadableSocket&) const;
  typedef std::map<char, Command>	CommandMap;

  CommandMap _commandMap;
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
	    (_handler->*_callableMap[0x01])(tmp);
	  }
      }
    return true;
  }

public:
	ClientCommunication()
	{
		_handler = NULL;
		_defaultCallback = NULL;
		_commandMap[0x00] = &ClientCommunication::TCProomList;
		_commandMap[0x00] = &ClientCommunication::TCProomState;
		_commandMap[0x00] = &ClientCommunication::TCPwrongMap;
		_commandMap[0x00] = &ClientCommunication::TCPstartLoading;
		_commandMap[0x00] = &ClientCommunication::TCPgetFileTrunk;
		_commandMap[0x00] = &ClientCommunication::TCPassocSprites;
		_commandMap[0x00] = &ClientCommunication::UDPok;
		_commandMap[0x00] = &ClientCommunication::TCPsendError;
		_commandMap[0x00] = &ClientCommunication::UDPscreenState;
		_commandMap[0x00] = &ClientCommunication::UDPendOfGame;
		_commandMap[0x00] = &ClientCommunication::UDPpause;
		_commandMap[0x00] = &ClientCommunication::UDPspawn;
		_commandMap[0x00] = &ClientCommunication::UPDdeath;
	}

	~ClientCommunication() {}

	void setCallback(char opcode, void (T::*mthd)(void* data))
	{
		map[opcode] = mthd;
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
		typename std::map<char, void (ClientCommunication::*)(IReadableSocket&) const>::const_iterator ite;
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

	/* CLIENT TO SERVER */
	void TCPsayHello(Packet& packet, const char* nickname, short resolution[2])
	{}

	void TCPsetRoom(Packet& packet, const char* roomName)
	{}

	void TCPselectRoom(Packet& packet, const char roomId)
	{}

	void TCPleaveRoom(Packet& packet)
	{}

	void TCPchangeDifficulty(Packet& packet, char difficulty)
	{}

	void TCPsetMap(Packet& packet, bool mapStatus, const char* filename, const char* fileContent)
	{}
	
	void TCPsendFileTrunk(Packet& packet, const char* filename, const char* data)
	{}

	void TCPsetReady(Packet& packet)
	{}

	void TCPdownloadRessource(Packet& packet, const char* filename)
	{}

	void UDPReady(Packet& packet)
	{}

	void TCPletsPlay(Packet& packet)
	{}

	void TCPsaveMap(Packet& packet, const char* mapName)
	{}

	void UDPinputs(Packet& packet, s_inputs& inputs)
	{}

	void UDPpauseOk(Packet& packet)
	{}

	/* SERVER TO CLIENT */
	bool TCProomList(IReadableSocket& socket) const
	{
		return true;
	}

	bool TCProomState(IReadableSocket& socket) const
	{
		return true;
	}

	bool TCPwrongMap(IReadableSocket& socket) const
	{
		return true;
	}

	bool TCPstartLoading(IReadableSocket& socket) const
	{
		return true;
	}

	bool TCPgetFileTrunk(IReadableSocket& socket) const
	{
		return true;
	}
	
	bool TCPassocSprites(IReadableSocket& socket) const
	{
		return true;
	}

	bool UDPok(IReadableSocket& socket) const
	{
		return true;
	}

	bool TCPsendError(IReadableSocket& socket) const
	{
		return true;
	}

	bool UDPscreenState(IReadableSocket& socket) const
	{
		return true;
	}

	bool UDPendOfGame(IReadableSocket& socket) const
	{
		return true;
	}

	bool UDPpause(IReadableSocket& socket) const
	{
		return true;
	}

	bool UDPspawn(IReadableSocket& socket) const
	{
		return true;
	}

	bool UPDdeath(IReadableSocket& socket) const
	{
		return true;
	}
};
