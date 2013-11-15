//
// WinThread.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:57:57 2013 julien edmond
// Last update Mon Oct 28 17:26:48 2013 julien edmond
//

#pragma once
#ifdef _WIN32

# include	<Windows.h>
# include	"Caller.hpp"
# include	"IThread.h"
# include	"WinSysException.h"

class WinThread: public IThread
{
public:
  template<typename Obj>
  WinThread(Obj& o, void (Obj::*m)())
    : _call(new MthdPtrCaller<Obj>(o, m)), _launched(false)
  {
    this->createThread();
  }

  template<typename Obj, typename Param>
  WinThread(Obj& o, void (Obj::*m)(Param), Param p)
    : _call(new MthdPtrCaller2<Obj, Param>(o, m, p)), _launched(false)
  {
    this->createThread();
  }

  template<typename Callable>
  WinThread(Callable& c)
    : _call(getCaller(c)), _launched(false)
  {
    this->createThread();
  }

  template<typename Callable, typename Param>
  WinThread(Callable c, Param p)
    : _call(new Caller<Callable, Param>(c, p)), _launched(false)
  {
    this->createThread();
  }

  WinThread(const WinThread&);
  WinThread&  operator=(const WinThread&);
  ~WinThread();

  bool	start();
  bool	join();
  bool	tryJoin();
  bool	timedJoin(unsigned int msec);
  bool	isLaunched() const;

private:
  void	      createThread();
  WinThread();

  HANDLE	_th;
  DWORD		_id;
  ICaller*	_call;
  bool		_launched;

  static DWORD WINAPI	_startRoutine(LPVOID param);
};

#endif // WIN32
