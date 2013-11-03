//
// WinMutex.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:27:00 2013 julien edmond
// Last update Sat Oct 26 14:30:23 2013 julien edmond
//

#pragma once

#ifdef _WIN32

# include	<Windows.h>
# include	"IMutex.h"

class	WinMutex: public IMutex
{
public:
  WinMutex();
  ~WinMutex();

  void	lock();
  void	unlock();
  bool	tryLock();

  operator CRITICAL_SECTION&();

private:
  CRITICAL_SECTION	_cs;

  WinMutex(const WinMutex&);
  WinMutex&	operator=(const WinMutex&);
};

#endif // _WIN32
