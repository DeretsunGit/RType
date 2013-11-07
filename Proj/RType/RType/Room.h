#pragma once

#include <vector>
#include "Thread.h"
#include "Mutex.h"
#include "Player.h"

class Room
{
private:
	const char	_id;
	std::string	*_name; //limite 32
	std::string	*_map; //limite 128
	bool		_isRandom;
	std::vector<Player*> _party;
	char	_nbReady;
	char	_difficulty;

	Thread*	_th;
	Mutex	_m;
public:
	Room(char);
	~Room();

	void	roomLoop();
	bool	startGame();


	bool	addClient(Client*);
	bool	addPlayer(Player*);
	bool	removePlayer(int);
	bool	removeClient(int);

	char	getDifficulty() const;
	char	getId() const;
	char	getNbPlayer() const;
	std::string	getName() const;
	std::vector<Player*> getPlayers() const;

	bool	setMap(char *);
	bool	setName(char *);
	void	setId(char);
	void	setDifficulty(char);

	//Packet* TCPsendRoomList(const std::list<Room>& rooms) const;
};
