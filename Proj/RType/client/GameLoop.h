#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteManager.h"
#include "PlayerShip.h"

#pragma once
class GameLoop
{
private:
	SpriteManager		_spritemgr;
	sf::RenderWindow	*_window;
public:
	GameLoop(sf::RenderWindow*);
	void	manageEvent(bool *, PlayerShip *);
	void	openBackMenu(bool *);
	void	drawBackground(void);
	void	mainLoop(void);
	~GameLoop(void);
};

