//
// Packet.hpp for RType
//
// Made by kevin gilmaire
// Login   <gilmai_k@epitech.net>
//

#pragma once

#include <string>
#include <list>
#include <cstring>
#include <iostream>
#include <algorithm>

class Packet
{
public:

  Packet()
  {
    _size = 0;
    _ite = _buffer.begin();
  }

  ~Packet()
  {
    while (!_buffer.empty())
      {
	delete[] _buffer.back();
	_buffer.pop_back();
      }
  }

  Packet(const Packet&)
  {
    _size = 0;
    _ite = _buffer.begin();
  }

  Packet& operator=(const Packet&)
  {
    return (*this);
  }

  void write(const char* data, unsigned int size)
  {
    while (size > 0)
      {
	if (this->_ite == this->_buffer.end())
	  {
	    _buffer.push_back(new char[1024]);
	    _ite = --_buffer.end();
	  }

	unsigned int sizetocpy = std::min<unsigned int>(1024 - (_size % 1024), size);

	memcpy(&(*_ite)[_size % 1024], data, sizetocpy);
	size -= sizetocpy;
	_size += sizetocpy;
	if (!(_size % 1024))
	  ++_ite;
      }
  }

  const std::list<char*>& getBuffer() const
  {
    return (this->_buffer);
  }

  int getSize() const
  {
    return (this->_size);
  }

  void	setSize(int size)
  {
    _size = size;
  }

  void reset()
  {
    _size = 0;
    _ite = _buffer.begin();
  }

  void	pop_front()
  {
    if (_size)
      {
	delete[] this->_buffer.front();
	this->_buffer.pop_front();
	if (!this->_buffer.empty())
	  this->_ite = --this->_buffer.end();
	else
	  this->_ite = this->_buffer.end();
	_size -= std::min<unsigned int>(1024, _size);
      }
  }

private:
  int _size;
  std::list<char*> _buffer;
  std::list<char*>::iterator _ite;
};
