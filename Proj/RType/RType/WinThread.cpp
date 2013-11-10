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
  if (!(this->_th = CreateThread(NULL, 0, &this->_startRoutine, NULL, CREATE_SUSPENDED, &this->_id)))
      throw std::runtime_error("Thread creation failed");
  this->_call = w._call->clone();
}

WinThread::~WinThread()
{
  CloseHandle(this->_th);
  delete this->_call;
}

bool WinThread::start()
{
  return (ResumeThread(this->_th) != -1);
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

#endif	// _WIN32
