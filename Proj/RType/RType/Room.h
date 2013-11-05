#pragma once

#include <vector>
#include "Client.h"
#include "Player.h"
#include "Game.h"

class Room
{
private:
	char	_id;
	// Thread	_th;
	std::vector<Player*> _party;
	char	_nbReady;

public:
	Room();
	~Room();

	bool	addPlayer(Player*);
	bool	startGame();
	bool	removePlayer(int id);
	char	getId() const;
	char	getNbPlayer() const;
	void	roomLoop();
	Packet* TCPsendRoomList(const std::list<Room>& rooms) const; 
};