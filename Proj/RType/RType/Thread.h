//
// Thread.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:58:25 2013 julien edmond
// Last update Thu Oct 24 15:11:46 2013 julien edmond
//

#pragma once

#ifdef _WIN32

# include "WinThread.h"

typedef WinThread BasicThread;

#else

# include "UnixThread.h"

typedef UnixThread BasicThread;

#endif // _WIN32

class Thread: public BasicThread
{
public:
  template<typename Obj>
  Thread(Obj& o, void (Obj::*m)())
    : BasicThread(o, m)
  {}

  template<typename Obj, typename Param>
  Thread(Obj& o, void (Obj::*m)(Param), Param p)
    : BasicThread(o, m, p)
  {}

  template<typename Callable>
  Thread(Callable& c)
    : BasicThread(c)
  {}

  template<typename Callable, typename Param>
  Thread(Callable c, Param p)
    : BasicThread(c, p)
  {}

private:
  Thread();
  Thread(const Thread&);
  Thread&	operator=(const Thread&);
};
