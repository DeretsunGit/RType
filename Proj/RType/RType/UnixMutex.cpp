//
// UnixMutex.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:26:23 2013 julien edmond
// Last update Sun Nov 17 14:51:34 2013 julien edmond
//

#ifndef _WIN32

# include	"UnixMutex.h"
# include	"UnixSysException.h"

UnixMutex::UnixMutex()
{
  if (pthread_mutex_init(&this->_mutex, NULL))
    throw UnixSysException("Mutex: pthread_mutex_init");
}

UnixMutex::~UnixMutex()
{
  pthread_mutex_destroy(&this->_mutex);
}

void  UnixMutex::lock()
{
  pthread_mutex_lock(&this->_mutex);
}

void  UnixMutex::unlock()
{
  pthread_mutex_unlock(&this->_mutex);
}

bool  UnixMutex::tryLock()
{
  return (!pthread_mutex_trylock(&this->_mutex));
}

UnixMutex::operator	pthread_mutex_t&()
{
  return (this->_mutex);
}

#endif // _WIN32
