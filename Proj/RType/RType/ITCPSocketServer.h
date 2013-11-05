//
// ATCPSocketServer.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Tue Nov  5 03:01:53 2013 julien edmond
// Last update Tue Nov  5 03:13:34 2013 julien edmond
//

#pragma once

#ifndef	_WIN32

# include	"ITCPSocketClient.h"

class	ITCPSocketServer: public ISocket
{
public:
  virtual ~ITCPSocketServer() {}

  virtual ITCPSocketClient*	accept() = 0;
};

#endif	// !_WIN32
