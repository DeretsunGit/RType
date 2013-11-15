//
// UnixDynLib.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:27:25 2013 julien edmond
// Last update Fri Nov  8 16:43:21 2013 julien edmond
//

#ifndef		_WIN32

# include	<iostream>
# include	<stdexcept>
# include	"UnixDynLib.h"

UnixDynLib::UnixDynLib(const char* libName)
{
  if (!(this->_handle = dlopen(libName, RTLD_NOW | RTLD_GLOBAL)))
    throw std::runtime_error("DynLib: dlopen failed");// UNIXEXCEPT
}

UnixDynLib::~UnixDynLib()
{
  if (dlclose(this->_handle))
    std::cerr << "DynLib: dlclose failed" << std::endl; // UNIXEXCEPT
}

#endif		// !_WIN32
