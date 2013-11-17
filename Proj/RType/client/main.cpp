#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "MainMenu.h"
#include <iostream>

int main()
{
	sf::RenderWindow	*renderwindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "R-TYPE");
	SpriteManager		*spritemgr = new SpriteManager;
	MainMenu			menu(renderwindow, spritemgr);

	menu.menuLoop();
	return 0;
}