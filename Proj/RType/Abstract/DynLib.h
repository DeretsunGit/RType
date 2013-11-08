//
// DynLib.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:28:04 2013 julien edmond
// Last update Fri Nov  8 16:36:05 2013 julien edmond
//

#pragma once

#ifdef	_WIN32

# include	"WinDynLib.h"

typedef WinDynLib	BasicDynLib;

#else

# include	"UnixDynLib.h"

typedef UnixDynLib	BasicDynLib;

#endif	// _WIN32

class	DynLib: public BasicDynLib
{
public:
  DynLib(const char* libName)
    : BasicDynLib(libName)
  {}

  ~DynLib()
  {}

  template<typename T>
  bool	getSym(const char* symName, T& dest)
  {
    return (BasicDynLib::getSym<T>(symName, dest));
  }

private:
  DynLib();
  DynLib(const DynLib&);
  DynLib&	operator=(const DynLib&);
};
