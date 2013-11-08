#pragma once

#include <vector>
#include <list>
#include <iterator>
//#include "rtype_common.h"
#include "Wave.h"
#include "Wall.h"
#include "Bullet.h"
#include "ServerCommunication.hpp"
#include "Clock.h"

class Game
{
private:
	unsigned short int	_port;
	UDPSocketServer*	_udpSock;
	//ServerCommunication<Game>		_GameCom;

	const std::vector<Player*>&	_players;
	std::list<Wave>			_livingThings;

	// maps
	// Script				_script;
	bool					_endGame;
	short int				_firstColumn;
	std::list<Element*>		_map[18][17]; // [hauteur y][largeur x]
	short int				_globalPos;
	char					_globalMapTop[256];
	char					_globalMapBot[256];

	// pools
	std::list<Wall*>		_wallPool;
	std::list<Bullet*>		_bulletPool;

public:
	Game(const std::vector<Player*>& p);
	~Game();

//ServerCommunication
	void	inputs(void *);
	void	pauseOk(void *);
	void	callBackError(char, IReadableSocket&);

	void	genPool();
	bool	startGame();
	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();
	void	collision();
	void	sendPriority();
	void	getInputs();
	bool	isPlayerAlive();
	void	moveWall();
	void	playerShoot(Player *);
	void	moveBullets();

	void	TCPsend(Packet&);
	void	setUDP();

	//ServerCommunication		*getServCom();

};