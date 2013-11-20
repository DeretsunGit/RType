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
#include "Opcodes.h"

#define HEADSIZE (sizeof(char) + sizeof(short)) // taille du "header" opcode + datasize

template<unsigned int size, typename T = char>
struct Buffer
{
	Buffer()
	{}

	Buffer(const Buffer& b)
	{
		memcpy(_buff, b._buff, size);
	}

	Buffer(const T* arr)
	{
		memcpy(_buff, arr, size);
	}

	~Buffer()
	{

	}

	Buffer&	operator=(const Buffer&)
	{
		memcpy(_buff, _buff, size);
	}

	T	_buff[size];
};

/* TCP BLOCK STRUCTURES DEFINITION */
struct s_room_info
{
	char name[32];
	char id;
	char nbPlayer;
};

struct s_room_state_info
{
	char* name;
	char players[4][32];
	bool playerState[4];
};

struct s_start_loading
{
	unsigned short udp;
//	std::list<std::pair<Buffer<128>, Buffer<32> > > files;
};

struct s_shorts
{
	unsigned short _v1;
	unsigned short _v2;
	unsigned short _v3;
	unsigned short _v4;
};

struct s_assoc_sprite
{
	char* file;
	std::list<std::pair<char, s_shorts> > sprites;
};

struct s_file_trunk
{
	char* file;
	unsigned int size;
	char* data;
};

struct s_error
{
	char code;
	char* msg;
};

struct s_screen_state
{
	unsigned int score;
	std::list<std::pair<u_long, t_coord> > elements;
};

struct s_inputs
{
  // TODO
  unsigned short  x;
  unsigned short  y;
  char		  fire;
  char		  shield;
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

public:
	ClientCommunication()
	{
		_handler = NULL;
		_defaultCallback = NULL;
		_commandMap[Opcodes::roomList] = &ClientCommunication::TCProomList;
		_commandMap[Opcodes::roomState] = &ClientCommunication::TCProomState;
		_commandMap[Opcodes::wrongMap] = &ClientCommunication::TCPwrongMap;
		_commandMap[Opcodes::startLoading] = &ClientCommunication::TCPstartLoading;
		_commandMap[Opcodes::fileTrunk] = &ClientCommunication::TCPgetFileTrunk;
		_commandMap[Opcodes::assocSprite] = &ClientCommunication::TCPassocSprites;
		_commandMap[Opcodes::UDPOkay] = &ClientCommunication::UDPok;
		_commandMap[Opcodes::sendError] = &ClientCommunication::TCPsendError;
		_commandMap[Opcodes::screenState] = &ClientCommunication::UDPscreenState;
		_commandMap[Opcodes::endOfGame] = &ClientCommunication::UDPendOfGame;
	}

	~ClientCommunication() {}

	void setCallback(char opcode, void (T::*mthd)(void* data))
	{
	  _callableMap[opcode] = mthd;
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
	  typename CommandMap::const_iterator ite;
	  char opcode;

	  if (socket.readable())
	  {
	      socket.recv(&opcode, 1);
	      if ((ite = _commandMap.find(opcode)) != _commandMap.end()
		  && _callableMap.find(opcode) != _callableMap.end())
	      {
		      if ((this->*(ite->second))(socket) == false)
			      socket.putback(&opcode, 1);
	      }
	      else if (_handler != NULL && _defaultCallback != NULL)
		(this->_handler->*_defaultCallback)(opcode, socket);
	  }
	}

	/* CLIENT TO SERVER */
  void TCPsayHello(Packet& packet, const char* nickname, unsigned short resolution[2]);
  void TCPaskRoomList(Packet& packet);
  void TCPsetRoom(Packet& packet, const char* roomName);
  void TCPselectRoom(Packet& packet, const char roomId);
  void TCPleaveRoom(Packet& packet);
  void TCPchangeDifficulty(Packet& packet, char difficulty);
  void TCPsetMap(Packet& packet, bool mapStatus, const char* filename);
  void TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size);
  void TCPsetReady(Packet& packet);
  void TCPdownloadRessource(Packet& packet, const char* filename);
  void UDPReady(Packet& packet, const char *);
  void TCPletsPlay(Packet& packet);
  void TCPsaveMap(Packet& packet, const char* mapName);
  void UDPinputs(Packet& packet, s_inputs& inputs);
  void UDPpauseOk(Packet& packet);


  /* SERVER TO CLIENT */
  bool TCProomList(IReadableSocket& socket) const;
  bool TCProomState(IReadableSocket& socket) const;
  bool TCPwrongMap(IReadableSocket& socket) const;
  bool TCPstartLoading(IReadableSocket& socket) const;
  bool TCPgetFileTrunk(IReadableSocket& socket) const;
  bool TCPassocSprites(IReadableSocket& socket) const;
  bool UDPok(IReadableSocket& socket) const;
  bool TCPsendError(IReadableSocket& socket) const;
  bool UDPscreenState(IReadableSocket& socket) const;
  bool UDPendOfGame(IReadableSocket& socket) const;
  bool UDPpause(IReadableSocket& socket) const;
  bool UDPspawn(IReadableSocket& socket) const;
  bool UPDdeath(IReadableSocket& socket) const;
};
