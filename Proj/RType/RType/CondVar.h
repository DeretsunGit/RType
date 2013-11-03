//
// CondVar.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Oct 28 16:54:31 2013 julien edmond
// Last update Mon Oct 28 17:08:47 2013 julien edmond
//

#pragma once

#ifdef	_WIN32

# include "WinCondVar.h"

typedef WinCondVar	BasicCondVar;

#else

# include "UnixCondVar.h"

typedef UnixCondVar	BasicCondVar;

#endif // _WIN32

class	CondVar: public BasicCondVar
{
public:
  CondVar() {}
  ~CondVar() {}

private:
  CondVar(const CondVar&);
  CondVar&	operator=(const CondVar&);
};
