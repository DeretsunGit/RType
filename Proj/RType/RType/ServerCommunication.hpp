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
//#include "ICallable.h"
#include "Packet.hpp"
#include "Player.h"

// TMP
struct s_tmp
{
	bool tmp;
};

template<typename T>
class ServerCommunication
{
private:
	std::map<char, void (ServerCommunication::*)(IReadableSocket& socket) const> _commandMap;
	std::map<char, void (T::*)(void*)> _callableMap;

	T* _handler;

	// RETOURNE BOOL SI FALSE RENVOI OPCODE SOCKET.PUTBACK !!
	void exempleOfDeserialisationFunction(IReadableSocket&)
	{
		s_tmp tmp; // structure correspondant à chaque commande
		char* data;
		short datasize;
		int readSize = 0;

		if (socket.readable())
		{
			readSize += socket.recv(reinterpret_cast<char*>(&datasize), 2);
			if (readSize != 2)
			{
				socket.putback(reinterpret_cast<char*>(&datasize), readSize);
				return ;
			}
			data = new char[datasize];
			readSize += socket.recv(data, datasize);
			if (readSize != datasize + 2)
			{
				socket.putback(reinterpret_cast<char*>(&datasize), 2);
				socket.putback(data, readSize -2);
				return ;
			}
			else if (!_handler && _callableMap.find(0x01) != _callableMap.end())
			{
				// déserialisation dans tmp
				tmp.tmp = true;
				(_handler->*_callableMap[0x01])(&tmp);
			}
		}
	}

public:
	ServerCommunication()
	{
		_handler = NULL;
		_commandMap[0x01] = &ServerCommunication::exempleOfDeserialisationFunction;
	}

	~ServerCommunication() {}

	void setCallback(char opcode, void (T::*mthd)(void* data))
	{
		map[opcode] = mthd;
	}

	void setHandler(T* handler)
	{
		this->_handler = handler;
	}

	void interpretCommand(IReadableSocket&) const
	{
		std::map<char, void (ServerCommunication::*)(IReadableSocket&) const>::const_iterator ite;
		char opcode;

		if (socket.readable())
		{
			socket.recv(&opcode, 1);
			if ((ite = _commandMap.find(opcode)) != _commandMap.end())
				(this->*(ite->second))(socket);
		}
	}
};