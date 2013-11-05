#pragma once

#include <list>
#include <iterator>
#include <Windows.h>

#ifndef	_WIN32

# define Sleep(x)	usleep((x) * 1000)

#endif

#define K_TOP	0
#define K_BOT	1
#define K_RIGHT	2
#define K_LEFT	3

typedef struct s_coord
{
	short _posX;
	short _posY;
} t_coord;