#include "Game.h"

Game::Game()
{
	this->_endGame = false;
	this->_firstColumn = 0;
	// on récupère Script en argument
	// on récupère de Script la map et les waves
	// on instancie les waves, les ennemis, et plein de bullets
	//
}

void	Game::mapGeneration()
{
	// grâce au script et à un fichier qui décrit les patterns, on recompose la map globale
	short int					i = 0;
	short int					x = 0;
	short int					y = 0;
	t_coord						coord;
	std::list<Wall*>::iterator	it;

	while (i < 256)
	{
		this->_globalMapTop[i] = '2';
		this->_globalMapBot[i] =	 '2';
		i++;
	}
	// on génère maintenant visibleMap
	while (y < 18)
	{
		x = 0;
		while (x < 17)
		{
			if (this->_globalMapTop[x] >= y || this->_globalMapBot[x] >= 18 - y)
			{
				for (it = (this->_wallPool).begin(); it != (this->_wallPool).end(); it++)
				{
					if ((*it)->getHP() == 0)
					{
						this->_map[y][x].push_back(*it);
						(*it)->setHP(1);
						coord._posX = x * 100;
						coord._posY = y * 50;
						(*it)->addToCurrentCell(coord);
					}
				}
			}
			x++;
		}
		y++;
	}
}

void	Game::genPool()
{
	int i = 0;

	while (i <= 100)
	{
		this->_wallPool.push_back(new Wall);
		this->_bulletPool.push_back(new Bullet);
		i++;
	}
}

void	Game::gameLoop()
{
	Clock	loopTimer;
	float	execTime;

	while (this->_endGame != true)
	{
		loopTimer.initialise();
		// check évènements des joueurs + déplacements DONE
		this->getInputs();
		// déplacement de Waves en fonction du script
		// déplacement bullets
		this->collision();
		// (pop de Wave)
		// send au client DONE
		this->sendPriority();
		// timer pour égaliser le temps de boucle DONE
		this->_endGame = !this->isPlayerAlive();
		execTime = loopTimer.getTimeBySec();
		Sleep(16 - execTime);
	}
	// on dit aux clients de lancer l'ecran de fin (win ou lose)
}

void	Game::collision()
{
	std::list<Wall*>::iterator		it_wall;
	std::vector<t_coord>::iterator	it_coord;
	std::vector<Player*>::iterator	it_player;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				for (it_coord = ((*it_wall)->getCurrentCell()).begin(); it_coord != ((*it_wall)->getCurrentCell()).end(); it_coord++)
					(*it_wall)->isCollision(_map[(*it_coord)._posY][(*it_coord)._posX]);
			}
		}
	for (it_player = (this->_players).begin(); it_player != (this->_players).end(); it_player++)
		{
			if ((*it_player)->getHP() != 0)
			{
				for (it_coord = ((*it_player)->getCurrentCell()).begin(); it_coord != ((*it_player)->getCurrentCell()).end(); it_coord++)
					(*it_player)->isCollision(_map[(*it_coord)._posY][(*it_coord)._posX]);
			}
		}
}

void	Game::sendPriority()
{
	std::list<Element *>	elemToSend;
	std::list<Wall*>::iterator		it_wall;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				elemToSend.push_back(*it_wall);
			}
		}
	// UDPsendGameElements(const std::list<Element*>, const std::vector<&Player>);
	 //UDPsendGameElements(elemToSend, _players);

}

void	Game::getInputs()
{
		// interpretCommand(const char *data);
}

void	Game::playerReset()
{
}

bool	Game::isPlayerAlive()
{
	std::vector<Player*>::iterator	it_player;

	for (it_player = (this->_players).begin(); it_player != (this->_players).end(); it_player++)
		{
			if ((*it_player)->getHP() != 0)
			{
				return (true);
			}
		}
	return (false);
}

void	Game::MoveWall()
{
	bool							decal = false;
	t_coord							temp;
	std::list<Wall*>::iterator		it_wall;
	short int						y = 0;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			// on move tous les murs actifs
			if ((*it_wall)->getHP() != 0)
			{
				temp._posX = (*it_wall)->getPos()._posX - 3;
				temp._posY = (*it_wall)->getPos()._posY;
				(*it_wall)->setPos(temp);
			}
			// on supprime les murs inactifs et on set les nouveaux murs
			if ((*it_wall)->getPos()._posX == -100)
			{
				decal = true;
				(*it_wall)->setHP(0);

			}
		}
	if (decal == true)
	{
		while (y < 18)
		{
				if (this->_globalMapTop[this->_globalPos] >= y || this->_globalMapBot[this->_globalPos] >= 18 - y)
				{
					for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
					{
						if ((*it_wall)->getHP() == 0)
						{
							this->_map[y][_firstColumn].push_back(*it_wall);
							(*it_wall)->setHP(1);
							temp._posX = 1600;
							temp._posY = y * 50;
							(*it_wall)->addToCurrentCell(temp);
						}
					}
			}
			y++;
		}
		this->_globalPos ++;
		if (this->_firstColumn <= 16)
			this->_firstColumn++;
		else
			this->_firstColumn = 0;
	}
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}