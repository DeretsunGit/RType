#pragma once
#include <SFML/Audio.hpp>
#include "Menu.h"
class MainMenu :
	public Menu
{
public:
	MainMenu(sf::RenderWindow *, SpriteManager *);
	~MainMenu(void);
};

