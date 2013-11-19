#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteManager.h"
#include "PlayerShip.h"
#include "ClientCommunication.hpp"
#include "UDPSocketClient.h"
#pragma once

class GameLoop
{
private:
	SpriteManager					_spritemgr;
	sf::RenderWindow				*_window;
	ClientCommunication<GameLoop>	_comm;
	UDPSocketClient					*_udpsock;
public:
	GameLoop(sf::RenderWindow*, short);
	void	manageEvent(bool *, PlayerShip *);
	void	openBackMenu(bool *);
	void	drawBackground(void);
	void	displaySprite(short, short, eSprites);
	void	mainLoop(void);
	~GameLoop(void);
};

