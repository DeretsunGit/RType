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
#include "Script.h"
#include "Ennemy.h"

class Game
{
private:
	unsigned short int	_port;
	UDPSocketServer*	_udpSock;
	ServerCommunication<Game>		_GameCom;

	const std::vector<Player*>&	_players;
	std::list<Wave>			_livingThings;
	//std::list<Clock &>		_waveTime;

	// maps
	Script					*_script;
	bool					_endGame;
	short int				_firstColumn;
	std::list<Element*>		_map[18][17]; // [hauteur y][largeur x]
	short int				_globalPos;

	// pools
	std::list<Wall*>		_wallPool;
	std::list<Bullet*>		_bulletPool;
	std::list<Ennemy*>		_ennemyPool;
	Packet					_pack;

public:
	Game(const std::vector<Player*>& p, Script *, UDPSocketServer *);
	~Game();

//ServerCommunication
	void	inputs(void *);
	void	pauseOk(void *);
	void	callBackError(char, IReadableSocket&);
	void	sendError(char, const char *);

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
	//bool	assignWall(Wall *, bool, short, short, bool);
	bool	assignWall(Wall *, bool, t_coord &, bool);

	void	playerShoot(Player *);
	void	moveBullets();

	void	TCPsend(Packet&);

	//ServerCommunication		*getServCom();

};