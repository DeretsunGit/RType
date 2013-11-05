#pragma once

#include <vector>
#include <list>
#include <iterator>
#include "Player.h"
#include "Wave.h"
#include "Wall.h"
#include "Bullet.h"

class Game
{
	std::vector<Player*>	_players;
	std::list<Wave>			_livingThings;

	// maps
	// Script				_script;
	bool					_endGame;
	std::list<Element*>		_map[18][17];
	char					_globalMapTop[256];
	char					_globalMapBot[256];

	// pools
	std::list<Wall*>		_wallPool;
	std::list<Bullet*>		_bulletPool;

public:
	// Game(Player players[4]);
	Game();
	~Game();

	void	genPool();
	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();
	void	collision();
};