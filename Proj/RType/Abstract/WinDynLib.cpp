//
// WinDynLib.cpp for RType in /home/edmond_j//rendu/B5/Rtype/RType/Proj/RType/Abstract
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Fri Nov  8 16:26:21 2013 julien edmond
// Last update Fri Nov  8 16:26:48 2013 julien edmond
//

#ifdef		_WIN32

# include	<iostream>
# include	<stdexcept>
# include	"WinDynLib.h"
# include	"WinSysException.h"

WinDynLib::WinDynLib(const char* libName)
  : _handler(LoadLibrary(libName))
{
  if (!this->_handler)
    throw WinSysException("DynLib");
}

WinDynLib::~WinDynLib()
{
  if (FreeLibrary(this->_handler))
    std::cerr << WinSysException::GetError("~DynLib: FreeLibrary") << std::endl;
}

#endif		// _WIN32
