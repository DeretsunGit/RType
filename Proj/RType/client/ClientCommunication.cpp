//
// ClientCommunication.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/client
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 15:05:51 2013 julien edmond
// Last update Fri Nov  8 15:12:12 2013 julien edmond
//

#include	<cstring>
#include	"ClientCommunication.hpp"
#include	"rtype_common.h"

/* CLIENT TO SERVER */
template<typename T>
void ClientCommunication<T>::TCPsayHello(Packet& packet, const char* nickname, short resolution[2])
  {
	  s_say_hello block;

	  block.opcode = Opcodes::sayHello;
	  block.datasize = sizeof(s_say_hello) - HEADSIZE;
	  strcpy(block.magic, "KOUKOU");
	  memcpy(block.nickname, nickname, strlen(nickname));
	  memcpy(block.resolution, resolution, sizeof(block.resolution));

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_say_hello));
  }

template<typename T>
void ClientCommunication<T>::TCPsetRoom(Packet& packet, const char* roomName)
  {
	  s_set_room block;

	  block.opcode = Opcodes::setRoom;
	  block.datasize = sizeof(char) * 32;
	  memcpy(block.roomName, roomName, strlen(roomName));

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_set_room));
  }

template<typename T>
void ClientCommunication<T>::TCPselectRoom(Packet& packet, const char roomId)
  {
	  s_select_room block;

	  block.opcode = Opcodes::selectRoom;
	  block.roomId = roomId;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_select_room));
  }

template<typename T>
void ClientCommunication<T>::TCPleaveRoom(Packet& packet)
  {
	  s_leave_room block;

	  block.opcode = Opcodes::leaveRoom;
	  
	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_leave_room));
  }

template<typename T>
void ClientCommunication<T>::TCPchangeDifficulty(Packet& packet, char difficulty)
  {
	  s_change_difficulty block;

	  block.opcode = Opcodes::changeDifficulty;
	  block.difficulty = difficulty;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_change_difficulty));
  }

template<typename T>
void ClientCommunication<T>::TCPsetMap(Packet& packet, bool mapStatus, const char* filename)
  {
	  s_set_map block;

	  block.opcode = Opcodes::setMap;
	  block.datasize = sizeof(s_set_map) - HEADSIZE;
	  block.mapStatus = mapStatus;
	  memcpy(block.filename, filename, strlen(filename));
	  
	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_set_map));
  }

template<typename T>
void ClientCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
  {
	  s_file_trunk block;

	  block.opcode = Opcodes::fileTrunk;
	  block.datasize = static_cast<short>(sizeof(char) * (32 + size));
	  memcpy(block.filename, filename, strlen(filename));
	  memcpy(block.data, data, size);

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_file_trunk));
  }

template<typename T>
void ClientCommunication<T>::TCPsetReady(Packet& packet)
  {
	  s_set_ready block;

	  block.opcode = Opcodes::setReady;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_set_ready));
  }

template<typename T>
void ClientCommunication<T>::TCPdownloadRessource(Packet& packet, const char* filename)
{
  s_download_ressource block;

  block.opcode = Opcodes::downloadRsrc;
  block.datasize = sizeof(char) * 128;
  memcpy(block.filename, filename, strlen(filename));

  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_download_ressource));
}

template<typename T>
void ClientCommunication<T>::UDPReady(Packet& packet)
 {
	  s_udp_ready block;

	  block.opcode = Opcodes::UDPReady;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_udp_ready));
  }

template<typename T>
void ClientCommunication<T>::TCPletsPlay(Packet& packet)
 {
	  s_lets_play block;

	  block.opcode = Opcodes::letsPlay;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_lets_play));
  }

template<typename T>
void ClientCommunication<T>::TCPsaveMap(Packet& packet, const char* mapName)
{
	  s_save_map block;

	  block.opcode = Opcodes::saveMap;
	  block.datasize = 128;
	  memcpy(block.mapName, mapName, strlen(mapName));

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_save_map));
}

template<typename T>
void ClientCommunication<T>::UDPinputs(Packet& packet, s_inputs& inputs)
{
	  s_inputs block;

	  block = inputs;
	  block.opcode = Opcodes::inputs;

	  packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_inputs));
  }

template<typename T>
void ClientCommunication<T>::UDPpauseOk(Packet& packet)
{
	s_pause_ok block;

	block.opcode = 0x0E;

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_pause_ok));
}

/* SERVER TO CLIENT */
template<typename T>
bool ClientCommunication<T>::TCProomList(IReadableSocket& socket) const
{
	s_room_list roomList;
	roomList.opcode = Opcodes::roomList;
	int readSize = 0;
	int nbRooms = 0;
	int i = 0;

	if (socket.readable() && (_handler && _callableMap.find(roomList.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&roomList.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&roomList.datasize), readSize);
			return false;
		}
		nbRooms = roomList.datasize / sizeof(s_room_list_content);
		roomList.rooms = new s_room_list_content[nbRooms];
		readSize = 0;
		while (i < nbRooms)
		{
			readSize += socket.recv(reinterpret_cast<char*>(&roomList.rooms[i]), sizeof(s_room_list_content));
			if (readSize != sizeof(s_room_list_content))
			{
				socket.putback(reinterpret_cast<char*>(&roomList.rooms[i]), readSize);
				while (--i >= 0)
					socket.putback(reinterpret_cast<char*>(&roomList.rooms[i]), sizeof(s_room_list_content));
				socket.putback(reinterpret_cast<char*>(&roomList.datasize), 2);
				delete roomList.rooms;
				return false;
			}
			readSize = 0;
			++i;
		}
		(_handler->*(_callableMap.at(roomList.opcode)))(&roomList);
		delete roomList.rooms;
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCProomState(IReadableSocket& socket) const
{
	s_room_state status;
	status.opcode = Opcodes::roomState;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(status.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&status.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&status.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&status) + HEADSIZE), sizeof(s_room_state) - HEADSIZE);
		if (readSize != status.datasize && readSize != sizeof(s_room_state) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&status) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap.at(status.opcode))(&status);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCPwrongMap(IReadableSocket& socket) const
{
	s_wrong_map block;
	block.opcode = Opcodes::wrongMap;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCPstartLoading(IReadableSocket& socket) const
{
	s_start_loading block;
	block.opcode = Opcodes::startLoading;
	int readSize = 0;
	int nbRessources = 0;
	int i = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize += socket.recv(reinterpret_cast<char*>(&block.port), 2);
		if (readSize != 4)
		{
			socket.putback(reinterpret_cast<char*>(&block.port), readSize);
			socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
			return false;
		}
		nbRessources = (block.datasize - 2) / sizeof(s_ressource);
		block.ressources = new s_ressource[nbRessources];
		readSize = 0;
		while (i < nbRessources)
		{
			readSize += socket.recv(reinterpret_cast<char*>(&block.ressources[i]), sizeof(s_ressource));
			if (readSize != sizeof(s_ressource))
			{
				socket.putback(reinterpret_cast<char*>(&block.ressources[i]), readSize);
				while (--i >= 0)
					socket.putback(reinterpret_cast<char*>(&block.ressources[i]), sizeof(s_ressource));
				socket.putback(reinterpret_cast<char*>(&block.port), 2);
				socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
				delete block.ressources;
				return false;
			}
			readSize = 0;
			++i;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		delete block.ressources;
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket) const
{
	s_file_trunk block;
	block.opcode = Opcodes::fileTrunk;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_file_trunk) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_file_trunk) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCPassocSprites(IReadableSocket& socket) const
{
	s_assoc_sprites block;
	block.opcode = Opcodes::assocSprite;
	int readSize = 0;
	int nbSprites = 0;
	int i = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize += socket.recv(reinterpret_cast<char*>(&block.filename), 128);
		if (readSize != 130)
		{
			socket.putback(reinterpret_cast<char*>(&block.filename), readSize);
			socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
			return false;
		}
		nbSprites = (block.datasize - 128) / sizeof(s_sprite);
		block.sprites = new s_sprite[nbSprites];
		readSize = 0;
		while (i < nbSprites)
		{
			readSize += socket.recv(reinterpret_cast<char*>(&block.sprites[i]), sizeof(s_sprite));
			if (readSize != sizeof(s_sprite))
			{
				socket.putback(reinterpret_cast<char*>(&block.sprites[i]), readSize);
				while (--i >= 0)
					socket.putback(reinterpret_cast<char*>(&block.sprites[i]), sizeof(s_sprite));
				socket.putback(reinterpret_cast<char*>(&block.filename), 128);
				socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
				delete block.sprites;
				return false;
			}
			readSize = 0;
			++i;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		delete block.sprites;
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UDPok(IReadableSocket& socket) const
{
	s_udp_ok block;
	block.opcode = Opcodes::UDPOkay;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::TCPsendError(IReadableSocket& socket) const
{
	s_send_error block;
	block.opcode = Opcodes::sendError;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_send_error) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_send_error) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UDPscreenState(IReadableSocket& socket) const
{
	s_screen_state block;
	block.opcode = Opcodes::screenState;
	int readSize = 0;
	int nbElements = 0;
	int i = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize += socket.recv(reinterpret_cast<char*>(&block.score), sizeof(int));
		if (readSize != 2 + sizeof(int))
		{
			socket.putback(reinterpret_cast<char*>(&block.score), readSize);
			socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
			return false;
		}
		nbElements = (block.datasize - sizeof(int)) / sizeof(s_element);
		block.elements = new s_element[nbElements];
		readSize = 0;
		while (i < nbElements)
		{
			readSize += socket.recv(reinterpret_cast<char*>(&block.elements[i]), sizeof(s_element));
			if (readSize != sizeof(s_element))
			{
				socket.putback(reinterpret_cast<char*>(&block.elements[i]), readSize);
				while (--i >= 0)
					socket.putback(reinterpret_cast<char*>(&block.elements[i]), sizeof(s_element));
				socket.putback(reinterpret_cast<char*>(&block.score), sizeof(int));
				socket.putback(reinterpret_cast<char*>(&block.datasize), 2);
				delete block.elements;
				return false;
			}
			readSize = 0;
			++i;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		delete block.elements;
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UDPendOfGame(IReadableSocket& socket) const
{
	s_end_of_game block;
	int readSize = 0;
	block.opcode = Opcodes::endOfGame;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.score), sizeof(int));
		if (readSize != sizeof(int))
		{
			socket.putback(reinterpret_cast<char*>(&block.score), readSize);
			return false;
		}
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UDPpause(IReadableSocket& socket) const
{
 	s_pause block;
	block.opcode = 0x19;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UDPspawn(IReadableSocket& socket) const
{
  	s_spawn block;
	block.opcode = 0x1A;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}

template<typename T>
bool ClientCommunication<T>::UPDdeath(IReadableSocket& socket) const
{
  	s_death block;
	block.opcode = 0x1B;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap.at(block.opcode))(&block);
		return true;
	}
	return false;
}
