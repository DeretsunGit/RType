//
// ASocket.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Nov  4 19:16:18 2013 julien edmond
// Last update Tue Nov  5 00:56:46 2013 julien edmond
//

#include	"SocketPool.h"
#include	"Socket.h"

ASocket::ASocket()
{
}

ASocket::~ASocket()
{
  SocketPool::getInstance().releaseSocket(this);
}
