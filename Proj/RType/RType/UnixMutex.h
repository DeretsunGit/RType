//
// UnixMutex.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:27:00 2013 julien edmond
// Last update Mon Oct 28 16:45:20 2013 julien edmond
//

#pragma once

#ifndef	_WIN32

# include	<pthread.h>
# include	<stdexcept>
# include	"IMutex.h"

class	UnixMutex: public IMutex
{
public:
  UnixMutex();
  ~UnixMutex();

  void	lock();
  void	unlock();
  bool	tryLock();

  operator pthread_mutex_t&();

private:
  pthread_mutex_t	_mutex;

  UnixMutex(const UnixMutex&);
  UnixMutex&	operator=(const UnixMutex&);
};

#endif // _WIN32
