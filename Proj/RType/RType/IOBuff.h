#pragma once

#include "CircularBuffer.h"

template<typename Type = char, unsigned long size = 500>
struct IOBuff
{
  CircularBuffer<Type, size>  _input;
  CircularBuffer<Type, size>  _output;
};