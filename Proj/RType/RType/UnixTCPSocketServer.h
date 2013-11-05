//
// UnixTCPSocketServer.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Tue Nov  5 03:12:47 2013 julien edmond
// Last update Tue Nov  5 04:06:39 2013 julien edmond
//

#pragma once

#ifndef	_WIN32

# include	<queue>
# include	"Mutex.h"
# include	"ITCPSocketServer.h"

class	UnixTCPSocketServer: public ITCPSocketServer
{
public:
  UnixTCPSocketServer(unsigned short port);
  virtual ~UnixTCPSocketServer();

  SocketId		getId() const;
  bool			wantToWrite() const;
  void			readFromSock();
  void			writeToSock();
  ITCPSocketClient*	accept();
  bool			isLive() const;

private:
  UnixTCPSocketServer();
  UnixTCPSocketServer(const UnixTCPSocketServer&);
  UnixTCPSocketServer&	operator=(const UnixTCPSocketServer&);

  bool				_live;
  SocketId			_sock;
  std::queue<ITCPSocketClient*>	_clients;
  Mutex				_m;
};

#endif	// !_WIN32
