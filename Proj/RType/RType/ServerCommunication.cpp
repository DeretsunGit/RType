#include "ServerCommunication.hpp"
#include "Room.h"

	/* SERVER TO CLIENT */
template<class T>
void ServerCommunication<T>::TCProomList(Packet& packet, std::list<Room *>& rooms) // ajouter un tcpSocket pour pouvoir l'envoyer avant l'initialisation du client ? (erreur 66, RTypeServer.cpp L52)
{
	s_room_list block;
	packet.setSize(0);
	block.opcode = Opcodes::roomList;
	block.datasize = static_cast<short>(sizeof(s_room_list_content) * (rooms.size() + 1));
	std::list<Room *>::const_iterator ite = rooms.begin();
	int start = HEADSIZE;
	packet.set(reinterpret_cast<char*>(&block), 0, HEADSIZE);

	while (ite != rooms.end())
	{
		s_room_list_content room;
		size_t		    size(std::min<size_t>((*ite)->getName().size(), sizeof(room.roomName) - 1));

		room.nbPlayer = (* ite)->getNbPlayer();
		room.roomId = (* ite)->getId();
		memcpy(room.roomName, (* ite)->getName().c_str(), size);
		memset(&room.roomName[size], 0, sizeof(room.roomName) - size);
		packet.set(reinterpret_cast<char*>(&room), start, sizeof(s_room_list_content));
		start += sizeof(s_room_list_content);
		++ite;
	}
	s_room_list_content end;
	end.roomId = 0;
	packet.set(reinterpret_cast<char*>(&end), start, sizeof(s_room_list_content));
}

template<class T>
void ServerCommunication<T>::TCProomState(Packet& packet, Room& room)
{
	s_room_state block;

	block.opcode = Opcodes::roomState;
	block.datasize = sizeof(s_room_state) - HEADSIZE;
	block.difficulty = room.getDifficulty();
	memcpy(block.roomName, room.getName().c_str(), room.getName().size());
	memcpy(block.map, room.getMap().c_str(), room.getMap().size());
	block.mapStatus = room.getMapStatus();

	int i = 0;
	std::vector<Player*>::const_iterator ite = room.getPlayers().begin();

	while (ite != room.getPlayers().end() && i < 4)
	{
		memcpy(block.playerNames[i], (*ite)->getName().c_str(), (*ite)->getName().size());
		block.playerStates[i] = (*ite)->getReady();
		++i;
		++ite;
	}

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_room_state));
}

template<class T>
void ServerCommunication<T>::TCPwrongMap(Packet& packet)
{
	s_wrong_map block;

	block.opcode = Opcodes::wrongMap;

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_wrong_map));
}

template<class T>
void ServerCommunication<T>::TCPstartLoading(Packet& packet, std::list<std::string>& filenames, std::list<std::string>& md5, unsigned short UDPport) // on remplacera les deux listes filename/md5 par une liste de File quand j'aurai l'API filesystem
{
	s_start_loading block;

	block.opcode = Opcodes::startLoading;
	block.datasize = static_cast<short>((sizeof(s_ressource) * filenames.size()) + sizeof(unsigned short));
	block.port = UDPport;

	packet.set(reinterpret_cast<char*>(&block), 0, HEADSIZE + sizeof(unsigned short));

	int start = HEADSIZE + sizeof(unsigned short);
	std::list<std::string>::const_iterator f_ite = filenames.begin();
	std::list<std::string>::const_iterator m_ite = md5.begin();

	while (f_ite != filenames.end() && m_ite != md5.end())
	{
		s_ressource ressource;
		memcpy(ressource.filename, f_ite->c_str(), f_ite->size());
		memcpy(ressource.md5, m_ite->c_str(), m_ite->size());
		packet.set(reinterpret_cast<char*>(&ressource), start, sizeof(ressource));
		start += sizeof(s_ressource);
		++f_ite;
		++m_ite;
	}
	s_ressource end;
	end.filename[0] = 0;
	packet.set(reinterpret_cast<char*>(&end), start, sizeof(s_ressource));
}

template<class T>
void ServerCommunication<T>::TCPsendFileTrunk(Packet& packet, const char* filename, const char* data, size_t size)
{
	s_file_trunk block;

	block.opcode = Opcodes::fileTrunk;
	block.datasize = static_cast<short>(sizeof(char) * (32 + size));
	memcpy(block.filename, filename, strlen(filename));
	memcpy(block.data, data, size);

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_file_trunk));
}

template<class T>
void ServerCommunication<T>::TCPassocSprites(Packet& packet, const char* filename, std::list<char>& idSprites, std::list<short[4]>& coords)
{
	s_assoc_sprites block;

	block.opcode = Opcodes::assocSprite;
	block.datasize = static_cast<short>((sizeof(char) * 128) + (sizeof(s_sprite) * idSprites.size()));
	memcpy(block.filename, filename, strlen(filename));

	packet.set(reinterpret_cast<char*>(&block), 0, HEADSIZE + (sizeof(char) * 128));
	int start = HEADSIZE + (sizeof(char) * 128);
	std::list<char>::const_iterator id_ite = idSprites.begin();
	std::list<short[4]>::const_iterator coord_ite = coords.begin();

	while (id_ite != idSprites.end() && coord_ite != coords.end())
	{
		s_sprite newsprite;
		newsprite.idSprite = *id_ite;
		memcpy(newsprite.coord, (*coord_ite), sizeof(short) * 4);
		packet.set(reinterpret_cast<char*>(&newsprite), start, sizeof(s_sprite));
		start += sizeof(s_sprite);
		++id_ite;
		++coord_ite;
	}
	s_sprite end;
	end.idSprite = 0;
	packet.set(reinterpret_cast<char*>(&end), start, sizeof(s_sprite));
}

template<class T>
void ServerCommunication<T>::UDPok(Packet& packet)
{
	s_udp_ok block;

	block.opcode = Opcodes::UDPOkay;

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_udp_ok));
}

template<class T>
void ServerCommunication<T>::TCPsendError(Packet& packet, char errorCode, const char* errorMsg)
{
	s_send_error block;

	block.opcode = Opcodes::sendError;
	block.datasize = sizeof(s_send_error) - HEADSIZE;
	block.errorCode = errorCode;
	memcpy(block.errorDesc, errorMsg, strlen(errorMsg));

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_send_error));
}

template<class T>
void ServerCommunication<T>::UDPscreenState(Packet& packet, int score, std::list<Element>& elements) // elements pour idSprite et CoordSprite
{
	s_screen_state block;

	block.opcode = Opcodes::screenState;
	block.datasize = static_cast<short>(sizeof(int) + (sizeof(s_sprite) * elements.size()));
	block.score = score;

	packet.set(reinterpret_cast<char*>(&block), 0, HEADSIZE + sizeof(int));

	int start = HEADSIZE + sizeof(int);
	std::list<Element>::const_iterator ite = elements.begin();

	while (ite != elements.end())
	{
		s_element element;
		element.idSprite = ite->getSpriteId();
		element.coord = ite->getPos();
		packet.set(reinterpret_cast<char*>(&element), start, sizeof(s_element));
		++ite;
		start += sizeof(s_element);
	}
	s_element end;
	end.idSprite = 0;
	packet.set(reinterpret_cast<char*>(&end), start, sizeof(s_element));
}

template<class T>
void ServerCommunication<T>::UDPendOfGame(Packet& packet, int score)
{
	s_end_of_game block;

	block.opcode = Opcodes::endOfGame;
	block.score = score;

	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_end_of_game));
}

template<class T>
void ServerCommunication<T>::UDPpause(Packet& packet)
{
	s_pause block;

	block.opcode = 0x19;
	
	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_pause));
}

template<class T>
void ServerCommunication<T>::UDPspawn(Packet& packet)
{
	s_spawn block;

	block.opcode = 0x1A;
	
	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_spawn));
}

template<class T>
void ServerCommunication<T>::UPDdeath(Packet& packet)
{
	s_death block;

	block.opcode = 0x1B;
	
	packet.set(reinterpret_cast<char*>(&block), 0, sizeof(s_death));
}

/* CLIENT TO SERVER */
template<class T>
bool ServerCommunication<T>::TCPsayHello(IReadableSocket& socket)
{ 
	s_say_hello block;
	block.opcode = Opcodes::sayHello;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_say_hello) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_say_hello) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetRoom(IReadableSocket& socket)
{
	s_set_room block;
	block.opcode = Opcodes::setRoom;
	int readSize = 0;

	std::cout << "je passe par la mon osti" << std::endl;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_set_room) - HEADSIZE);
		std::cout << "read = " << readSize << std::endl;
		if (readSize != block.datasize && readSize != sizeof(s_set_room) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPselectRoom(IReadableSocket& socket)
{
	s_select_room block;
	block.opcode = Opcodes::selectRoom;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.roomId), 1);
		if (readSize != 1)
			return false;
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPleaveRoom(IReadableSocket& socket)
{
	s_leave_room block;
	block.opcode = Opcodes::leaveRoom;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return true;
}

template<class T>
bool ServerCommunication<T>::TCPchangeDifficulty(IReadableSocket& socket)
{
	s_change_difficulty block;
	block.opcode = Opcodes::changeDifficulty;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.difficulty), 1);
		if (readSize != 1)
			return false;
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetMap(IReadableSocket& socket)
{
	s_set_map block;
	block.opcode = Opcodes::setMap;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_set_map) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_set_map) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPgetFileTrunk(IReadableSocket& socket)
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
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsetReady(IReadableSocket& socket)
{ 
	s_set_ready block;
	block.opcode = Opcodes::setReady;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPdownloadRessource(IReadableSocket& socket)
{
	s_download_ressource block;
	block.opcode = Opcodes::downloadRsrc;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_download_ressource) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_download_ressource) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPReady(IReadableSocket& socket)
{
	s_udp_ready block;
	block.opcode = Opcodes::UDPReady;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPletsPlay(IReadableSocket& socket)
{
	s_udp_ready block;
	block.opcode = Opcodes::letsPlay;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::TCPsaveMap(IReadableSocket& socket)
{ 
	s_save_map block;
	block.opcode = Opcodes::saveMap;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block.datasize), 2);
		if (readSize != 2)
		{
			socket.putback(reinterpret_cast<char*>(&block.datasize), readSize);
			return false;
		}
		readSize = socket.recv(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + HEADSIZE), sizeof(s_save_map) - HEADSIZE);
		if (readSize != block.datasize && readSize != sizeof(s_save_map) - HEADSIZE)
		{
			socket.putback(reinterpret_cast<char*>(reinterpret_cast<char *>(&block) + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPinputs(IReadableSocket& socket)
{
	s_inputs block;
	block.opcode = Opcodes::inputs;
	int readSize = 0;

	if (socket.readable() && (_handler && _callableMap.find(block.opcode) != _callableMap.end()))
	{
		readSize += socket.recv(reinterpret_cast<char*>(&block + 1), sizeof(s_inputs) - 1);
		if (readSize != sizeof(s_inputs) - 1)
		{
			socket.putback(reinterpret_cast<char*>(&block + 1), readSize);
			return false;
		}
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}

template<class T>
bool ServerCommunication<T>::UDPpauseOk(IReadableSocket& socket)
{ 
	s_pause_ok block;
	block.opcode = 0x19;

	if (_handler && _callableMap.find(block.opcode) != _callableMap.end())
	{
		(_handler->*_callableMap[block.opcode])(&block);
		return true;
	}
	return false;
}
