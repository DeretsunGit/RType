#include <iostream>
#include "ServerCommunication.hpp"
#include "Room.h"
#include "SocketStack.h"


	/* SERVER TO CLIENT */
template<class T>
void ServerCommunication<T>::TCProomList(Packet& packet, std::list<Room *>& rooms) // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
{
	unsigned int opcode = htonl(Opcodes::roomList);
	unsigned short datasize = htons(static_cast<short>(rooms.size()) *  (sizeof(char) * 34));
	char name[32], id = 0, nbplayer = 0;
	int i = 0;
	std::list<Room *>::const_iterator ite = rooms.begin();

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));

	while (ite != rooms.end() && i < 5)
	{
//		if ((*ite)->getNbPlayer() != 0)
//		{
			memset(name, 0, 32);
			strncpy(name, (*ite)->getName().c_str(), 31);
			id = (*ite)->getId();
			nbplayer = (*ite)->getNbPlayer();
			packet.write(name, 32 * sizeof(char));
			packet.write(&id, sizeof(char));
			packet.write(&nbplayer, sizeof(char));
			++ite;
//		}
	}
}

template<class T>
void ServerCommunication<T>::TCProomState(Packet& packet, Room& room)
{
	unsigned int opcode = htonl(Opcodes::roomState);
	unsigned short datasize = htons(((32 + (4 * 32)) * sizeof(char)) + (4 * sizeof(bool)));
	char name[32];
	char players[4][32];
	std::vector<Player*>::const_iterator ite;
	int i = 0;

	strncpy(name, room.getName().c_str(), 32);

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
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
	unsigned int opcode = htonl(Opcodes::wrongMap);
	unsigned short datasize = htons(0);

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(short));
}

template<class T>
void ServerCommunication<T>::TCPstartLoading(Packet& packet, unsigned short UDPport)//std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport) // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
{
	unsigned int opcode = htonl(Opcodes::startLoading);
	unsigned short datasize = htons((sizeof(unsigned short)));// + (static_cast<unsigned short>(filenames.size()) * (160 * sizeof(char))));
	unsigned short udp_to_send = htons(UDPport);
//	char name[128], md5_to_cpy[32];
//	std::list<std::string>::const_iterator f_ite = filenames.begin();
//	std::list<std::string>::const_iterator m_ite = md5.begin();

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(reinterpret_cast<char*>(&udp_to_send), sizeof(unsigned short));

/*	while (f_ite != filenames.end() && m_ite != md5.end())
	{
		memset(name, 0, 128);
		memset(md5_to_cpy, 0, 128);
		strncpy(name, f_ite->c_str(), 128);
		strncpy(md5_to_cpy, m_ite->c_str(), 32);
		packet.write(name, 128 * sizeof(char));
		packet.write(md5_to_cpy, 32 * sizeof(char));
		++f_ite;
		++m_ite;
	}
	*/
}

template<class T>
void ServerCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{
	unsigned int opcode = htonl(Opcodes::fileTrunk);
  unsigned short datasize = htons((32 * sizeof(char)) + (sizeof(unsigned int)) + (static_cast<unsigned short>(size) * sizeof(char)));
  char name[32];

  strncpy(name, filename, 32);
  packet.reset();

  packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(name, 32 * sizeof(char));
  packet.write(reinterpret_cast<char*>(&size), sizeof(unsigned int));
  packet.write(data, static_cast<unsigned short>(size) * sizeof(char));
}

template<class T>
void ServerCommunication<T>::TCPassocSprites(Packet& packet, const char* filename, std::list<char>& idSprites, std::list<unsigned short[4]>& coords)
{
	unsigned int opcode = htonl(Opcodes::assocSprite);
	unsigned short datasize = htons((32 * sizeof(char)) + (static_cast<unsigned short>(idSprites.size()) * (sizeof(char) + (sizeof(unsigned short) * 4))));
	char name[32], id;
	unsigned short coord[4];
	std::list<char>::const_iterator s_ite = idSprites.begin();
	std::list<unsigned short[4]>::const_iterator c_ite = coords.begin();

	memset(name, 0, 32);
	packet.reset();
	strncpy(name, filename, 32);
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(name, 32 * sizeof(char));
	while (s_ite != idSprites.end() && c_ite != coords.end())
	{
		coord[0] = htons((*c_ite)[0]);
		coord[1] = htons((*c_ite)[1]);
		coord[2] = htons((*c_ite)[2]);
		coord[3] = htons((*c_ite)[3]);
		id = (*s_ite);
		packet.write(&id, sizeof(char));
		packet.write(reinterpret_cast<char*>(coord), 4 * sizeof(unsigned short));
		++s_ite;
		++c_ite;
	}
}

template<class T>
void ServerCommunication<T>::UDPok(Packet& packet)
{
	unsigned int opcode = htonl(Opcodes::UDPOkay);
	unsigned short datasize = htons(0);

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
}

template<class T>
void ServerCommunication<T>::TCPsendError(Packet& packet, char errorCode, const char* errorMsg)
{
	unsigned int opcode = htonl(Opcodes::sendError);
	unsigned short datasize = htons(sizeof(char) * 257);
	char msg[256];

	memset(msg, 0, 256);
	strncpy(msg, errorMsg, 256);

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(&errorCode, sizeof(char));
	packet.write(msg, 256 * sizeof(char));
}

template<class T>
void ServerCommunication<T>::UDPscreenState(Packet& packet, unsigned int score, std::list<Element*>& elements) // elements pour idSprite et CoordSprite
{
  unsigned int opcode = htonl(Opcodes::screenState);
  unsigned short datasize = htons(sizeof(unsigned int) + (static_cast<unsigned short>(elements.size()) * (sizeof(unsigned int) + sizeof(t_coord))));
  unsigned int score_to_send = htonl(score);
  unsigned int id = 24;
  t_coord coord;
  std::list<Element*>::const_iterator ite = elements.begin();

  packet.reset();
  packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(reinterpret_cast<char*>(&score_to_send), sizeof(unsigned int));
  while (ite != elements.end())
    {
      id = htonl((*ite)->getSprite().front());
      coord._posX = htons((*ite)->getPos()._posX);
      coord._posY = htons((*ite)->getPos()._posY);
      packet.write(reinterpret_cast<char*>(&id), sizeof(unsigned int));
      packet.write(reinterpret_cast<char*>(&coord), sizeof(t_coord));
      ++ite;
    }
}

template<class T>
void ServerCommunication<T>::UDPendOfGame(Packet& packet, unsigned int score)
{
	unsigned int opcode = htonl(Opcodes::endOfGame);
	unsigned short datasize = htons(sizeof(unsigned int));
	unsigned int score_to_send = htonl(score);

	packet.reset();
	packet.write(reinterpret_cast<char*>(&opcode), sizeof(unsigned int));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
	packet.write(reinterpret_cast<char*>(&score_to_send), sizeof(unsigned int));
}

/* CLIENT TO SERVER */
template<class T>
bool ServerCommunication<T>::TCPsayHello(IReadableSocket& socket)
{
	s_say_hello block;
	char nickname[32];
	char magic[7];
	unsigned int readsize;
	unsigned short dataSize;
	SocketStack stack;


	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char *>(&dataSize), sizeof(dataSize))) != 2)
		{
			socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
			return false;
		}
		stack.push(dataSize);
		if ((readsize = socket.recv(magic, 7)) != 7)
		{
			socket.putback(magic, readsize);
			stack.put_back(socket);
			return false;
		}
		stack.push(magic);
		if ((readsize = socket.recv(nickname, 32)) != 32)
		{
			socket.putback(nickname, readsize);
			stack.put_back(socket);
			return false;
		}
		stack.push(nickname);
		if ((readsize = socket.recv(reinterpret_cast<char*>(block.resolution), (2 * sizeof(unsigned short)))) != (2 * sizeof(unsigned short)))
		{
			socket.putback(reinterpret_cast<char*>(block.resolution), readsize);
			stack.put_back(socket);
			return false;
		}
		block.nickname = nickname;
		block.magic = magic;
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
	unsigned short datasize;
	unsigned int readsize;
	char name[32];

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		if ((readsize = socket.recv(name, 32)) != 32)
		{
			socket.putback(name, readsize);
			socket.putback(reinterpret_cast<char*>(&datasize), 2);
			return false;
		}
		(_handler->*_callableMap[Opcodes::setRoom])(name);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPselectRoom(IReadableSocket& socket)
{
	unsigned short datasize;
	unsigned int readsize;
	char id;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		if ((readsize = socket.recv(&id, 1)) != 1)
		{
			socket.putback(&id, readsize);
			socket.putback(reinterpret_cast<char*>(&datasize), 2);
			return false;
		}
		std::cout << "I select a room" << std::endl;
		(_handler->*_callableMap[Opcodes::selectRoom])(&id);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPleaveRoom(IReadableSocket& socket)
{
	unsigned int readsize;
	unsigned short datasize;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		(_handler->*_callableMap[Opcodes::leaveRoom])(NULL);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPchangeDifficulty(IReadableSocket& socket)
{
	unsigned short datasize;
	unsigned int readsize;
	char difficulty;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		if ((readsize = socket.recv(&difficulty, 1)) != 1)
		{
			socket.putback(&difficulty, readsize);
			socket.putback(reinterpret_cast<char*>(&datasize), 2);
			return false;
		}
		(_handler->*_callableMap[Opcodes::changeDifficulty])(&difficulty);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetMap(IReadableSocket& socket)
{
	s_set_map block;
	unsigned short datasize;
	unsigned int readsize;
	bool status;
	char file[128];
	SocketStack stack;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		stack.push(datasize);
		if ((readsize = socket.recv(reinterpret_cast<char*>(&status), 1)) != 1)
		{
			socket.putback(reinterpret_cast<char*>(&status), readsize);
			stack.put_back(socket);
			return false;
		}
		stack.push(status);
		if ((readsize = socket.recv(file, 128)) != 128)
		{
			socket.putback(file, readsize);
			stack.put_back(socket);
			return false;
		}

		block.filename = file;
		block.status = status;
		(_handler->*_callableMap[Opcodes::changeDifficulty])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket)
{
	s_file_trunk block;
	unsigned short datasize;
	unsigned int readsize;
	unsigned int size;
	char file[32];
	char data[1024];
	SocketStack stack;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		stack.push(datasize);
		if ((readsize = socket.recv(file, 32)) != 32)
		{
			socket.putback(file, readsize);
			stack.put_back(socket);
			return false;
		}
		stack.push(file);
		if ((readsize = socket.recv(reinterpret_cast<char*>(&size), sizeof(size))) != sizeof(size))
		{
			socket.putback(reinterpret_cast<char*>(&size), readsize);
			stack.put_back(socket);
			return false;
		}
		stack.push(size);
		if ((readsize = socket.recv(reinterpret_cast<char*>(data), htonl(size))) != htonl(size))
		{
			socket.putback(data, readsize);
			stack.put_back(socket);
			return false;
		}

		block.data = data;
		block.filename = file;
		block.size = ntohl(size);
		(_handler->*_callableMap[Opcodes::fileTrunk])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetReady(IReadableSocket& socket)
{
	unsigned int readsize;
	unsigned short datasize;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		(_handler->*_callableMap[Opcodes::setReady])(NULL);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPdownloadRessource(IReadableSocket& socket)
{
	unsigned short datasize;
	unsigned int readsize;
	char file[128];

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		if ((readsize = socket.recv(file, 128)) != 128)
		{
			socket.putback(file, readsize);
			socket.putback(reinterpret_cast<char*>(&datasize), 2);
			return false;
		}
		(_handler->*_callableMap[Opcodes::downloadRsrc])(file);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPReady(IReadableSocket& socket)
{
  unsigned int readsize;
  unsigned short datasize;
  char		nickname[32];
  s_udp_ready	sent;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      if ((readsize = socket.recv(nickname, 32)) != 32)
	{
	  socket.putback(nickname, readsize);
	  return false;
	}
      sent.from = this->from;
      sent.nickname = nickname;
      (_handler->*_callableMap[Opcodes::UDPReady])(&sent);
      return true;
    }
  return false;
}

template<class T>
bool ServerCommunication<T>::TCPletsPlay(IReadableSocket& socket)
{
	unsigned int readsize;
	unsigned short datasize;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		(_handler->*_callableMap[Opcodes::letsPlay])(NULL);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsaveMap(IReadableSocket& socket)
{
	unsigned short datasize;
	unsigned int readsize;
	char map[128];

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		if ((readsize = socket.recv(map, 128)) != 128)
		{
			socket.putback(map, readsize);
			socket.putback(reinterpret_cast<char*>(&datasize), 2);
			return false;
		}
		(_handler->*_callableMap[Opcodes::saveMap])(map);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPinputs(IReadableSocket& socket)
{
  unsigned short datasize;
  unsigned int readsize;
  s_inputs in;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      if ((readsize = socket.recv(reinterpret_cast<char*>(&in), sizeof(in))) != sizeof(in))
	{
	  socket.putback(reinterpret_cast<char*>(&in), readsize);
	  socket.putback(reinterpret_cast<char*>(&datasize), 2);
	  return false;
	}
      in.from = this->from;
      (_handler->*_callableMap[Opcodes::inputs])(&in);
      return true;
    }
  return false;
}

template<class T>
bool ServerCommunication<T>::TCProomListRequest(IReadableSocket& socket)
{
	unsigned int readsize;
	unsigned short datasize;

	if (socket.readable())
	{
		if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
		{
			socket.putback(reinterpret_cast<char*>(&datasize), readsize);
			return false;
		}
		(_handler->*_callableMap[Opcodes::askRoomList])(NULL);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPpauseOk(IReadableSocket& socket)
{
	return true;
}
