//
// IMutex.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Sat Oct 26 14:28:25 2013 julien edmond
// Last update Mon Oct 28 16:24:19 2013 julien edmond
//

#pragma once

class	IMutex
{
public:
  virtual	~IMutex() {}

  virtual void	lock() = 0;
  virtual void	unlock() = 0;
  virtual bool	tryLock() = 0;
};
