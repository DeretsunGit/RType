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
	std::cout << "Size: " << this->_players.size() << std::endl;
	this->_endGame = false;
	this->_firstColumn = 0;
	this->_globalPos = 17;
	//this->_com.TCPsendStartGame(packet, this->_port);
	//this->TCPsend(packet);
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
	// grâce au script et à un fichier qui décrit les patterns, on recompose la map globale
	bool						assign = false;
	short int					i = 0;
	short int					x = 0;
	short int					y = 0;
	t_coord						coord;
	std::list<Wall*>::iterator	it;

	// on génère maintenant visibleMap
	std::cout << "Visible map generation started" << std::endl;
	std::cout << "unsing script, map of size" << this->_script->getMap()->_botMap.size() << std::endl;
	std::cout << "-------------------TOPMAP------------------" << std::endl;
	std::cout << this->_script->getMap()->_topMap << std::endl;
	std::cout << "-------------------BOTMAP------------------" << std::endl;
	std::cout << this->_script->getMap()->_botMap << std::endl;
	std::cout << "__________________________________________" << std::endl;
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
						assign = true;
						this->_map[y][x].push_back(*it);
						(*it)->setHP(1);
						coord._posX = x * 100;
						coord._posY = y * 50;
						(*it)->setPos(&coord);
						coord._posX = x;
						coord._posY = y;
						(*it)->addToCurrentCell(coord);
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
						assign = true;
						this->_map[y][x].push_back(*it);
						(*it)->setHP(1);
						coord._posX = x * 100;
						coord._posY = y * 50;
						(*it)->setPos(&coord);
						coord._posX = x;
						coord._posY = y;
						(*it)->addToCurrentCell(coord);
					}
					it ++;
				}
				y--;
			}
			x++;
		}
	std::cout << "finished !" << std::endl;
	x = 0;
	y = 0;
	std::cout << "--------------First Screen------------" << std::endl;
	while (y < 18)
	{
		x = 0;
		while (x < 17)
		{
			if (this->_map[y][x].size() > 0)
				std::cout << "[=]";
			else
				std::cout << "   ";
			x ++;
		}
		std::cout << "-" << std::endl;
		y ++;
	}
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
		Sleep((unsigned long)(LOOPTIME - execTime));
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
				if ((*it_wall)->getSendPriority() > maxPriority)
					maxPriority = (*it_wall)->getSendPriority();
				if (elemToSend.size() < 100)
					{
						elemToSend.push_back(*it_wall);
						(*it_wall)->setSendPriority(2);
					}
				else
					(*it_wall)->setSendPriority((*it_wall)->getSendPriority() + 1);
			}
		}
	// ajouter les ennemis et les bullets
	this->_GameCom.UDPscreenState(this->_pack, 0, elemToSend);
	this->_udpSock->broadcast(this->_pack);
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
				if ((*it_wall)->getPos()._posY < 0)
					std::cout << "POMI IZ SO BAD!" << std::endl;
				temp._posX = (*it_wall)->getPos()._posX - (3 * (*it_wall)->getSpeed());
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
					std::cout << "CREATED !top" <<std::endl;
					assign = true;
					this->_map[y][this->_firstColumn].push_back(*it_wall);
					(*it_wall)->setHP(1);
					temp._posX = 1600;
					temp._posY = y * 50;
					(*it_wall)->setPos(&temp);
					temp._posX = this->_firstColumn;
					temp._posY = y;
					(*it_wall)->addToCurrentCell(temp);
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
					std::cout << "CREATED !bot "<< std::endl;
					assign = true;
					this->_map[y][this->_firstColumn].push_back(*it_wall);
					(*it_wall)->setHP(1);
					temp._posX = 1600;
					temp._posY = y * 50;
					(*it_wall)->setPos(&temp);
					temp._posX = this->_firstColumn;
					temp._posY = y;
					(*it_wall)->addToCurrentCell(temp);
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
		/*short x;
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

Game::~Game()
{
	// ramener tous les joueurs au menu
}
