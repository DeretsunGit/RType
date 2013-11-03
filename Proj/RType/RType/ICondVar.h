//
// ICondVar.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Mon Oct 28 16:23:55 2013 julien edmond
// Last update Mon Oct 28 16:58:23 2013 julien edmond
//

#pragma once

#include	"Mutex.h"

class	ICondVar
{
public:
  virtual	~ICondVar() {}

  virtual bool	wait(Mutex& mutex) = 0;
  virtual bool	signal() = 0;
  virtual bool	broadcast() = 0;
  virtual bool	timedWait(Mutex& mutex, unsigned int msec) = 0;
};
