#pragma once

#include <vector>
#include <list>
#include <iterator>
#include "rtype_common.h"
#include "Player.h"
#include "Wave.h"
#include "Wall.h"
#include "Bullet.h"
#include "ServerCommunication.h"
#include "Clock.h"

class Game
{
	std::vector<Player*>	_players;
	std::list<Wave>			_livingThings;

	// maps
	// Script				_script;
	bool					_endGame;
	short int				_firstColumn;
	std::list<Element*>		_map[18][17]; // [hauteur y][largeur x]
	short int				_globalPos;
	char					_globalMapTop[256];
	char					_globalMapBot[256];

	// pools
	std::list<Wall*>		_wallPool;
	std::list<Bullet*>		_bulletPool;

public:
	Game();
	~Game();

	void	genPool();
	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();
	void	collision();
	void	sendPriority();
	void	getInputs();
	bool	isPlayerAlive();
	void	moveWall();
	void	playerShoot(Player *);
	void	moveBullets();
};