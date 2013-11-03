#pragma once

#include <list>
#include "Player.h"
#include "Wave.h"

class Game
{
	bool				_end;
	Player				_players[4];
	short int			_nbPlayers;
	// Script			_script;
	std::list<Wave>		_livingThings;
	char				_visibleMap[18][17];
	char				_globalMapTop[256];
	char				_globalMapBot[256];

public:
	// Game(Player players[4]);
	Game();
	~Game();

	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();

	void movePlayers();
};