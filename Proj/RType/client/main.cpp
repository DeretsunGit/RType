#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "MainMenu.h"
#include <iostream>
#include <Windows.h>

int main()
{
	sf::RenderWindow	*renderwindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "R-TYPE");
	SpriteManager		*spritemgr = new SpriteManager;
	Menu				menu(renderwindow, spritemgr, MAIN);

	menu.menuLoop();
	return 0;

}