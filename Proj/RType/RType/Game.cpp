#include "Game.h"

Game::Game()
{
	// on r�cup�re Script en argument
	// on r�cup�re de Script la map et les waves
	// on instancie les waves, les ennemis, et plein de bullets
	// 
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
			// parcourir pools jusqu'� trouver hp == 0
//			if (this->_globalMapTop[x] >= y || this->_globalMapBot[x] >= 18 - y)
//				this->_map[y][x].push_back(new Wall);
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
//		this->_wallPool.push_back(new Wall);
		i++;
	}
}

void	Game::gameLoop()
{
	// check �v�nements des joueurs + d�placements
	// d�placement de Waves en fonction du script
	// d�placement bullets
	// (pop de Wave)
	// send au client
	// timer pour �galiser le temps de boucle

}

void	Game::playerReset()
{
	int i = 0;

	while (i < this->_nbPlayers)
	{
		this->_players[i].setReady(1);
		i++;
	}
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}