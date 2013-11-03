#include "Game.h"

Game::Game()
{
	this->_end = false;
	this->_nbPlayers = 4;
	// on r�cup�re Script en argument
	// on r�cup�re de Script la map et les waves
	this->mapGeneration();
	this->playerReset();
	// on instancie les waves, les ennemis, et plein de bullets
	// on lance la gameloop
	this->gameLoop();

}

void	Game::mapGeneration()
{
	// gr�ce au script et � un fichier qui d�crit les patterns, on recompose la map globale
	short int i = 0;
	short int x = 0;
	short int y = 0;

	while (i < 256)
	{
		this->_globalMapTop[i] = '2';
		this->_globalMapBot[i] = '2';
		i++;
	}
	// on g�n�re maintenant visibleMap
	i = 0;
	while (y < 18)
	{
		x = 0;
		while (x < 17)
		{
			if (this->_globalMapTop[x] >= y)
				this->_visibleMap[y][x] = '1';
			else if (this->_globalMapBot[x] >= 18 - y)
				this->_visibleMap[y][x] = '1';
			else
				this->_visibleMap[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	Game::gameLoop()
{
	while (this->_end != true)
	{
	// check �v�nements des joueurs + d�placements
		this->movePlayers();
	// d�placement de Waves en fonction du script
	// d�placement bullets
	// (pop de Wave)
	// si il le faut, ge�n�ration de la suite de la visible map
	// send au client
	// timer pour �galiser le temps de boucle
	}
	// ecran de fin, + menus
}

void Game::movePlayers()
{
	int i = 0;

	while (i < this->_nbPlayers)
	{
		this->_players[i].move();
		this->_players[i].isColision(this->_visibleMap);
		i++;
	}
}


void	Game::playerReset()
{
	int i = 0;

	while (i < this->_nbPlayers)
	{
		this->_players[i].setReady(1);
		this->_players[i].setScore(0);
		i++;
	}
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}