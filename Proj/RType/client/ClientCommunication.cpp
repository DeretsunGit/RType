//
// ClientCommunication.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/client
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 15:05:51 2013 julien edmond
// Last update Wed Nov 20 10:49:35 2013 julien edmond
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
#include	"SocketStack.h"

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
void ClientCommunication<T>::TCPaskRoomList(Packet& packet)
{
	char opcode = Opcodes::askRoomList;
	unsigned short datasize = htons(0);

	packet.reset();
	packet.write(&opcode, sizeof(char));
	packet.write(reinterpret_cast<char*>(&datasize), sizeof(datasize));
}

template<typename T>
void ClientCommunication<T>::TCPsetRoom(Packet& packet, const char* roomName)
{
  char opcode = Opcodes::setRoom;
  unsigned short datasize = htons(32 * sizeof(char));
  char name[32];

  strncpy(name, roomName, 32);

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(name, 32 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPselectRoom(Packet& packet, const char roomId)
{
  char opcode = Opcodes::selectRoom;
  unsigned short datasize = htons(sizeof(char));

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(&roomId, sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPleaveRoom(Packet& packet)
{
  char opcode = Opcodes::leaveRoom;
  unsigned short datasize = htons(0);

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
}

template<typename T>
void ClientCommunication<T>::TCPchangeDifficulty(Packet& packet, char difficulty)
{
  char opcode = Opcodes::changeDifficulty;
  unsigned short datasize = htons(sizeof(char));
  packet.reset();
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

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(reinterpret_cast<char*>(&mapStatus), sizeof(bool));
  packet.write(name, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{
  char opcode = Opcodes::fileTrunk;
  unsigned short datasize = htons((32 * sizeof(char)) + (sizeof(unsigned int)) + (static_cast<unsigned short>(size) * sizeof(char)));
  char name[32];

  strncpy(name, filename, 32);
  packet.reset();

  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(name, 32 * sizeof(char));
  packet.write(reinterpret_cast<char*>(&size), sizeof(unsigned int));
  packet.write(data, static_cast<unsigned short>(size) * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::TCPsetReady(Packet& packet)
{
  char opcode = Opcodes::setReady;
  unsigned short datasize = htons(0);

  packet.reset();
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

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(name, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::UDPReady(Packet& packet, const char *nickname)
{
  char opcode = Opcodes::UDPReady;
  unsigned short datasize = htons(32 * sizeof(char));
  char nickname_to_write[32];

  strncpy(nickname_to_write, nickname, 32);

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(nickname_to_write, 32 * sizeof(char));

}

template<typename T>
void ClientCommunication<T>::TCPletsPlay(Packet& packet)
{
  char opcode = Opcodes::letsPlay;
  unsigned short datasize = htons(0);

  packet.reset();
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

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(map, 128 * sizeof(char));
}

template<typename T>
void ClientCommunication<T>::UDPinputs(Packet& packet, s_inputs& inputs)
{
  char opcode = Opcodes::inputs;
  unsigned short datasize = htons(sizeof(s_inputs));
  s_inputs in;

  in.fire = inputs.fire;
  in.shield = inputs.shield;
  in.x = htons(inputs.x);
  in.y = htons(inputs.y);

  packet.reset();
  packet.write(&opcode, sizeof(char));
  packet.write(reinterpret_cast<char*>(&datasize), sizeof(unsigned short));
  packet.write(reinterpret_cast<char*>(&in), sizeof(s_inputs));
}

template<typename T>
void ClientCommunication<T>::UDPpauseOk(Packet& packet)
{
}

/* SERVER TO CLIENT */
template<typename T>
bool ClientCommunication<T>::TCProomList(IReadableSocket& socket) const
{
  unsigned short		dataSize;
  int		readsize;
  std::list<s_room_info>	ret;
  int		total(0);
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char *>(&dataSize), sizeof(dataSize))) != 2)
	{
	  socket.putback(reinterpret_cast<char *>(&dataSize), readsize);
	  return false;
	}
      stack.push(dataSize);
      while (total < ntohs(dataSize))
	{
	  ret.push_back(s_room_info());
	  if ((readsize = socket.recv(ret.back().name, 32)) != 32)
	    {
	      socket.putback(ret.back().name, readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(ret.back().name, 32);
	  total += readsize;
	  if ((readsize = socket.recv(&ret.back().id, 1)) != 1)
	    {
	      socket.putback(&ret.back().id, readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(ret.back().id);
	  total += readsize;
	  if ((readsize = socket.recv(&ret.back().nbPlayer, 1)) != 1)
	    {
	      socket.putback(&ret.back().nbPlayer, readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(ret.back().nbPlayer);
	  total += readsize;
	}
      (_handler->*_callableMap.at(Opcodes::roomList))(reinterpret_cast<void *>(&ret));
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCProomState(IReadableSocket& socket) const
{
  s_room_state_info block;
  unsigned short	datasize;
  unsigned int	readsize;
  char name[32];
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char *>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char *>(&datasize), readsize);
	  return false;
	}
      stack.push(datasize);
      if ((readsize = socket.recv(name, 32)) != 32)
	{
	  socket.putback(name, readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(name);
      if ((readsize = socket.recv(reinterpret_cast<char*>(block.players), sizeof(block.players))) != sizeof(block.players))
	{
	  socket.putback(reinterpret_cast<char*>(block.players), readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(block.players);
      if ((readsize = socket.recv(reinterpret_cast<char*>(block.playerState), sizeof(block.playerState))) != sizeof(block.playerState))
	{
	  socket.putback(reinterpret_cast<char*>(block.playerState), readsize);
	  stack.put_back(socket);
	  return false;
	}
      block.name = name;
      (_handler->*_callableMap.at(Opcodes::roomState))(reinterpret_cast<void *>(&block));
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCPwrongMap(IReadableSocket& socket) const
{
  unsigned short datasize;
  unsigned int readsize;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      (_handler->*_callableMap.at(Opcodes::wrongMap))(NULL);
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCPstartLoading(IReadableSocket& socket) const
{
  s_start_loading block;
  unsigned short datasize;
  unsigned int readsize, total;
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      stack.push(datasize);
      if ((readsize = socket.recv(reinterpret_cast<char*>(&(block.udp)), sizeof(block.udp))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&(block.udp)), readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(block.udp);
      total = readsize;
     /* while (total != ntohs(datasize) - sizeof(block.udp))
	{
	  block.files.push_back(std::pair<Buffer<128>, Buffer<32> >());
	  if ((readsize = socket.recv(block.files.back().first._buff, 128)) != 128)
	    {
	      socket.putback(block.files.back().first._buff, readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.files.back().first._buff);
	  total += readsize;
	  if ((readsize = socket.recv(block.files.back().second._buff, 32)) != 32)
	    {
	      socket.putback(block.files.back().second._buff, readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.files.back().second._buff);
	  total += readsize;
	}*/
      block.udp = ntohs(block.udp);
      (_handler->*_callableMap.at(Opcodes::startLoading))(reinterpret_cast<void*>(&block));
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket) const
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
      if ((readsize = socket.recv(reinterpret_cast<char*>(data), ntohl(size))) != ntohl(size))
	{
	  socket.putback(data, readsize);
	  stack.put_back(socket);
	  return false;
	}
      block.data = data;
      block.file = file;
      block.size = ntohl(size);
      (_handler->*_callableMap.at(Opcodes::fileTrunk))(&block);
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCPassocSprites(IReadableSocket& socket) const
{
  s_assoc_sprite block;
  unsigned short datasize;
  unsigned int readsize, total;
  char filename[32];
  std::list<std::pair<char, s_shorts> >::iterator ite;
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      stack.push(datasize);
      if ((readsize = socket.recv(filename, 32)) != 32)
	{
	  socket.putback(filename, readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(filename);
      total = readsize;
      while (total != ntohs(datasize))
	{
	  block.sprites.push_back(std::pair<char, s_shorts>());
	  if ((readsize = socket.recv(&block.sprites.back().first, 1)) != 1)
	    {
	      socket.putback(reinterpret_cast<char*>(&block.sprites.back().first), readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.sprites.back().first);
	  total += readsize;
	  if ((readsize = socket.recv(reinterpret_cast<char*>(&block.sprites.back().second), sizeof(s_shorts))) != sizeof(s_shorts))
	    {
	      socket.putback(reinterpret_cast<char*>(&block.sprites.back().second), readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.sprites.back().second);
	  total += readsize;
	}
      if (!block.sprites.empty())
	{
	  ite = block.sprites.begin();
	  while (ite != block.sprites.end())
	    {
	      ite->second._v1 = ntohs(ite->second._v1);
	      ite->second._v2 = ntohs(ite->second._v2);
	      ite->second._v3 = ntohs(ite->second._v3);
	      ite->second._v4 = ntohs(ite->second._v4);
	      ++ite;
	    }
	}
      (_handler->*_callableMap.at(Opcodes::assocSprite))(reinterpret_cast<void*>(&block));
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::UDPok(IReadableSocket& socket) const
{
  unsigned short datasize;
  unsigned int readsize;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      (_handler->*_callableMap.at(Opcodes::UDPOkay))(NULL);
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::TCPsendError(IReadableSocket& socket) const
{
  s_error block;
  unsigned short datasize;
  unsigned int readsize;
  char msg[256];
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      stack.push(datasize);
      if ((readsize = socket.recv(&(block.code), sizeof(char))) != sizeof(char))
	{
	  socket.putback(&(block.code), readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(block.code);
      if ((readsize = socket.recv(msg, 256)) != 256)
	{
	  socket.putback(msg, readsize);
	  stack.put_back(socket);
	  return false;
	}
      block.msg = msg;
      (_handler->*_callableMap.at(Opcodes::sendError))(reinterpret_cast<void*>(&block));
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::UDPscreenState(IReadableSocket& socket) const
{
  s_screen_state block;
  unsigned short datasize;
  unsigned int readsize, total;
  std::list<std::pair<unsigned int, t_coord> >::iterator ite;
  SocketStack stack;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      stack.push(datasize);
      if ((readsize = socket.recv(reinterpret_cast<char*>(&(block.score)), sizeof(block.score))) != sizeof(block.score))
	{
	  socket.putback(reinterpret_cast<char*>(&(block.score)), readsize);
	  stack.put_back(socket);
	  return false;
	}
      stack.push(block.score);
      total = readsize;
      while (total < ntohs(datasize))
	{
	  block.elements.push_back(std::pair<unsigned int, t_coord>());
	  if ((readsize = socket.recv(reinterpret_cast<char*>(&block.elements.back().first), sizeof(unsigned int))) != sizeof(unsigned int))
	    {
	      socket.putback(reinterpret_cast<char*>(&block.elements.back().first), readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.elements.back().first);
	  total += readsize;
	  if ((readsize = socket.recv(reinterpret_cast<char*>(&block.elements.back().second), sizeof(t_coord))) != sizeof(t_coord))
	    {
	      socket.putback(reinterpret_cast<char*>(&block.elements.back().second), readsize);
	      stack.put_back(socket);
	      return false;
	    }
	  stack.push(block.elements.back().second);
	  total += readsize;
	}
      if (!block.elements.empty())
	{
	  ite = block.elements.begin();
	  while (ite != block.elements.end())
	    {
			ite->first = ntohl(ite->first);
	      ite->second._posX = ntohs(ite->second._posX);
	      ite->second._posY = ntohs(ite->second._posY);
	      ++ite;
	    }
	}
      block.score = ntohl(block.score);
      (_handler->*_callableMap.at(Opcodes::screenState))(&block);
      return true;
    }
  return false;
}

template<typename T>
bool ClientCommunication<T>::UDPendOfGame(IReadableSocket& socket) const
{
  unsigned short datasize;
  unsigned int readsize;
  unsigned int score;

  if (socket.readable())
    {
      if ((readsize = socket.recv(reinterpret_cast<char*>(&datasize), sizeof(datasize))) != 2)
	{
	  socket.putback(reinterpret_cast<char*>(&datasize), readsize);
	  return false;
	}
      if ((readsize = socket.recv(reinterpret_cast<char*>(&score), sizeof(unsigned int))) != sizeof(unsigned int))
	{
	  socket.putback(reinterpret_cast<char*>(&score), readsize);
	  socket.putback(reinterpret_cast<char*>(&datasize), sizeof(datasize));
	  return false;
	}
      score = ntohl(score);
      (_handler->*_callableMap.at(Opcodes::endOfGame))(&score);
      return true;
    }
  return false;
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

