#pragma once

#include <list>
#include "Player.h"
#include "Wave.h"
#include "Wall.h"
#include "Bullet.h"

class Game
{
	Player				_players[4];
	short int			_nbPlayers;
	std::list<Wave>		_livingThings;

	// maps
	// Script			_script;
	std::list<Element*>	_map[18][17];
	char				_globalMapTop[256];
	char				_globalMapBot[256];

	// pools
	std::list<Wall*>	_wallPool;
	std::list<Ennemy>	_ennemyPool;
	std::list<Bullet*>	_bulletPool;

public:
	// Game(Player players[4]);
	Game();
	~Game();

	void	genPool();
	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();
};