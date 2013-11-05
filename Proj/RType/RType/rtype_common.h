#pragma once

#include <list>
#include <iterator>

#ifdef _WIN32

#include <Windows.h>

#endif

#ifndef	_WIN32

# define Sleep(x)	usleep((x) * 1000)

#endif

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