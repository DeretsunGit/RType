//
// ServerCommunication.hpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#ifndef _WIN32
#include	<arpa/inet.h>
#endif
#include	<algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <map>
#include "IReadableSocket.h"
#include "IUDPSocketServer.h"
#include "Packet.hpp"
#include "Player.h"
#include "Opcodes.h"

#define HEADSIZE (sizeof(char) + sizeof(short)) // taille du "header" opcode + datasize

/* TCP BLOCK STRUCTURES DEFINITION */
struct s_say_hello
{
	char *nickname;
	char *magic;
	unsigned short resolution[2];
};

struct s_set_map
{
	bool status;
	char* filename;
};

struct s_file_trunk
{
	char* filename;
	unsigned int size;
	char* data;
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

class Room;
class Game;

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
		_commandMap[Opcodes::sayHello] = &ServerCommunication::TCPsayHello;
		_commandMap[Opcodes::askRoomList] = &ServerCommunication::TCProomListRequest;
		_commandMap[Opcodes::setRoom] = &ServerCommunication::TCPsetRoom;
		_commandMap[Opcodes::selectRoom] = &ServerCommunication::TCPselectRoom;
		_commandMap[Opcodes::leaveRoom] = &ServerCommunication::TCPleaveRoom;
		_commandMap[Opcodes::changeDifficulty] = &ServerCommunication::TCPchangeDifficulty;
		_commandMap[Opcodes::setMap] = &ServerCommunication::TCPsetMap;
		_commandMap[Opcodes::fileTrunk] = &ServerCommunication::TCPgetFileTrunk;
		_commandMap[Opcodes::setReady] = &ServerCommunication::TCPsetReady;
		_commandMap[Opcodes::downloadRsrc] = &ServerCommunication::TCPdownloadRessource;
		_commandMap[Opcodes::UDPReady] = &ServerCommunication::UDPReady;
		_commandMap[Opcodes::letsPlay] = &ServerCommunication::TCPletsPlay;
		_commandMap[Opcodes::saveMap] = &ServerCommunication::TCPsaveMap;
		_commandMap[Opcodes::inputs] = &ServerCommunication::UDPinputs;
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
		char opcode ;
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

	void interpretCommand(IUDPSocketServer& socket, const in_addr& addr)
	{
		this->interpretCommand(socket.getClient(addr));
	}


	/* SERVER TO CLIENT */
	void TCProomList(Packet& packet, std::list<Room *>& rooms); // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
	void TCProomState(Packet& packet, Room& room);
	void TCPwrongMap(Packet& packet);
	void TCPstartLoading(Packet& packet, unsigned short); //std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport); // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
	void TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size);
	void TCPassocSprites(Packet& packet, const char* filename, std::list<char>& idSprites, std::list<unsigned short[4]>& coords);
	void UDPok(Packet& packet);
	void TCPsendError(Packet& packet, char errorCode, const char* errorMsg);
	void UDPscreenState(Packet& packet, unsigned int score, std::list<Element>& elements); // elements pour idSprite et CoordSprite
	void UDPendOfGame(Packet& packet, unsigned int score);
	/* CLIENT TO SERVER */
	bool TCPsayHello(IReadableSocket& socket); // ok
	bool TCPsetRoom(IReadableSocket& socket); // ok
	bool TCPselectRoom(IReadableSocket& socket); // ok
	bool TCPleaveRoom(IReadableSocket& socket); //	ok	------- Gestion Macro des room finie
	bool TCPchangeDifficulty(IReadableSocket& socket); // ok
	bool TCPsetMap(IReadableSocket& socket); // wtf
	bool TCPgetFileTrunk(IReadableSocket& socket); // -
	bool TCPsetReady(IReadableSocket& socket); // ok
	bool TCPdownloadRessource(IReadableSocket& socket); // -
	bool UDPReady(IReadableSocket& socket); //
	bool TCPletsPlay(IReadableSocket& socket); //
	bool TCPsaveMap(IReadableSocket& socket); //-		--------Gestion Micro des room finie
	bool UDPinputs(IReadableSocket& socket);
	bool UDPpauseOk(IReadableSocket& socket);
	bool TCProomListRequest(IReadableSocket& socket);
};
