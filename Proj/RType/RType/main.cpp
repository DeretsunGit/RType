//
// main.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:57:20 2013 julien edmond
// Last update Mon Oct 28 17:24:57 2013 julien edmond
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include "Thread.h"
#include "Mutex.h"
#include "CondVar.h"
#include "IOBuff.h"
#include "Vector2.hpp"

#ifndef	_WIN32

# define Sleep(x)	usleep((x) * 1000)

#endif	// ! _WIN32

Mutex	g_m;
CondVar	g_c;
int	count = 0;

void	inc_count(long id)
{
  int	i(0);

  while (i < 10)
    {
      g_m.lock();
      if (++count == 12)
	{
	  g_c.signal();
	  std::cout << "Count thread " << id << ", count = " << count
		    << " cond reached" << std::endl;
	}
      std::cout << "Count thread " << id << ", count = " << count
		<< " unlocking mutex" << std::endl;
      ++i;
      g_m.unlock();
      Sleep(1000);
    }
}

void	watch_count(long id)
{
  std::cout << "Starting watch" << std::endl;
  g_m.lock();
  while (count < 12)
    {
      g_c.wait(g_m);
      std::cout << "Watcher thread " << id << ", signal received" << std::endl;
      count += 125;
      std::cout << "Watcher thread " << id << " new count val: " << count
		<< std::endl;
    }
  g_m.unlock();
}

int	main()
{
/*  Thread	watcher(&watch_count, 0);
  Thread	inc1(&inc_count, 1);
  Thread	inc2(&inc_count, 2);

  watcher.start();
  inc1.start();
  inc2.start();
  watcher.join();
  inc1.join();
  inc2.join();*/

  IOBuff<>   b;
  char			    buff[7];

  memset(buff, 0, sizeof(buff));
  b._input.writeSome("coucou", 7);
  std::cout << b._input.readableSize() << '/' << b._input.getSize() << std::endl;
  b._input.readSome(buff, sizeof(buff));
  std::cout << buff << std::endl;
  std::cin.get();
  return (0);
}
