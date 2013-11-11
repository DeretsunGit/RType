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
#ifdef _WIN32
#include	<WinSock2.h>
#else
#include	<arpa/inet.h>
#endif
#include	"ClientCommunication.hpp"
#include	"rtype_common.h"

/* CLIENT TO SERVER */
template<typename T>
void ClientCommunication<T>::TCPsayHello(Packet& packet, const char* nickname, unsigned short resolution[2])
{
	char opcode = Opcodes::sayHello;
	unsigned short datasize = htons((32 * sizeof(char)) + (2 * (sizeof(unsigned short))));
	char nickname_to_write[32];

	strncpy(nickname_to_write, nickname, 32);

	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(nickname_to_write, 32);
	packet.write(reinterpret_cast<char*>(&resolution), 2 * (sizeof(unsigned short)));
}

template<typename T>
void ClientCommunication<T>::TCPsetRoom(Packet& packet, const char* roomName)
{

}

template<typename T>
void ClientCommunication<T>::TCPselectRoom(Packet& packet, const char roomId)
{

}

template<typename T>
void ClientCommunication<T>::TCPleaveRoom(Packet& packet)
{

}

template<typename T>
void ClientCommunication<T>::TCPchangeDifficulty(Packet& packet, char difficulty)
{

}

template<typename T>
void ClientCommunication<T>::TCPsetMap(Packet& packet, bool mapStatus, const char* filename)
{
 
}

template<typename T>
void ClientCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{

}

template<typename T>
void ClientCommunication<T>::TCPsetReady(Packet& packet)
{

}

template<typename T>
void ClientCommunication<T>::TCPdownloadRessource(Packet& packet, const char* filename)
{

}

template<typename T>
void ClientCommunication<T>::UDPReady(Packet& packet)
{
 
}

template<typename T>
void ClientCommunication<T>::TCPletsPlay(Packet& packet)
{

}

template<typename T>
void ClientCommunication<T>::TCPsaveMap(Packet& packet, const char* mapName)
{

}

/*template<typename T>
void ClientCommunication<T>::UDPinputs(Packet& packet, s_inputs& inputs)
{

}*/

template<typename T>
void ClientCommunication<T>::UDPpauseOk(Packet& packet)
{

}

/* SERVER TO CLIENT */
template<typename T>
bool ClientCommunication<T>::TCProomList(IReadableSocket& socket) const
{
	return true;
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
