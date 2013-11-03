#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>

#endif // _WIN32

#include <algorithm>
#include "SocketPool.h"

SocketPool::SocketPool()
  : _alive(true), _watcher(*this, &SocketPool::watcher)
{}

SocketPool::~SocketPool()
{
  this->_alive = false;
  this->_c.signal();
  this->_watcher.join();
}

void  SocketPool::watchSocket(ASocket* s)
{
  ScopedLock  lock(this->_m);

  this->_list.push_back(s);
  this->_c.signal();
}

void  SocketPool::releaseSocket(ASocket* s)
{
  ScopedLock  lock(this->_m);

  this->_list.remove(s);
}

SocketPool::Setter::Setter(fd_set& rfds, fd_set& wfds, unsigned int& max)
  : _rfds(rfds), _wfds(wfds), _max(max)
{}

SocketPool::Setter::~Setter()
{}

void  SocketPool::Setter::operator()(ASocket *s)
{
  FD_SET(s->getId(), &this->_rfds);
  if (s->wantToWrite())
    FD_SET(s->getId(), &this->_wfds);
  if (s->getId() > this->_max)
    this->_max = s->getId();
}

void  SocketPool::Setter::reset()
{
  FD_ZERO(&this->_rfds);
  FD_ZERO(&this->_wfds);
  this->_max = 0;
}

SocketPool::Executer::Executer(fd_set& rfds, fd_set& wfds)
  : _rfds(rfds), _wfds(wfds)
{}

SocketPool::Executer::~Executer()
{}

void  SocketPool::Executer::operator()(ASocket *s)
{
  if (FD_ISSET(s->getId(), &this->_rfds))
    s->readFromSock();
  if (FD_ISSET(s->getId(), &this->_wfds))
    s->writeToSock();
}

void			SocketPool::watcher()
{
  ASocket::SocketId	max;
  fd_set		rfds;
  fd_set		wfds;
  SocketPool::Setter    s(rfds, wfds, max);
  SocketPool::Executer	e(rfds, wfds);
  timeval		to;

  while (this->_alive)
  {
    if (!this->_list.size())
      this->_c.wait(this->_m);
    if (this->_list.size())
    {
      ScopedLock  lock(this->_m);

      s.reset();
      to.tv_sec = 0;
      to.tv_usec = 500000;
      std::for_each<std::list<ASocket*>::iterator, SocketPool::Setter&>(this->_list.begin(), this->_list.end(), s);
      select(max, &rfds, &wfds, NULL, &to);
      std::for_each<std::list<ASocket*>::iterator, SocketPool::Executer&>(this->_list.begin(), this->_list.end(), e);
    }
  }
}