//
// WinMutex.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:26:23 2013 julien edmond
// Last update Sat Oct 26 14:26:24 2013 julien edmond
//

#ifdef _WIN32

#include "WinMutex.h"

WinMutex::WinMutex()
{
  InitializeCriticalSection(&this->_cs);
}

WinMutex::~WinMutex()
{
  DeleteCriticalSection(&this->_cs);
}

void  WinMutex::lock()
{
  EnterCriticalSection(&this->_cs);
}

void  WinMutex::unlock()
{
  LeaveCriticalSection(&this->_cs);
}

bool  WinMutex::tryLock()
{
  return (!!TryEnterCriticalSection(&this->_cs));
}

WinMutex::operator CRITICAL_SECTION&()
{
  return (this->_cs);
}

#endif // _WIN32
