#pragma once
#include "Menu.h"
class MainMenu :
	public Menu
{
private:

public:
	MainMenu(sf::RenderWindow*, SpriteManager *);
	virtual ~MainMenu(void);
};

