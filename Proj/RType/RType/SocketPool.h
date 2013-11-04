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
#define	  SPTOUSEC  500000

class SocketPool: public Singleton<SocketPool>
{
public:
  SocketPool();
  ~SocketPool();

  void	watchSocket(ASocket* sock);
  void	releaseSocket(ASocket* sock);

private:

  class Setter
  {
  public:
    Setter(fd_set& rfds, fd_set& wfds, ASocket::SocketId& max);
    ~Setter();

    void  operator()(ASocket* sock);
    void  reset();

  private:
    Setter();
    Setter(const Setter&);
    Setter& operator=(const Setter&);

    fd_set&	  _rfds;
    fd_set&	  _wfds;
    ASocket::SocketId& _max;
  };

  class Executer
  {
  public:
    Executer(fd_set& rfds, fd_set& wfds);
    Executer(const Executer&);
    ~Executer();

    bool  operator()(ASocket* sock);

  private:
    Executer();
    Executer& operator=(const Executer&);

    fd_set& _rfds;
    fd_set& _wfds;
  };

  void watcher();

  bool		      _alive;
  std::list<ASocket*> _list;
  CondVar	      _c;
  Mutex		      _m;
  Thread	      _watcher;

  SocketPool(const SocketPool&);
  SocketPool& operator=(const SocketPool&);
};
