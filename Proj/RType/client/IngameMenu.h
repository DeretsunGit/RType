#pragma once
#include "Menu.h"
class IngameMenu :
	public Menu
{
public:
	IngameMenu(sf::RenderWindow *, SpriteManager *);
	~IngameMenu(void);
};

