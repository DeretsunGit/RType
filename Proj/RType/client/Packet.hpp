//
// Packet.hpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>

class Packet
{
public:
	Packet(int size, char* data)
	{
		set(data, size);
	}

	Packet()
	{
		_size = 0;
		_buff = 0;
	}

	~Packet()
	{
		if (_buff != 0)
			delete _buff;
	}

	bool set(char* data, int size)
	{
		if (_buff != 0)
			delete _buff;
		_buff = 0;

		if (data == 0)
			return (false);

		_size = size;
		_buff = data;

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
	char* _buff;

};