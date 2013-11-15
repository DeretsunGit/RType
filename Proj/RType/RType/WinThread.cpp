//
// WinThread.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:57:12 2013 julien edmond
// Last update Mon Oct 28 17:27:04 2013 julien edmond
//

#ifdef	_WIN32

# include <stdexcept>
# include "WinThread.h"

WinThread::WinThread(const WinThread& w)
  : _launched(false)
{
  this->_call = w._call->clone();
  if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, this->_call, CREATE_SUSPENDED, &this->_id)))
  {
    delete this->_call;
    throw WinSysException("WinThread: CreateThread");
  }
}

WinThread::~WinThread()
{
  TerminateThread(this->_th, 0);
  CloseHandle(this->_th);
  delete this->_call;
}

bool WinThread::start()
{
  return ((this->_launched = (ResumeThread(this->_th) != -1)));
}

bool WinThread::join()
{
  return (WaitForSingleObject(this->_th, INFINITE) == WAIT_OBJECT_0);
}

bool WinThread::timedJoin(unsigned int msec)
{
  return (WaitForSingleObject(this->_th, msec) == WAIT_OBJECT_0);
}

bool WinThread::tryJoin()
{
  return (WaitForSingleObject(this->_th, 0) == WAIT_OBJECT_0);
}

bool WinThread::isLaunched() const
{
  return (this->_launched);
}

DWORD WINAPI	WinThread::_startRoutine(LPVOID param)
{
  ICaller*	call(static_cast<ICaller*>(param));

  if (call)
    call->call();
  return (0);
}

void  WinThread::createThread()
{
  if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, this->_call, CREATE_SUSPENDED, &this->_id)))
    throw WinSysException("WinThread: CreateThread");
}

#endif	// _WIN32
