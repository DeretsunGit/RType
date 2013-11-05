#ifdef _WIN32

# include <WinSock2.h>
# include <Windows.h>

#endif // _WIN32

#include <algorithm>
#include <iostream>
#include "SocketPool.h"
#include "rtype_common.h"

SocketPool::SocketPool()
  : _alive(true), _watcher(*this, &SocketPool::watcher)
{
#ifdef _WIN32
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
		throw std::exception();
#endif // _WIN32

  this->_watcher.start();
}

SocketPool::~SocketPool()
{
  this->_alive = false;
  this->_c.signal();
  this->_watcher.join();
#ifdef _WIN32
  if (WSACleanup() == SOCKET_ERROR)
	  std::cerr << "WSACleanup() fail" << std::endl;
#endif // _WIN32
}

void  SocketPool::watchSocket(ISocket* s)
{
  this->_m.lock();
  this->_list.push_back(s);
  this->_c.signal();
  this->_m.unlock();
}

void  SocketPool::releaseSocket(ISocket* s)
{
  this->_m.lock();
  this->_list.remove(s);
  this->_m.unlock();
}

SocketPool::Setter::Setter(fd_set& rfds, fd_set& wfds, ISocket::SocketId& max)
  : _rfds(rfds), _wfds(wfds), _max(max)
{}

SocketPool::Setter::~Setter()
{}

void  SocketPool::Setter::operator()(ISocket *s)
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

SocketPool::Executer::Executer(const Executer& e)
  : _rfds(e._rfds), _wfds(e._wfds)
{}

SocketPool::Executer::~Executer()
{}

bool  SocketPool::Executer::operator()(ISocket *s)
{
  if (FD_ISSET(s->getId(), &this->_rfds))
    s->readFromSock();
  if (FD_ISSET(s->getId(), &this->_wfds))
    s->writeToSock();
  return (!s->isLive());
}

void			SocketPool::watcher()
{
  ISocket::SocketId	max;
  fd_set		rfds;
  fd_set		wfds;
  SocketPool::Setter    s(rfds, wfds, max);
  SocketPool::Executer	e(rfds, wfds);
  timeval		to;

  while (this->_alive)
  {
    if (!this->_list.empty())
    {
      max = -1;
      s.reset();
      to.tv_sec = SPTOSEC;
      to.tv_usec = SPTOUSEC;
      this->_m.lock();
      std::for_each<std::list<ISocket*>::iterator, SocketPool::Setter&>(this->_list.begin(), this->_list.end(), s);
      select(static_cast<int>(max + 1), &rfds, &wfds, NULL, &to);
      this->_list.remove_if(e);
      this->_m.unlock();
	  std::cout << to.tv_sec * 1000 + to.tv_usec / 1000 << std::endl;
     // Sleep(to.tv_sec * 1000 + to.tv_usec / 1000);
    }
  }
}
