//
// UnixThread.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:59:44 2013 julien edmond
// Last update Mon Oct 28 17:27:22 2013 julien edmond
//

#pragma once
#ifndef _WIN32

# include	<stdexcept>
# include	<pthread.h>
# include	"IThread.h"
# include	"Caller.hpp"

class UnixThread: public IThread
{
public:
  template<typename Obj>
  UnixThread(Obj& o, void (Obj::*m)())
    : _call(new MthdPtrCaller<Obj>(o, m)), _launched(false)
  {}

  template<typename Obj, typename Param>
  UnixThread(Obj& o, void (Obj::*m)(Param), Param p)
    : _call(new MthdPtrCaller2<Obj, Param>(o, m, p)), _launched(false)
  {}

  template<typename Callable>
  UnixThread(Callable& c)
    : _call(new BasicCaller<Callable>(c)), _launched(false)
  {}

  template<typename Callable, typename Param>
  UnixThread(Callable c, Param p)
    : _call(new Caller<Callable, Param>(c, p)), _launched(false)
  {}

  UnixThread(const UnixThread&);
  UnixThread& operator=(const UnixThread&);
  ~UnixThread();

  bool	start();
  bool	join();
  bool	tryJoin();
  bool	timedJoin(unsigned int msec);
  bool	isLaunched() const;

private:
  UnixThread();

  pthread_t	_th;
  ICaller*	_call;
  bool		_launched;

  static void*	_startRoutine(void* param);
};

#endif // WIN32
