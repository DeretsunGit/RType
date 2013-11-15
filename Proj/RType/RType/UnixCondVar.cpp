//
// UnixCondVar.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Oct 28 16:31:55 2013 julien edmond
// Last update Mon Oct 28 16:57:54 2013 julien edmond
//

#ifndef		_WIN32
# include	"UnixCondVar.h"

UnixCondVar::UnixCondVar()
{
  if (pthread_cond_init(&this->_cond, NULL))
    throw std::runtime_error("Conditional variable creation failed"); // UNIXEXCEPT
}

UnixCondVar::~UnixCondVar()
{
  pthread_cond_destroy(&this->_cond);
}

bool	UnixCondVar::wait(Mutex& mutex)
{
  return (!pthread_cond_wait(&this->_cond,
			     &static_cast<pthread_mutex_t&>(mutex)));
}

bool	UnixCondVar::signal()
{
  return (!pthread_cond_signal(&this->_cond));
}

bool	UnixCondVar::broadcast()
{
  return (!pthread_cond_broadcast(&this->_cond));
}

bool			UnixCondVar::timedWait(Mutex& mutex, unsigned int msec)
{
  struct timespec	abstime;

  abstime.tv_sec = msec / 1000;
  abstime.tv_nsec = (msec % 1000) * 1000000;
  return (!pthread_cond_timedwait(&this->_cond,
				  &static_cast<pthread_mutex_t&>(mutex),
				  &abstime));
}

#endif		// !_WIN32
