//
// UnixDynLib.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:27:25 2013 julien edmond
// Last update Sun Nov 17 14:37:43 2013 julien edmond
//

#ifndef		_WIN32

# include	<iostream>
# include	<stdexcept>
# include	"UnixDynLib.h"
# include	"UnixSysException.h"

UnixDynLib::UnixDynLib(const char* libName)
{
  if (!(this->_handle = dlopen(libName, RTLD_NOW | RTLD_GLOBAL)))
    throw UnixSysException("DynLib: dlopen");
}

UnixDynLib::~UnixDynLib()
{
  if (dlclose(this->_handle))
    std::cerr << UnixSysException::GetError("~DynLib: dlcose") << std::endl;
}

#endif		// !_WIN32
