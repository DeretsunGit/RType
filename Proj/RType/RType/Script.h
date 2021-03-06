#pragma once

#include <map>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include "rtype_common.h"
#include "Wave.hpp"
#include "Script.h"
#include "Randomization.hpp"

typedef struct	s_scriptWave
{
	Clock	_time;
	// stockage de wave, si possible un truc genre enum mais dynamique
}				t_scriptWave;

typedef struct s_scriptMap
{
	std::string		_topMap;
	std::string		_botMap;
}				t_scriptMap;

typedef struct	s_pattern
{
	bool		_isTop;
	char		_id;
	char		_len;
	std::string	_elemHeight;
}				t_pattern;

class Script
{
	bool			_isRandom;
	short int		_mapSize;
	std::list<t_scriptWave *>	_waveList;
	t_scriptMap		_map;
	std::ifstream	*_patternFile;
	std::ifstream	*_scriptFile;
	std::vector<t_pattern> _patternList;
	Randomization<char>		*_rand;

public:
	Script();
	~Script(void);
	void			LoadMap(std::string *);

	void			interpretMap();
	//random
	void			makeRandomScript();
	void			setRandomMap();
	t_scriptWave	*setRandomWave();
	bool			getPattern();
	std::vector<t_pattern>	getPatternList();

	//chargement
	//void	getScript();
	t_scriptMap		*getMap();
	t_scriptWave	*getWave();
	//std::string		getScriptFile();
	bool			getRandom() const;
	
	void			setScriptFile(std::string *);
	void			setRandom(bool);
	void			setPatternList(std::vector<t_pattern>);

	void			genFile();
};

