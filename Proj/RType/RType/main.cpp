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
#include "WinTCPSocketServer.h"

#ifndef	_WIN32

# define Sleep(x)	usleep((x) * 1000)

#endif	// ! _WIN32
/*
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
*/
int	main()
{
	WinTCPSocketServer	winTCPSocketServer(1234, false);
	WinTCPSocketClient	*winTCPSocketClient;
	while (!(winTCPSocketClient = winTCPSocketServer.accept())){}

	std::cin.get();
	delete winTCPSocketClient;
	return (0);
}
