#pragma once

#include <string>
#include <list>
#include <iterator>
#include <iostream>

#ifdef _WIN32

# include <Windows.h>

# define _CRT_SECURE_NO_WARNINGS

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
	short _posX;
	short _posY;
} t_coord;