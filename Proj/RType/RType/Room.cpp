#include <algorithm>
#include "Room.h"


Room::Room()
{
//	this->_id;
//	this->_nbReady = 0;
}

Room::~Room(void)
{
}

bool	Room::addPlayer(Player* player)
{
	if (_party.size() < 4)
	{
		_party.push_back(player);
		return (true);
	}
	return (false);
}

bool	Room::startGame()
{
	Game newGame;
	// on instancie une game
	return (true);
}

bool	Room::removePlayer(int id)
{
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _party.size())
	{
		if (_party[i]->getId() == id)
		{
			_party.erase(ite);
			return (true);
		}
		++i;
		++ite;
	}
	return (false);
}

void	Room::roomLoop()
{
	/*
	while (this->_nbReady != _party.size())
	{
		// add les joueurs voulant join
		//	delete les joueurs qui partent / deco
	}*/
	startGame();
}

char	Room::getId() const
{
	return (this->_id);
}

char	Room::getNbPlayer() const
{
	return (_party.size());
}