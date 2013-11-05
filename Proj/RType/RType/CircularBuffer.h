#pragma once

template<class Type = char, unsigned long size = 500>
class CircularBuffer
{
public:
  CircularBuffer()
    : _start(0), _end(0)
  {}

  CircularBuffer(const CircularBuffer& o)
    : _start(o._start), _end(o._end)
  {
    unsigned long off(this->_start);

    while (off != this->_end)
    {
      this->_buff[off] = o._buff[off];
      off = (off + 1) % size;
    }
  }

  CircularBuffer&   operator=(const CircularBuffer& o)
  {
    unsigned long off(o._start);

    this->_start = o._start;
    this->_end = o._end;
    while (off != this->_end)
    {
      this->_buff[off] = o._buff[off];
      off = (off + 1) % size;
    }
  }

  ~CircularBuffer()
  {}

  unsigned long getSize() const
  {
    return (size);
  }

  unsigned long	  readableSize() const
  {
    return (this->_end >= this->_start ? this->_end - this->_start : size - this->_start + this->_end);
  }

  unsigned long	  readSome(Type* buff, unsigned long s)
  {
    unsigned long sent(0);

    while (sent < s && this->_start != this->_end)
    {
      buff[sent] = this->_buff[this->_start];
      this->_start = (this->_start + 1) % size;
      ++sent;
    }
    return (sent);
  }

  void		  writeSome(const Type* buff, unsigned long s)
  {
    unsigned long i(0);

    while (i < s)
    {
      this->_buff[this->_end] = buff[i];
      if ((this->_end = (this->_end + 1) % size) == this->_start)
	this->_start = (this->_start + 1) % size;
      ++i;
    }
  }

private:
  Type		_buff[size];
  unsigned long	_start;
  unsigned long	_end;
};
