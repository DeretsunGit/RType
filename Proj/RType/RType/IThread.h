//
// IThread.h for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:58:41 2013 julien edmond
// Last update Mon Oct 28 17:27:53 2013 julien edmond
//

#pragma once

class IThread
{
public:
  virtual ~IThread() {}

  virtual bool	start() = 0;
  virtual bool	join() = 0;
  virtual bool	tryJoin() = 0;
  virtual bool	timedJoin(unsigned int msec) = 0;
  virtual bool	isLaunched() const = 0;
};
