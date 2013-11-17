//
// SocketStack.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Nov 14 10:01:27 2013 julien edmond
// Last update Thu Nov 14 11:18:53 2013 julien edmond
//

#pragma once

#include	<stack>
#include	<utility>
#include	"IReadableSocket.h"

class	SocketStack: std::stack<std::pair<const char*, unsigned int> >
{
public:
  SocketStack()
    : _size(0)
  {}

  void	push(const char* addr, unsigned int size)
  {
    this->Parent::push(std::pair<const char*, unsigned int>(addr, size));
    this->_size += size;
  }

  template<typename T>
  void	push(const T& var)
  {
    this->push(reinterpret_cast<const char*>(&var), sizeof(T));
  }

  void	pop()
  {
    this->_size -= this->top().second;
    this->Parent::pop();
  }

  void	put_back(IReadableSocket& s)
  {
    while (!this->empty())
      {
	s.putback(this->top().first, this->top().second);
	this->pop();
      }
  }

  unsigned int	byteSize() const
  {
    return (this->_size);
  }

  ~SocketStack()
  {}

private:
  typedef std::stack<std::pair<const char*, unsigned int> > Parent;
  unsigned int	_size;

  SocketStack(const SocketStack&);
  SocketStack&	operator=(const SocketStack&);
};
