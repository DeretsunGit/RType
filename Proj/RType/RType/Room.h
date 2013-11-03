#pragma once

#include "Client.h"

class Room
{
	// Thread	_th;
	// Player[4]	party;

public:
	Room();
	~Room();

	bool	addPlayer(Client);
	bool	startGame();
	bool	removePlayer();
};