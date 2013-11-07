//
// ServerCommunication.cpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#include <cstring>
#include "ServerCommunication.h"

ServerCommunication::ServerCommunication()
{
	_commandMap[0x01] = &ServerCommunication::exempleOfDeserialisationFunction;
}

ServerCommunication::~ServerCommunication()
{
	;
}

template<typename Obj, typename Param>
void ServerCommunication::setCallback(char opcode, Obj& o, void (Obj::*mthd)(Param&))
{
	std::map<char, ICallable*>::iterator ite;

	if ((ite = _callableMap.find(opcode)) != __callableMap.end())
		_callableMap.erase(ite);
	map[opcode] = new MthdPtrBinder<Obj, Param>(o, mthd);
}

void	ServerCommunication::interpretCommand(IReadableSocket& socket) const
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

void ServerCommunication::exempleOfDeserialisationFunction(IReadableSocket& socket) const
{
	s_tmp tmp; // structure correspondant à chaque commande
	char* data;
	short datasize;
	int readSize = 0;

	if (socket.readable())
	{
		readSize += socket.recv(reinterpret_cast<char*>(datasize), 2);
		data = new char[datasize];
		readSize += socket.recv(data, datasize);
		if (readSize != datasize + 3)
			socket.putBack();
		else if (_callableMap.find(0x01) != _callableMap.end())
		{
			// déserialisation dans tmp
			tmp.tmp = true;
			_callableMap.at(0x01)->call(tmp);
		}
	}
}