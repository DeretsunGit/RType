#pragma once

#include <vector>
#include "Game.h"
#include "Thread.h"
#include "Mutex.h"

class Room
{
private:
	std::string _name; //limite 32
	const char	_id;
	Thread*	_th;
	Mutex	_m;
	std::vector<Player*> _party;
	char	_nbReady;

public:
	Room(char);
	~Room();

	void	roomLoop();
	bool	startGame();

	bool	addClient(Client*);
	bool	addPlayer(Player*);
	bool	removePlayer(int);
	bool	removeClient(int);

	char	getId() const;
	char	getNbPlayer() const;
	std::string	getName() const;

	void	setName(char *);
	void	setId(char);
	Packet* TCPsendRoomList(const std::list<Room>& rooms) const; 
};