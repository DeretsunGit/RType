//
// Packet.hpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>
#include <cstring>

class Packet
{
public:
	Packet(int size, char* data)
	{
		set(data, 0, size);
	}

	Packet()
	{
		_size = 0;
	}

	~Packet()
	{
	}

	/*bool set(char* data, int size)
	{
		if (data == 0)
			return (false);

		_size = size;
		memcpy(_buff, data, size);

		return (true);
	}*/

	bool set(char* data, int start, int size)
	{
		if (data == 0)
			return (false);

		_size += size;
		memcpy(&_buff[start], data, size);

		return (true);
	}

	const char* getBuffer() const
	{
		return (this->_buff);
	}

	int getSize() const
	{
		return (this->_size);
	}



private:
	int _size;
	char _buff[1000];

};