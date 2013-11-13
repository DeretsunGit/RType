#include <iostream>
#include "ServerCommunication.hpp"
#include "Room.h"


	/* SERVER TO CLIENT */
template<class T>
void ServerCommunication<T>::TCProomList(Packet& packet, std::list<Room *>& rooms) // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
{
	char opcode = Opcodes::roomList;
	unsigned short datasize = htons(static_cast<short>(rooms.size()) * (sizeof(char) * 34));
	char name[32], id = 0, nbplayer = 0;
	std::list<Room *>::const_iterator ite = rooms.begin();

	packet.reset();
	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));

	while (ite != rooms.end())
	{
//		if ((*ite)->getNbPlayer() != 0)
		{
			memset(name, 0, 32);
			strncpy(name, (*ite)->getName().c_str(), 32);
			id = (*ite)->getId();
			nbplayer = (*ite)->getNbPlayer();
			packet.write(name, 32 * sizeof(char));
			packet.write(&id, sizeof(char));
			packet.write(&nbplayer, sizeof(char));
			++ite;
		}
	}
}

template<class T>
void ServerCommunication<T>::TCProomState(Packet& packet, Room& room)
{
	char opcode = Opcodes::roomState;
	unsigned short datasize = htons(((32 + (4 * 32)) * sizeof(char)) + (4 * sizeof(bool)));
	char name[32];
	char players[4][32];
	std::vector<Player*>::const_iterator ite;
	int i = 0;

	strncpy(name, room.getName().c_str(), 32);
	
	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(short));
	packet.write(name, 32 * sizeof(char));

	ite = room.getPlayers().begin();
	while (ite != room.getPlayers().end() && i < 4)
	{
		strncpy(players[i], (*ite)->getName().c_str(), 32);
		++ite;
		++i;
	}
	while (i < 4)
	{
		players[i][0] = 0;
		++i;
	}
	packet.write(players[0], (4 * 32) * sizeof(char));
}

template<class T>
void ServerCommunication<T>::TCPwrongMap(Packet& packet)
{
	char opcode = Opcodes::wrongMap;
	unsigned short datasize = htons(0);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(short));
}

template<class T>
void ServerCommunication<T>::TCPstartLoading(Packet& packet, std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport) // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
{

}

template<class T>
void ServerCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{

}

template<class T>
void ServerCommunication<T>::TCPassocSprites(Packet& packet, const char* filename, std::list<char>& idSprites, std::list<short[4]>& coords)
{

}

template<class T>
void ServerCommunication<T>::UDPok(Packet& packet)
{

}

template<class T>
void ServerCommunication<T>::TCPsendError(Packet& packet, char errorCode, const char* errorMsg)
{

}

template<class T>
void ServerCommunication<T>::UDPscreenState(Packet& packet, unsigned int score, std::list<Element>& elements) // elements pour idSprite et CoordSprite
{

}

template<class T>
void ServerCommunication<T>::UDPendOfGame(Packet& packet, unsigned int score)
{

}

/* CLIENT TO SERVER */
template<class T>
bool ServerCommunication<T>::TCPsayHello(IReadableSocket& socket)
{ 
	s_say_hello block;
	char nickname[32];
	char magic[7];
	unsigned short resolution[2];
	unsigned int readsize;
	unsigned short dataSize;


	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char *>(&dataSize), sizeof(dataSize))) != 2)
		{
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		if ((readsize = socket.recv(magic, 7)) != 7)
		{
			socket.putback(magic, readsize);
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		if ((readsize = socket.recv(nickname, 32)) != 32)
		{
			socket.putback(nickname, readsize);
			socket.putback(magic, 7);
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		if ((readsize = socket.recv(reinterpret_cast<char*>(block.resolution), (2 * sizeof(unsigned short)))) != (2 * sizeof(unsigned short)))
		{
			socket.putback(reinterpret_cast<char*>(block.resolution), readsize);
			socket.putback(nickname, 32);
			socket.putback(magic, 7);
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		
//		block.nickname = ntohs(static_cast<char *>(nickname));
//		block.magic = ntohs(static_cast<char>(magic));
		block.nickname = nickname;//htons(static_cast<char *>(nickname));
		block.magic = magic;//htons(static_cast<char>(magic));
		block.resolution[0] = ntohs(block.resolution[0]);
		block.resolution[1] = ntohs(block.resolution[1]);
		(_handler->*_callableMap[Opcodes::sayHello])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetRoom(IReadableSocket& socket)
{
		return true;
}

template<class T>
bool ServerCommunication<T>::TCPselectRoom(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPleaveRoom(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPchangeDifficulty(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPsetMap(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPsetReady(IReadableSocket& socket)
{ 
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPdownloadRessource(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::UDPReady(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPletsPlay(IReadableSocket& socket)
{
		return true;

}

template<class T>
bool ServerCommunication<T>::TCPsaveMap(IReadableSocket& socket)
{ 
		return true;

}

template<class T>
bool ServerCommunication<T>::UDPinputs(IReadableSocket& socket)
{	
		return true;

}

template<class T>
bool ServerCommunication<T>::UDPpauseOk(IReadableSocket& socket)
{ 
		return true;

}
