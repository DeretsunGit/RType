#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>

#endif // _WIN32

#include <algorithm>
#include <iostream>
#include "SocketPool.h"

SocketPool::SocketPool()
  : _alive(true), _watcher(*this, &SocketPool::watcher)
{
	this->_watcher.start();
}

SocketPool::~SocketPool()
{
  this->_alive = false;
  this->_c.signal();
  this->_watcher.join();
}

void  SocketPool::watchSocket(ASocket* s)
{
  this->_m.lock();
  this->_list.push_back(s);
  this->_c.signal();
  this->_m.unlock();
}

void  SocketPool::releaseSocket(ASocket* s)
{
  this->_m.lock();
  this->_list.remove(s);
  this->_m.unlock();
}

SocketPool::Setter::Setter(fd_set& rfds, fd_set& wfds, ASocket::SocketId& max)
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
    /*if (!this->_list.size())
      this->_c.wait(this->_m);*/
    if (this->_list.size())
    {
      this->_m.lock();
      s.reset();
      to.tv_sec = SPTOSEC;
      to.tv_usec = SPTOUSEC;
      std::for_each<std::list<ASocket*>::iterator, SocketPool::Setter&>(this->_list.begin(), this->_list.end(), s);
      select(static_cast<int>(max), &rfds, &wfds, NULL, &to);
      std::for_each<std::list<ASocket*>::iterator, SocketPool::Executer&>(this->_list.begin(), this->_list.end(), e);
      this->_m.unlock();
    }
  }
}