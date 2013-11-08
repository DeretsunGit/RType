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
	    (_handler->*_callableMap[0x01])(&tmp);
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

  void	 interpretCommand(IReadableSocket& socket) const
  {
    typename CommandMap::const_iterator	ite;
    char				opcode;

    if (socket.readable())
      {
	socket.recv(&opcode, 1);
	if ((ite = _commandMap.find(opcode)) != _commandMap.end())
	  {
	    if ((this->*(ite->second))(socket) == false)
	      socket.putback(&opcode, 1);
	  }
	else if (_handler != NULL && _defaultCallback != NULL)
	  (_handler->*_defaultCallback)(opcode, socket);
      }
  }

  /* CLIENT TO SERVER */
  void TCPsayHello(Packet& packet, const char* nickname, short resolution[2])
  {}

  void TCPsetRoom(Packet& packet, const char* roomName)
  {}

  void TCPselectRoom(Packet& packet, const char roomId)
  {}

  void TCPleaveRoom(Packet& packet, const char roomId)
  {}

  void TCPchangeDifficulty(Packet& packet, bool difficulty)
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
