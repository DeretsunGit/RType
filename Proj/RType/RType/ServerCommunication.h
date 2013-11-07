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
//#include "IReadableSocket.h"
//#include "ICallable.h"
#include "Packet.hpp"
#include "Player.h"

// TMP
struct s_tmp
{
	bool tmp;
};
class IReadableSocket 
{
public:
	IReadableSocket();
	~IReadableSocket();
	bool readable();
	int recv(char* buff, int);
	void putBack();
};

class ICallable
{
public:
	ICallable();
	~ICallable();
	void call(s_tmp);
};

class ServerCommunication
{
private:
	std::map<char, void (ServerCommunication::*)(IReadableSocket& socket) const> _commandMap;
	std::map<char, ICallable*> _callableMap;

	void exempleOfDeserialisationFunction(IReadableSocket&) const;

public:
	ServerCommunication();
	~ServerCommunication();

	template<typename Obj, typename Param>
	void setCallback(char opcode, Obj& o, void (Obj::*mthd)(Param&));

	void interpretCommand(IReadableSocket&) const;
};