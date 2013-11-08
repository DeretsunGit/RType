#include <iostream>
#include "Game.h"

Game::Game(const std::vector<Player*>& p)
  : _players(p)
{
	
	/*
	this->_GameCom.setCallback(0x0D, &Game::inputs);
	this->_GameCom.setCallback(0x0E, &Game::pauseOk);
	this->_GameCom.setDefaultCallback(&Game::callBackError);
	this->_GameCom.setHandler(this);*/
	Packet packet;
	std::cout << "Size: " << this->_players.size() << std::endl;
	this->_endGame = false;
	this->_firstColumn = 0;
	// on r�cup�re Script en argument
	this->setUDP();
	//this->_com.TCPsendStartGame(packet, this->_port);
	this->TCPsend(packet);
	this->mapGeneration();
	this->genPool();
	this->startGame();
	// startGame() va attendre que les clients soient ready via TCP
	// puis envoi aux client le start game via TCP
	this->gameLoop();
  	
}

void	Game::callBackError(char, IReadableSocket&)
{

}

void	inputs(void *data)
{

}

void	pauseOk(void *data)
{

}

void	Game::setUDP()
{
	std::vector<Player*>::iterator	it_player;

	this->_udpSock = new UDPSocketServer(0);
	this->_port = this->_udpSock->getPort();
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

bool	Game::startGame()
{
	/*unsigned short i = 1;
	// On g�re l'attente des players
	// Lorsqu'on recoit des packets TCP, on les traite ici
	Packet* tmp = NULL; // tmp sera remplac� par le vrai packet recu

/*	if (_com.TCPgetReady(tmp->getBuffer()))
		;// la m�thode retourne vrai, le joueur a donc envoy� ready
	else
		;// la m�thode retourne false, le joueur a envoy� un packet eronn�
	// si tous les joueurs sont pr�ts
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

	while (this->_endGame != true)
	{
		loopTimer.initialise();
		std::cout << __LINE__ << std::endl;
		this->getInputs();
		// d�placement de Waves en fonction du script
		std::cout << __LINE__ << std::endl;
		this->moveBullets();
		std::cout << __LINE__ << std::endl;
		this->moveWall();
		std::cout << __LINE__ << std::endl;
		//this->collision();
		std::cout << __LINE__ << std::endl;
		// (pop de Wave)
		this->sendPriority();
		std::cout << __LINE__ << std::endl;
		this->_endGame = !this->isPlayerAlive();
		std::cout << __LINE__ << std::endl;
		execTime = loopTimer.getTimeBySec();
		std::cout << __LINE__ << std::endl;
		Sleep((unsigned long)(16 - execTime));
	}
}

void	Game::collision()
{
	int										collision_ret;
	std::list<Wall*>::iterator				it_wall;
	std::vector<t_coord>::const_iterator	it_coord;
	std::vector<Player*>::const_iterator	it_player;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				for (it_coord = ((*it_wall)->getCurrentCell()).begin(); it_coord != ((*it_wall)->getCurrentCell()).end(); it_coord++)
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
				for (it_coord = ((*it_player)->getCurrentCell()).begin(); it_coord != ((*it_player)->getCurrentCell()).end(); it_coord++)
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

	// UDPsendGameElements(const std::list<Element*>, const std::vector<&Player>);
	// on d�clare un Packet qui va etre allou� dans la m�thode
	//Packet pack;
	//_com.UDPsendGameElements(pack, elemToSend, this->_players);

	// ici, pack contient les donn�es s�rialis�es � �crire sur la socket.
}

void	Game::getInputs()
{
	//  !! ceci fonctionne pour 1 joueur !!
	//s_inputs inputs;
	char *buff = NULL;
	// recuperer les packets sur la socket
	// passer en param�tre de la fonction le buffer du packet
	// remplac� ici par un buffer vide
	//_com.UDPinterpretInputs(inputs, buff);

	// ici la struct inputs contient les inputs utilisateur
	// comme d�finie dans la RFC.
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
			(*it_bullet)->setPos(currentPlayer->getPos()); // faux car tir en haut a gauche
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
	bool							decal = false;
	t_coord							temp;
	std::list<Wall*>::iterator		it_wall;
	short int						y = 0;

	for (it_wall = (this->_wallPool).begin(); it_wall != (this->_wallPool).end(); it_wall++)
		{
			if ((*it_wall)->getHP() != 0)
			{
				temp._posX = (*it_wall)->getPos()._posX - 3 * (*it_wall)->getSpeed();
				temp._posY = (*it_wall)->getPos()._posY;
				(*it_wall)->setPos(temp);
			}
			// on supprime les murs inactifs et on set les nouveaux murs
			if ((*it_wall)->getPos()._posX <= -100)
			{
				decal = true;
				(*it_wall)->setHP(0);
				(*it_wall)->setSendPriority(2);
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
/*
ServerCommunication	*Game::getServCom()
{
	return (&this->_com);
}
*/
Game::~Game()
{
	// ramener tous les joueurs au menu
}