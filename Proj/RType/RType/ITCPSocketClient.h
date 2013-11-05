//
// ITCPSocketClient.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Nov  4 23:34:56 2013 julien edmond
// Last update Tue Nov  5 03:08:43 2013 julien edmond
//

#pragma once

#include "Socket.h"

class ITCPSocketClient: public ISocket
{
public:
  virtual ~ITCPSocketClient() {}

  virtual unsigned int	recv(char* buff, unsigned int size) = 0;
  virtual void		send(char* buff, unsigned int size) = 0;
};