//
// UnixDynLib.h for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:26:53 2013 julien edmond
// Last update Fri Nov  8 16:47:41 2013 julien edmond
//

#pragma once

#ifndef	_WIN32

# include	<dlfcn.h>
# include	"IDynLib.h"

class	UnixDynLib: public IDynLib
{
public:
  UnixDynLib(const char* libName);
  ~UnixDynLib();

  template<typename T>
  bool		getSym(const char* symName, T& dest)
  {
    void	*sym(dlsym(this->_handle, symName));

    if (sym)
      dest = reinterpret_cast<T>(sym);
    return (sym);
  }

private:
  UnixDynLib();
  UnixDynLib(const UnixDynLib&);
  UnixDynLib&	operator=(const UnixDynLib&);

  void*	_handle;
};

#endif	// !_WIN32
