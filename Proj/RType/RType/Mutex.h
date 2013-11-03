//
// Mutex.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:27:33 2013 julien edmond
// Last update Sat Oct 26 14:27:52 2013 julien edmond
//

#pragma once

#ifdef _WIN32

# include "WinMutex.h"

typedef WinMutex	BasicMutex;

#else

# include "UnixMutex.h"

typedef UnixMutex	BasicMutex;

#endif // _WIN32

class	Mutex: public BasicMutex
{
public:
  Mutex() {}
  ~Mutex() {}

private:
  Mutex(const Mutex&);
  Mutex&	operator=(const Mutex&);
};

class ScopedLock
{
public:
  ScopedLock(Mutex& m)
    : _m(m)
  {
    this->_m.lock();
  }

  ~ScopedLock()
  {
    this->_m.unlock();
  }

private:
  ScopedLock(const ScopedLock&);
  ScopedLock& operator=(const ScopedLock&);

  Mutex&  _m;
};