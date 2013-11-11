#include "ServerCommunication.hpp"
#include "Room.h"

	/* SERVER TO CLIENT */
template<class T>
void ServerCommunication<T>::TCProomList(Packet& packet, std::list<Room *>& rooms) // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
{

}

template<class T>
void ServerCommunication<T>::TCProomState(Packet& packet, Room& room)
{

}

template<class T>
void ServerCommunication<T>::TCPwrongMap(Packet& packet)
{

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
	unsigned int readsize;

	if (socket.readable())
	{
		if ((readsize = socket.recv(nickname, 32)) != 32)
		{
			socket.putback(nickname, readsize);
			return false;
		}
		if ((readsize = socket.recv(magic, 7)) != 7)
		{
			socket.putback(magic, readsize);
			socket.putback(nickname, 32);
			return false;
		}
		if ((readsize = socket.recv(reinterpret_cast<char*>(&block.resolution), (2 * sizeof(unsigned short)))) != (2 * sizeof(unsigned short)))
		{
			socket.putback(reinterpret_cast<char*>(&block.resolution), readsize);
			socket.putback(magic, 7);
			socket.putback(nickname, 32);
			return false;
		}
		block.nickname = nickname;
		block.magic = magic;
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
