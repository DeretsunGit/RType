#include <iostream>
#include "Game.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<Room>;

Game::Game(const std::vector<Player*>& p, Script *s, UDPSocketServer * UDPsock)
  : _players(p), _script(s), _udpSock(UDPsock)
{
	this->_GameCom.setCallback(0x0D, &Game::inputs);
	this->_GameCom.setCallback(0x0E, &Game::pauseOk);
	this->_GameCom.setDefaultCallback(&Game::callBackError);
	this->_GameCom.setHandler(this);

	this->_endGame = false;
	this->_firstColumn = 0;
	this->_globalPos = 17;
	this->genPool();

	std::cout << "Pools fully created" << std::endl;
	this->mapGeneration();
	std::cout << "Map generation finished !" << std::endl;
	this->startGame();
	std::cout << "___________________Loop starting________________________" << std::endl;
	this->gameLoop();
}

void	Game::callBackError(char opcode, IReadableSocket&)
{
		std::cout << "Impossible Action : callback with opcode " << std::hex << opcode;
	std::cout << " can't be done while Game is already lauched" << std::endl;
	this->sendError(61, "You can't perform this action by now.");
}

void	Game::inputs(void *data)
{

}

void	Game::pauseOk(void *data)
{

}

void		Game::sendError(char errorCode, const char *message)
{
	this->_GameCom.TCPsendError(this->_pack, errorCode, message);
}

void	Game::TCPsend(Packet& tosend)
{
  std::cout << __LINE__ << std::endl;
	std::vector<Player*>::const_iterator	it_player(this->_players.begin());
  std::cout << __LINE__ << std::endl;
	std::vector<Player*>::const_iterator	end(this->_players.end());
  std::cout << __LINE__ << std::endl;

  if (tosend.getSize())
  {
    while (it_player != end)
    {
      std::cout << (*it_player)->getClient() << '|' << (*it_player)->getClient()->getTCPSock() << std::endl;
	  (*it_player)->getClient()->getTCPSock()->send(tosend);
      ++it_player;
    }
  }
}

void	Game::mapGeneration()
{
	bool						assign = false;
	short int					i = 0;
	short int					x = 0;
	short int					y = 0;
	t_coord						coord;
	std::list<Wall*>::iterator	it;

	// on génère maintenant visibleMap
		while (x < 17)
		{
			// on parcours topmap
			y = 0;
			while (y < atoi(this->_script->getMap()->_topMap.substr(x, 1).c_str()))
			{
				assign = false;
				it = (this->_wallPool).begin();
				while ( it != (this->_wallPool).end() && assign == false)
				{
					if ((*it)->getHP() == 0)
					{
						coord._posX = x;
						coord._posY = y;
						assign = assignWall(*it, false, coord, true);
					}
					it ++;
				}
				y++;
			}
			y = 17;
			while (y > 17 - atoi(this->_script->getMap()->_botMap.substr(x, 1).c_str()))
			{
				assign = false;
				it = (this->_wallPool).begin();
				while ( it != (this->_wallPool).end() && assign == false)
				{
					if ((*it)->getHP() == 0)
					{
						coord._posX = x;
						coord._posY = y;
						assign = assignWall(*it, false, coord, false);
					}
					it ++;
				}
				y--;
			}
			x++;
		}
	std::cout << "finished !" << std::endl;
}

void	Game::genPool()
{
	int i = 0;

	while (i <= 200)
	{
		this->_wallPool.push_back(new Wall);
		this->_bulletPool.push_back(new Bullet);
		i++;
	}
}

bool	Game::startGame()
{
	/*unsigned short i = 1;
	// On gère l'attente des players
	// Lorsqu'on recoit des packets TCP, on les traite ici
	Packet* tmp = NULL; // tmp sera remplacé par le vrai packet recu

/*	if (_com.TCPgetReady(tmp->getBuffer()))
		;// la méthode retourne vrai, le joueur a donc envoyé ready
	else
		;// la méthode retourne false, le joueur a envoyé un packet eronné
	// si tous les joueurs sont prêts
	Packet* pack = _com.TCPsendStartGame();
	if (pack != NULL)
	  TCPsend(pack);
	delete pack;*/
	return (true);
}

void	Game::gameLoop()
{
	Clock	loopTimer;
	float	execTime;

	std::cout << "entering the mysterious arcanes of gameloop" << std::endl; 
	while (this->_endGame != true)
	{
	//	std::cout << "loop" << std::endl;
		loopTimer.initialise();
		this->getInputs();
		// déplacement de Waves en fonction du script
	//	this->moveBullets();
		this->moveWall();
		this->collision();
		// (pop de Wave)
		this->sendPriority();
		if (this->_globalPos == 256 || this->isPlayerAlive() == false)
			this->_endGame = true;
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(GAMELOOPTIME - execTime));
		this->_udpSock->broadcast(this->_pack);
	}
}

void	Game::collision()
{
	int										collision_ret;
	std::list<Wall*>::iterator				it_wall;
	std::vector<t_coord>::const_iterator	it_coord;
	std::vector<Player*>::const_iterator	it_player;
	std::vector<t_coord>					shittyvar_currentcelll;


	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				shittyvar_currentcelll = ((*it_wall)->getCurrentCell());
				for (it_coord = shittyvar_currentcelll.begin(); it_coord != shittyvar_currentcelll.end(); it_coord++)
					{
						if ((collision_ret = (*it_wall)->isCollision(_map[(*it_coord)._posY][(*it_coord)._posX])) != -1)
						{
							// collision entre *it_wall et l'objet d'id collision_ret
						}
				}
			}
		}
	for (it_player = (this->_players).begin(); it_player != (this->_players).end(); it_player++)
		{
			if ((*it_player)->getHP() != 0)
			{
				shittyvar_currentcelll = ((*it_player)->getCurrentCell());
				for (it_coord = shittyvar_currentcelll.begin(); it_coord != shittyvar_currentcelll.end(); it_coord++)
					{
						if ((collision_ret = (*it_player)->isCollision(_map[(*it_coord)._posY][(*it_coord)._posX])) != -1)
						{
								// collision entre *it_player et l'objet d'id collision_ret
						}
					}
			}
		}
	//ajouter ennemis
}

void	Game::sendPriority()
{
	short int					maxPriority = 0;
	std::list<Element *>		elemToSend;
	std::list<Wall*>::iterator		it_wall;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				//if ((*it_wall)->getSendPriority() > maxPriority)
				//	maxPriority = (*it_wall)->getSendPriority();
				/*if (elemToSend.size() < 100)
					{*/
						elemToSend.push_back(*it_wall);
				//		(*it_wall)->setSendPriority(2);
				//	}
				/*else
					(*it_wall)->setSendPriority((*it_wall)->getSendPriority() + 1);
*/			}
		}
	// ajouter les ennemis et les bullets
	std::list<Element *>::iterator	it = elemToSend.begin();
	int i = 0;
	while (it != elemToSend.end())
	{
		i++;
//		std::cout << (*it)->getPos()._posX << std::endl;
		it++;
	}
	//std::cout << "Sended " << i << "Walls" << std::endl;
	this->_GameCom.UDPscreenState(this->_pack, 0, elemToSend);
	// UDPsendGameElements(const std::list<Element*>, const std::vector<&Player>);
	// on déclare un Packet qui va etre alloué dans la méthode
	//Packet pack;
	//_com.UDPsendGameElements(pack, elemToSend, this->_players);

	// ici, pack contient les données sérialisées à écrire sur la socket.
}

void	Game::getInputs()
{
	//  !! ceci fonctionne pour 1 joueur !!
	//s_inputs inputs;
	char *buff = NULL;
	// recuperer les packets sur la socket
	// passer en paramètre de la fonction le buffer du packet
	// remplacé ici par un buffer vide
	//_com.UDPinterpretInputs(inputs, buff);

	// ici la struct inputs contient les inputs utilisateur
	// comme définie dans la RFC.
}

void	Game::moveBullets()
{
	std::list<Bullet*>::iterator		it_bullet;
	short int						y = 0;

	for (it_bullet = (this->_bulletPool).begin(); it_bullet != (this->_bulletPool).end(); it_bullet++)
		{
			if ((*it_bullet)->getHP() != 0)
			{
				// on check le mouvement de la bullet et on fait la translation correspondante
			}
		}
}

void Game::playerShoot(Player *currentPlayer)
{
	std::list<Bullet*>::iterator		it_bullet;

	for (it_bullet = (this->_bulletPool).begin(); it_bullet != (this->_bulletPool).end(); it_bullet++)
	{
		if ((*it_bullet)->getHP() == 0)
		{
		  //			(*it_bullet)->setPos(&(currentPlayer->getPos())); // faux car tir en haut a gauche
			(*it_bullet)->setHP(1);
			(*it_bullet)->setFaction(PLAYER);
		}
	}
}

void	Game::playerReset()
{
}

bool	Game::isPlayerAlive()
{
	std::vector<Player*>::const_iterator	it_player;

	for (it_player = (this->_players).begin(); it_player != (this->_players).end(); it_player++)
		{
			if ((*it_player)->getHP() != 0)
			{
				return (true);
			}
		}
	return (false);
}

void	Game::moveWall()
{
	bool							assign = false;
	bool							decal = false;
	t_coord							temp;
	std::list<Wall*>::iterator		it_wall;
	short int						y = 0;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				temp._posX = (*it_wall)->getPos()._posX - (2 * (*it_wall)->getSpeed());
				temp._posY = (*it_wall)->getPos()._posY;
				(*it_wall)->setPos(&temp);
				if ((*it_wall)->getPos()._posX <= -100 )
				{
					temp._posX = 0;
					temp._posY = 0;
					decal = true;
					(*it_wall)->setHP(0);
					(*it_wall)->setPos(&temp);
					(*it_wall)->setSendPriority(2);
					this->_map[((*it_wall)->getCurrentCell().front()._posY)][((*it_wall)->getCurrentCell().front()._posX)].clear();
					(*it_wall)->cleanCurrentCell();
				}
			}
		}
	if (decal == true)
	{
		y = 0;
		it_wall = (this->_wallPool).begin();
		while (y < atoi(this->_script->getMap()->_topMap.substr(this->_globalPos, 1).c_str()))
		{
			assign = false;
			while ( it_wall != (this->_wallPool).end() && assign == false)
			{
				if ((*it_wall)->getHP() == 0)
				{
					temp._posX = 16;
					temp._posY = y;
				//	std::cout << "CREATED !top" <<std::endl;
					assign = assignWall(*it_wall, false, temp, true);
				}
				it_wall ++;
			}
			y++;
		}
		y = 17;
		it_wall = this->_wallPool.begin();
		while (y > 17 - atoi(this->_script->getMap()->_botMap.substr(this->_globalPos, 1).c_str()))
		{
			assign = false;
			while (assign == false && it_wall != this->_wallPool.end())
			{
				if ((*it_wall)->getHP() == 0)
				{
					temp._posX = 16;
					temp._posY = y;
					//std::cout << "CREATED !bot" <<std::endl;
					assign = assignWall(*it_wall, false, temp, false);
				}
				it_wall ++;
			}
			--y;
		}
	//	std::cout << "--------------NEW Screen " << this->_firstColumn <<"/" << this->_globalPos << " ------------" << std::endl;
		this->_globalPos ++;
		if (this->_firstColumn < 16)
			this->_firstColumn++;
		else
			this->_firstColumn = 0;
/*		short x;
		y = 0;
	while (y < 18)
	{
		x = this->_firstColumn;
		while (x < 17)
		{
			if (this->_map[y][x].size() > 0)
				std::cout << "[=]";
			else
				std::cout << "   ";
			x ++;
		}
		x = 0;
		while (x < this->_firstColumn)
		{
			if (this->_map[y][x].size() > 0)
				std::cout << "[=]";
			else
				std::cout << "   ";
			x ++;
		}
		std::cout << "-" << std::endl;
		y ++;
	}*/
	}
}

bool	Game::assignWall(Wall * vWall, bool isfirst, t_coord &temp, bool isTop)
{
	t_coord						coord;

	//vWall->cleanSprite();
	if (isTop)
		vWall->addSprite(WALL_UP);
	else
		vWall->addSprite(WALL_DOWN);
	vWall->setHP(1);
	coord._posX = temp._posX * 100;
	coord._posY = temp._posY * 50;
	vWall->setPos(&coord);
	if (isfirst)
		coord._posX = temp._posX;
	else
		coord._posX = this->_firstColumn;
	coord._posY = temp._posY;
	this->_map[coord._posY][coord._posX].push_back(vWall);
	vWall->addToCurrentCell(coord);
	return (true);
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}
