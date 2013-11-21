#pragma once

#ifndef	_WIN32

# include	<sys/select.h>

#endif	// !_WIN32

#include <list>
#include "Thread.h"
#include "Mutex.h"
#include "CondVar.h"
#include "Singleton.h"
#include "Socket.h"

#define	  SPTOSEC   0
#define	  SPTOUSEC  500

class SocketPool: public Singleton<SocketPool>
{
public:
  SocketPool();
  ~SocketPool();

  void	watchSocket(ISocket* sock);
  void	releaseSocket(ISocket* sock);

private:

  class Setter
  {
  public:
    Setter(fd_set& rfds, fd_set& wfds, ISocket::SocketId& max);
    ~Setter();

    void  operator()(ISocket* sock);
    void  reset();

  private:
    Setter();
    Setter(const Setter&);
    Setter& operator=(const Setter&);

    fd_set&	  _rfds;
    fd_set&	  _wfds;
    ISocket::SocketId& _max;
  };

  class Executer
  {
  public:
    Executer(fd_set& rfds, fd_set& wfds);
    Executer(const Executer&);
    ~Executer();

    bool  operator()(ISocket* sock);

  private:
    Executer();
    Executer& operator=(const Executer&);

    fd_set& _rfds;
    fd_set& _wfds;
  };

  void watcher();

  bool		      _alive;
  std::list<ISocket*> _list;
  CondVar	      _c;
  Mutex		      _m;
  Thread	      _watcher;

  SocketPool(const SocketPool&);
  SocketPool& operator=(const SocketPool&);
};
