#pragma once

#include "CircularBuffer.h"
#include "Packet.hpp"

template<typename Type = char, unsigned long isize = 4096>
struct IOBuff
{
  CircularBuffer<Type, isize>  _input;
  Packet  _output;

  IOBuff(bool print = false)
    : _output(print)
  {}
};

template<unsigned long isize = 4096>
struct UDPBuff: public IOBuff<char, isize>
{
  unsigned short  _port;

  UDPBuff()
    : IOBuff<char, isize>(true)
  {}
};
