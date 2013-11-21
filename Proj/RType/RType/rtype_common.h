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

#define PATTERNFILE	"../ServerRessources/PatternList.txt"

#define LOOPTIME	16 // 16 would be a good value

#define MAXROOM		100
#define MAXCLIENT	400

#define LIGHT	0
#define	DARK	1

#define BLUE	0
#define RED		1
#define YELLOW	2
#define GREEN	3
#define WHITE	4

#define	WALL	0
#define PLAYER	1
#define ENNEMY	2

#define K_TOP	0
#define K_BOT	1
#define K_RIGHT	2
#define K_LEFT	3

typedef struct s_coord
{
	short _posX;
	short _posY;
} t_coord;

template<typename T>
T			strTo(const std::string& str)
{
  T			sent;
  std::istringstream	stream(str);

  stream >> sent;
  return (sent);
}
