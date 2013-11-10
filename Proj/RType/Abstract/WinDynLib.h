//
// WinDynLib.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:25:55 2013 julien edmond
// Last update Fri Nov  8 16:26:14 2013 julien edmond
//

#ifdef	_WIN32

#include  <Windows.h>
#include  "IDynLib.h"

class	WinDynLib: public IDynLib
{
public:
  WinDynLib(const char* lib);
  ~WinDynLib();

  template<typename T>
  bool	getSym(const char* symName, T& dest)
  {
    FARPROC sym(GetProcAddress(this->_handler, symName));

    if (sym)
      dest = reinterpret_cast<T>(sym);
    return (sym != NULL);
  }

private:
  WinDynLib();
  WinDynLib(const WinDynLib&);
  WinDynLib&  operator=(const WinDynLib&);

  HMODULE _handler;
};

#endif	// _WIN32
