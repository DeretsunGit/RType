#pragma once

#ifdef _WIN32

# include <Windows.h>
# include "ICondVar.h"

class	WinCondVar: public ICondVar
{
public:
  WinCondVar();
  ~WinCondVar();

  bool	wait(Mutex& mutex);
  bool	signal();
  bool	broadcast();
  bool	timedWait(Mutex& mutex, unsigned int msec);

private:
  CONDITION_VARIABLE  _cond;
};


#endif // _WIN32
