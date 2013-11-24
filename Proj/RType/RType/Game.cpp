#include <iostream>
#include "Game.h"
#include "ServerCommunication.cpp"
template class ServerCommunication<Room>;

Game::Game(std::vector<Player*>& p, Script *s, UDPSocketServer * UDPsock)
  : _players(p), _script(s), _udpSock(UDPsock)
{
	this->_GameCom.setCallback(Opcodes::letsPlay, &Game::letsPlay);
	this->_GameCom.setCallback(Opcodes::inputs, &Game::inputs);
	this->_GameCom.setDefaultCallback(&Game::callBackError);
	this->_GameCom.setHandler(this);
	this->_endGame = false;
	this->_firstColumn = 0;
	this->_globalPos = 17;
	this->genPool();
	this->_nbReady = 0;

	std::cout << (this->_players[0])->getPos()._posX << "/" << (this->_players[0])->getPos()._posY << std::endl;


	std::cout << "Pools fully created" << std::endl;
	this->mapGeneration();
	std::cout << "Map generation finished !" << std::endl;
	this->startGame();
	this->gameLoop();
}

void	Game::callBackError(char opcode, IReadableSocket&)
{
	std::cout << "Callbackerror, opcode :"<< opcode << std::endl; 
	this->sendError(61, "You can't perform this action by now.");
}

void	Game::inputs(void *data)
{
	s_recv_inputs	*dataStruct = reinterpret_cast<s_recv_inputs *>(data);;
	short		i = 0;

	while (i < this->_players.size())
	{
		if (dataStruct->from == this->_players[i]->getClient()->getInaddr())
		{
			this->_move.genericMove(PlayerMove, this->_players[i], dataStruct->in.x, dataStruct->in.y);
		}
		i++;
	}
}

void	Game::letsPlay(void *data)
{
	this->_nbReady ++;
}

void		Game::sendError(char errorCode, const char *message)
{
	this->_GameCom.TCPsendError(this->_pack, errorCode, message);
}

void	Game::mapGeneration()
{
	bool						assign = false;
	short int					i = 0;
	short int					x = 0;
	short int					y = 0;
	t_coord						coord;
	std::list<Wall*>::iterator	it;

		while (x < 17)
		{
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
}

void	Game::genPool()
{
	int i = 0;

	while (i <= 200)
	{
		this->_wallPool.push_back(new Wall);
		this->_bulletPool.push_back(new Bullet);
		this->_ennemyPool.push_back(new Ennemy(i));
		i++;
	}
}

bool	Game::startGame()
{
	bool ready= false;
	short int i;

	this->_GameCom.UDPok(this->_pack);
	this->_udpSock->broadcast(this->_pack);
	this->_nbReady = 0;
	while (ready != true)
	{
		i = 0;
		while (i < this->_players.size())
		{
			this->_GameCom.interpretCommand(*(this->_players[i]->getClient()->getTCPSock()));
			i++;
		}
		if (this->_nbReady == this->_players.size())
			ready = true;
	}
	return (true);
}

void	Game::gameLoop()
{
	Clock	GameTime;
	Clock	loopTimer;
	float	execTime;
	std::vector<Player*>::iterator	it = this->_players.begin();

	GameTime.initialise();
	std::cout << "entering the mysterious arcanes of gameloop" << std::endl; 
	while (this->_endGame != true)
	{
	//	std::cout << "a" << std::endl;
		loopTimer.initialise();
		this->moveWall();

		it = (this->_players).begin();
		while (it != this->_players.end())
		{
			if (this->_udpSock->isLive())
			{
				this->_GameCom.interpretCommand(*this->_udpSock);
				it ++;
			}
			else
			{
				(*it)->getClient()->setDelete(true);
				it = this->_players.erase(it);
			}
		}
		this->collision();
		// (pop de Wave)
		this->sendPriority((unsigned long)(GameTime.getTimeBySec() * 10));
		if (this->_globalPos == 256 || this->isPlayerAlive() == false)
			this->_endGame = true;
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(GAMELOOPTIME - execTime -1));
		this->_udpSock->broadcast(this->_pack);
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(GAMELOOPTIME - execTime));
	}
	if (this->_globalPos == 256)
	{
		// send win
	}
	else
	{
		// send lose
	}
}

void	Game::collision()
{
	int										collision_ret;
	std::list<Wall*>::iterator				it_wall;
	std::vector<t_coord>::const_iterator	it_coord;
	std::vector<t_coord>					shittyvar_currentcelll;
	int										i = 0;
	t_coord									coord;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
	{
		if ((*it_wall)->getHP() != 0)
		{
			i = 0;
			while (i < this->_players.size())
			{
				if ((*it_wall)->isCollision(this->_players[i]) == true)
				{
					if (this->_players[i]->getHP() > 0)
					{
						coord._posX = 100;
						coord._posY = 450;
						this->_players[i]->setHP(this->_players[i]->getHP() - 1);
						this->_players[i]->setPos(&coord);
					}	
				}
				i++;
			}
		}
	}
}

void	Game::sendPriority(unsigned long score)
{
	short int					maxPriority = 0;
	std::list<Element *>		elemToSend;
	std::list<Wall*>::iterator		it_wall;
	int								i = 0;

	while (i < this->_players.size())
	{
		elemToSend.push_back(this->_players[i]);
		i++;
	}
	i = 0;
	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				elemToSend.push_back(*it_wall);
				i++;
			}
		}
	this->_GameCom.UDPscreenState(this->_pack, score, elemToSend);
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
				this->_move.genericMove(Linear, (*it_wall), 1, 0);
				if ((*it_wall)->getPos()._posX <= -100 )
				{
					temp._posX = 0;
					temp._posY = 0;
					decal = true;
					(*it_wall)->setHP(0);
					(*it_wall)->setPos(&temp);
					(*it_wall)->setSendPriority(2);
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
					assign = assignWall(*it_wall, false, temp, false);
				}
				it_wall ++;
			}
			--y;
		}
		std::cout << "--------------NEW Screen " << this->_firstColumn <<"/" << this->_globalPos << " ------------" << std::endl;
		this->_globalPos ++;
		if (this->_firstColumn < 16)
			this->_firstColumn++;
		else
			this->_firstColumn = 0;
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
	coord._posX = 100;
	coord._posY = 50;
	vWall->setHitboxSize(&coord);
	if (isfirst)
		coord._posX = temp._posX;
	else
		coord._posX = this->_firstColumn;
	coord._posY = temp._posY;
	vWall->addToCurrentCell(coord);
	return (true);
}

Game::~Game()
{
	// ramener tous les joueurs au menu
}
