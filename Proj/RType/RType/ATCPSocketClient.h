//
// ATCPSocketClient.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Nov  4 23:34:56 2013 julien edmond
// Last update Mon Nov  4 23:37:00 2013 julien edmond
//

#pragma once

#include "Socket.h"

class ATCPSocketClient: public ASocket
{
public:
  virtual ~ATCPSocketClient() {}

  virtual unsigned int	recv(char* buff, unsigned int size) = 0;
  virtual void		send(char* buff, unsigned int size) = 0;
};