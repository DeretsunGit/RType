//
// ITCPSocketClient.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Nov  4 23:34:56 2013 julien edmond
// Last update Wed Nov  6 15:28:48 2013 julien edmond
//

#pragma once

#include "IReadableSocket.h"

class ITCPSocketClient: public IReadableSocket
{
public:
  virtual ~ITCPSocketClient() {}

  virtual void		putback(const char* buff, unsigned int size) = 0;
  virtual unsigned int	recv(char* buff, unsigned int size) = 0;
  virtual unsigned int	readable() const = 0;
};
