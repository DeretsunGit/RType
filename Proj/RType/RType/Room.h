#pragma once

#include <vector>
#include "Client.h"
#include "Player.h"

class Room
{
private:
	char	_nbPlayer;
	char	_id;
	// Thread	_th;
	std::vector<Player*> _party;

public:
	Room();
	~Room();

	bool	addPlayer(Player*);
	bool	startGame();
	bool	removePlayer(int id);
	char	getId() const;
	char	getNbPlayer() const;
};