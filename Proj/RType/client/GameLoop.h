#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteManager.h"
#include "PlayerShip.h"
#include "ClientCommunication.hpp"
#include "UDPSocketClient.h"
#include "TCPSocketClient.h"

#pragma once

enum eSocketType
{
	TCP,
	UDP
};

class GameLoop
{
private:
	SpriteManager					_spritemgr;
	sf::RenderWindow				*_window;
	ClientCommunication<GameLoop>	_comm;
	UDPSocketClient					*_udpsock;
	TCPSocketClient					*_tcpsock;
	//eSocketType						_socktype;
	Packet							_p;
	s_screen_state					_screenstate;
	
public:
	GameLoop(sf::RenderWindow*, TCPSocketClient*, short);
	void	manageEvent(bool *, PlayerShip *);
	void	openBackMenu(bool *);
	void	drawBackground(void);
	void	displaySprite(short, short, eSprites);
	void	handleUDPOkay(void *);
	void	handleStartLoading(void *);
	void	handleScreenState(void *);
	void	defaultCallback(char, IReadableSocket&);
	void	handleNetwork();
	void	mainLoop(void);
	//void	drawWalls(void);
	void	initNetwork(void);
	void	drawScreenState(void);
	~GameLoop(void);
};

