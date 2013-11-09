#pragma once
#include "rtype_common.h"
#include "Wave.h"

typedef struct	s_scriptWave
{
	short int	_time;
	// stockage de wave, si possible un truc genre enum mais dynamique
}				t_scriptWave;

typedef struct s_scriptMap
{
	char *		_topMap;
	char *		_botMap;
}				t_scriptMap;

class Script
{
	bool			_isRandom;
	short int		_mapSize;
	std::list<t_scriptWave *>	_waveList;
	s_scriptMap		_map;
	std::string		_patternFile;
	std::string		_scriptFile;

public:
	Script(void);
	~Script(void);

	//random

	//chargement
};

