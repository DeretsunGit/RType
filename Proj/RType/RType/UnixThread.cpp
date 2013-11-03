//
// UnixThread.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 15:06:49 2013 julien edmond
// Last update Mon Oct 28 17:28:07 2013 julien edmond
//

#ifndef	_WIN32

# include	<signal.h>
# include	<unistd.h>
# include	"UnixThread.h"

UnixThread::~UnixThread()
{
  if (this->_launched)
    pthread_cancel(this->_th);
  delete this->_call;
}

bool	UnixThread::start()
{
  if (this->_launched)
    return (false);
  return ((this->_launched = !pthread_create(&this->_th, NULL, &UnixThread::_startRoutine,
					     this->_call)));
}

bool	UnixThread::join()
{
  if (!this->_launched)
    return (false);
  return (!pthread_join(this->_th, NULL));
}

bool			UnixThread::timedJoin(unsigned int msec)
{
  struct timespec	abstime;

  if (!this->_launched)
    return (false);
  abstime.tv_sec = msec / 1000;
  abstime.tv_nsec = (msec % 1000) * 1000000;
  return (!pthread_timedjoin_np(this->_th, NULL, &abstime));
}

bool	UnixThread::tryJoin()
{
  if (!this->_launched)
    return (false);
  return (!pthread_tryjoin_np(this->_th, NULL));
}

void*		UnixThread::_startRoutine(void* param)
{
  ICaller*	call(static_cast<ICaller*>(param));

  if (call)
    call->call();
  return (0);
}

bool	UnixThread::isLaunched() const
{
  return (this->_launched);
}

#endif	// _WIN32
