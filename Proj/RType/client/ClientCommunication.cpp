//
// ClientCommunication.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/client
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 15:05:51 2013 julien edmond
// Last update Sun Nov 10 20:23:29 2013 julien edmond
//

#include	<algorithm>
#include	<cstring>
/*#ifdef _WIN32
#include	<WinSock2.h>*/
#ifndef _WIN32
#include	<arpa/inet.h>
#endif
#include	"ClientCommunication.hpp"
#include	"rtype_common.h"

/* CLIENT TO SERVER */
template<typename T>
void ClientCommunication<T>::TCPsayHello(Packet& packet, const char* nickname, unsigned short resolution[2])
{
	char opcode = Opcodes::sayHello;
	unsigned short datasize = htons(sizeof("KOUKOU") + (32 * sizeof(char)) + (2 * (sizeof(unsigned short))));
	char nickname_to_write[32];
	unsigned short res[2] = {htons(resolution[0]), htons(resolution[1])};

	strncpy(nickname_to_write, nickname, 32);

	packet.reset();
	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short)); 
	packet.write("KOUKOU", sizeof("KOUKOU"));
	packet.write(nickname_to_write, 32 * sizeof(char));
	packet.write(reinterpret_cast<char*>(res), sizeof(res));
}

template<typename T>
void ClientCommunication<T>::TCPsetRoom(Packet& packet, const char* roomName)
{
	char opcode = Opcodes::setRoom;
	unsigned short datasize = htons(32 * sizeof(char));
	char name[32];

	strncpy(name, roomName, 32);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(name, 32 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPselectRoom(Packet& packet, const char roomId)
{
	char opcode = Opcodes::selectRoom;
	unsigned short datasize = htons(sizeof(char));
	
	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(&roomId, sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPleaveRoom(Packet& packet)
{
	char opcode = Opcodes::leaveRoom;
	unsigned short datasize = htons(0);

	packet.write(&opcode, sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPchangeDifficulty(Packet& packet, char difficulty)
{
	char opcode = Opcodes::changeDifficulty;
	unsigned short datasize = htons(sizeof(char));

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(&difficulty, sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPsetMap(Packet& packet, bool mapStatus, const char* filename)
{
	char opcode = Opcodes::setMap;
	unsigned short datasize = htons(sizeof(bool) + (128 * sizeof(char)));
	char name[128];

	strncpy(name, filename, 128);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(reinterpret_cast<char*>(&mapStatus), sizeof(bool));
	packet.write(name, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{
	char opcode = Opcodes::fileTrunk;
	unsigned short datasize = htons((32 * sizeof(char)) + (sizeof(unsigned int)) + (size * sizeof(char)));
	char name[32];

	strncpy(name, filename, 32);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(name, 32 * sizeof(char));
	packet.write(reinterpret_cast<char*>(&size), sizeof(unsigned int));
	packet.write(data, size * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPsetReady(Packet& packet)
{
	char opcode = Opcodes::setReady;
	unsigned short datasize = htons(0);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
}

template<typename T>
void ClientCommunication<T>::TCPdownloadRessource(Packet& packet, const char* filename)
{
	char opcode = Opcodes::downloadRsrc;
	unsigned short datasize = htons(128 * sizeof(char));
	char name[128];

	strncpy(name, filename, 128);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(name, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::UDPReady(Packet& packet)
{
	char opcode = Opcodes::UDPReady;
	unsigned short datasize = htons(0);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
}

template<typename T>
void ClientCommunication<T>::TCPletsPlay(Packet& packet)
{
	char opcode = Opcodes::letsPlay;
	unsigned short datasize = htons(0);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
}

template<typename T>
void ClientCommunication<T>::TCPsaveMap(Packet& packet, const char* mapName)
{
	char opcode = Opcodes::saveMap;
	unsigned short datasize = htons(128 * sizeof(char));
	char map[128];

	strncpy(map, mapName, 128);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(map, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::UDPinputs(Packet& packet, s_inputs& inputs)
{

}

template<typename T>
void ClientCommunication<T>::UDPpauseOk(Packet& packet)
{
}

/* SERVER TO CLIENT */
template<typename T>
bool ClientCommunication<T>::TCProomList(IReadableSocket& socket) const
{
  s_room_info block;
	unsigned short		dataSize;
	int		readsize;
	std::list<s_room_info>	ret;
	int		total(0);

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char *>(&dataSize), sizeof(dataSize))) != 2)
		{
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		while (total < htons(dataSize))
		{
			if ((readsize = socket.recv(block.name, 32)) != 32)
			{
				socket.putback(block.name, readsize);
				while (!ret.empty())
				{
				  socket.putback(reinterpret_cast<char*>(&ret.back()), sizeof(s_room_info));
				  ret.pop_back();
				}
				socket.putback(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
				return false;
			}
			total += readsize;
			if ((readsize = socket.recv(&block.id, 1)) != 1)
			{
				socket.putback(&block.id, readsize);
				socket.putback(block.name, 32);
				while (!ret.empty())
				{
				  socket.putback(reinterpret_cast<char*>(&ret.back()), sizeof(s_room_info));
				  ret.pop_back();
				}
				socket.putback(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
				return false;
			}
			total += readsize;
			if ((readsize = socket.recv(&block.nbPlayer, 1)) != 1)
			{
				socket.putback(&block.nbPlayer, readsize);
				socket.putback(&block.id, 1);
				socket.putback(block.name, 32);
				while (!ret.empty())
				{
				  socket.putback(reinterpret_cast<char*>(&ret.back()), sizeof(s_room_info));
				  ret.pop_back();
				}
				socket.putback(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
				return false;
			}
			total += readsize;
			ret.push_back(block);
		}
		(_handler->*_callableMap.at(Opcodes::roomList))(reinterpret_cast<void *>(&ret));
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCProomState(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::TCPwrongMap(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::TCPstartLoading(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::TCPassocSprites(IReadableSocket& socket) const
{
 	return true;
}

template<typename T>
bool ClientCommunication<T>::UDPok(IReadableSocket& socket) const
{
 	return true;
}

template<typename T>
bool ClientCommunication<T>::TCPsendError(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::UDPscreenState(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::UDPendOfGame(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::UDPpause(IReadableSocket& socket) const
{
		return true;
}

template<typename T>
bool ClientCommunication<T>::UDPspawn(IReadableSocket& socket) const
{
 	return true;
}

template<typename T>
bool ClientCommunication<T>::UPDdeath(IReadableSocket& socket) const
{
		return true;
}

