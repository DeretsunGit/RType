#pragma once

#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <sstream>

#ifdef _WIN32

# include <Windows.h>

#endif

#ifndef	_WIN32

# define Sleep(x)	usleep((x) * 1000)

#endif

#define DEBUGSTATE	8

#define PATTERNFILE	""

#define MAXROOM		100
#define MAXCLIENT	400

#define SHIELD_LIGHT	0
#define	SHILED_DARK		1

#define	WALL	0
#define PLAYER	1
#define ENNEMY	2

#define K_TOP	0
#define K_BOT	1
#define K_RIGHT	2
#define K_LEFT	3

typedef struct s_coord
{
	unsigned short _posX;
	unsigned short _posY;
} t_coord;

template<typename T>
T			strTo(const std::string& str)
{
  T			sent;
  std::istringstream	stream(str);

  stream >> sent;
  return (sent);
}
