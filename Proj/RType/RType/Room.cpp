#include <algorithm>
#include "Room.h"


Room::Room(void)
{
	this->_nbPlayer = 0;
}


Room::~Room(void)
{
}

bool	Room::addPlayer(Player* player)
{
	if (this->_nbPlayer < 4)
	{
		_party.push_back(player);
		++_nbPlayer;
		return (true);
	}
	return (false);
}

bool	Room::startGame()
{
	return (true);
}

bool	Room::removePlayer(int id)
{
	int i = 0;
	std::vector<Player*>::iterator ite = _party.begin();

	while (i < _nbPlayer)
	{
		if (_party[i]->getId() == id)
		{
			_party.erase(ite);
			--_nbPlayer;
			return (true);
		}
		++i;
		++ite;
	}
	return (false);
}

char	Room::getId() const
{
	return (this->_id);
}

char	Room::getNbPlayer() const
{
	return (this->_nbPlayer);
}
