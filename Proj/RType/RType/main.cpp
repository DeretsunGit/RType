//
// main.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:57:20 2013 julien edmond
// Last update Wed Nov  6 02:07:22 2013 maxime miramond
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
#include "TCPSocketClient.h"
#include "TCPSocketServer.h"
#include "UDPSocketServer.h"
#include "UDPSocketClient.h"

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
int		  main()
{
  // UDPSocketClient c("localhost", 1234);
  // char		  buff[255];
  // int		  ret;

  // c.send("Coucou les amis!\n", sizeof("Coucou les amis!\n"));
  // while (c.isLive())
  // {
  //   if ((ret = c.recv(buff, sizeof(buff))) > 0)
  //   {
  //     buff[ret] = 0;
  //     std::cout << "Received " << buff << std::flush;
  //     c.send(buff, ret);
  //   }
  // }

  UDPSocketServer s(1234);
  char		  buff[255];
  int		  ret;
  in_addr	  senderAddr;

  while (s.isLive())
  {
    if ((ret = s.recvFrom(buff, sizeof(buff), senderAddr)) > 0)
      {
	buff[ret] = 0;
	std::cout << "Received " << buff << std::flush;
	s.sendTo(buff, ret, senderAddr);
      }
  }

  std::cin.get();
  return (0);
}
