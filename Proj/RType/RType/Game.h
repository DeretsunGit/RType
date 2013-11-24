#pragma once

#include <vector>
#include <list>
#include <iterator>
//#include "rtype_common.h"
#include "Clock.hpp"
#include "Script.h"
#include "Movement.hpp"
#include "Wave.hpp"
#include "Wall.h"
#include "Bullet.h"
#include "Ennemy.h"
#include "ServerCommunication.hpp"

class Game
{
private:
	unsigned short int	_port;
	UDPSocketServer*	_udpSock;
	ServerCommunication<Game>		_GameCom;

	const std::vector<Player*>&	_players;
	std::list<Wave>			_livingThings;
	//std::list<Clock &>		_waveTime;
	Movement					_move;

	// maps
	Script					*_script;
	bool					_endGame;
	short int				_firstColumn;
	std::list<Element*>		_map[18][17]; // [hauteur y][largeur x]
	short int				_globalPos;
	short int				_nbReady;

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
	void	letsPlay(void *);
	void	callBackError(char, IReadableSocket&);
	void	sendError(char, const char *);

	void	genPool();
	bool	startGame();
	void	gameLoop();
	void	waveGeneration();
	void	mapGeneration();
	void	playerReset();
	void	collision();
	void	sendPriority(unsigned long);
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