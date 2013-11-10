#pragma once

#include "CircularBuffer.h"

template<typename Type = char, unsigned long isize = 4096,
	 unsigned long osize = isize>
struct IOBuff
{
  CircularBuffer<Type, isize>  _input;
  CircularBuffer<Type, osize>  _output;
};

template<unsigned long isize = 4096, unsigned long osize = isize>
struct UDPBuff: public IOBuff<char, isize, osize>
{
  unsigned short  _port;
};
