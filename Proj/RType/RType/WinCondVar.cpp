#ifdef _WIN32

# include "WinCondVar.h"

WinCondVar::WinCondVar()
{
  InitializeConditionVariable(&this->_cond);
}

WinCondVar::~WinCondVar()
{}

bool  WinCondVar::wait(Mutex& m)
{
  return (!!SleepConditionVariableCS(&this->_cond, &static_cast<CRITICAL_SECTION&>(m), INFINITE));
}

bool  WinCondVar::signal()
{
  WakeConditionVariable(&this->_cond);
  return (true);
}

bool WinCondVar::broadcast()
{
  WakeAllConditionVariable(&this->_cond);
  return (true);
}

bool  WinCondVar::timedWait(Mutex& m, unsigned int msec)
{
  return (!!SleepConditionVariableCS(&this->_cond, &static_cast<CRITICAL_SECTION&>(m), msec));
}

#endif // _WIN32
