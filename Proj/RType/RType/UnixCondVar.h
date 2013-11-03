//
// UnixCondVar.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Oct 28 16:28:55 2013 julien edmond
// Last update Mon Oct 28 16:58:17 2013 julien edmond
//

#pragma once

#ifndef		_WIN32

# include	<pthread.h>
# include	"ICondVar.h"

class	UnixCondVar: public ICondVar
{
public:
  UnixCondVar();
  ~UnixCondVar();

  bool	wait(Mutex& mutex);
  bool	signal();
  bool	broadcast();
  bool	timedWait(Mutex& mutex, unsigned int msec);

private:
  UnixCondVar(const UnixCondVar&);
  UnixCondVar&	operator=(const UnixCondVar&);

  pthread_cond_t	_cond;
};

#endif		// !_WIN32
