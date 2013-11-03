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

class WinThread: public IThread
{
public:
  template<typename Obj>
  WinThread(Obj& o, void (Obj::*m)())
    : _call(new MthdPtrCaller<Obj>(o, m)), _launched(false)
  {
    if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, this->_call, CREATE_SUSPENDED, &this->_id)))
      throw std::runtime_error("Thread creation failed");
  }

  template<typename Obj, typename Param>
  WinThread(Obj& o, void (Obj::*m)(Param), Param p)
    : _call(new MthdPtrCaller2<Obj, Param>(o, m, p)), _launched(false)
  {
    if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, this->_call, CREATE_SUSPENDED, &this->_id)))
      throw std::runtime_error("Thread creation failed");
  }

  template<typename Callable>
  WinThread(Callable& c)
    : _call(NULL), _launched(false)
  {
    if (!(this->_th = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&c, NULL, CREATE_SUSPENDED, &this->_id)))
      throw std::runtime_error("Thread creation failed");
  }

  template<typename Callable, typename Param>
  WinThread(Callable c, Param p)
    : _call(new Caller<Callable, Param>(c, p)), _launched(false)
  {
    if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, this->_call, CREATE_SUSPENDED, &this->_id)))
      throw std::runtime_error("Thread creation failed");
  }

  ~WinThread();

  bool	start();
  bool	join();
  bool	tryJoin();
  bool	timedJoin(unsigned int msec);
  bool	isLaunched() const;

private:
  HANDLE	_th;
  DWORD		_id;
  ICaller*	_call;
  bool		_launched;

  static DWORD WINAPI	_startRoutine(LPVOID param);
};

#endif // WIN32
