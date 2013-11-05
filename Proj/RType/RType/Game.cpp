#include "Game.h"

Game::Game()
{
	this->_endGame = false;
	// on push back les player dans _collisionnableElem

	// on r�cup�re Script en argument
	// on r�cup�re de Script la map et les waves
	// on instancie les waves, les ennemis, et plein de bullets
	//
}

void	Game::mapGeneration()
{
	// gr�ce au script et � un fichier qui d�crit les patterns, on recompose la map globale
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
	// on g�n�re maintenant visibleMap
	i = 0;
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
						coord._posX = x;
						coord._posY = y;
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

	while (i <= 50)
	{
		this->_wallPool.push_back(new Wall);
		this->_bulletPool.push_back(new Bullet);
		i++;
	}
}

void	Game::gameLoop()
{
	while (this->_endGame != true)
	{
		// check �v�nements des joueurs + d�placements
		// UDPinterpretCommand(const char *data);
		// d�placement de Waves en fonction du script
		// d�placement bullets
		this->collision();
		// (pop de Wave)
		// send au client
		// UDPsendGameElements(const std::list<&Element>, const std::vector<&Player>);

		// timer pour �galiser le temps de boucle
	}
	// on dit aux clients de lancer l'ecran de fin (win ou lose)
}

void	Game::collision()
{
	std::list<Wall*>::iterator		it_wall;
	std::vector<t_coord>::iterator	it_coord;
	std::vector<Player*>::iterator	it_player;
	short int						x = 0;
	short int						y = 0;

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

void	Game::playerReset()
{
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}