#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "MainMenu.h"
#include <iostream>

int main()
{
	sf::RenderWindow	*renderwindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "R-TYPE", sf::Style::Close);
	SpriteManager		*spritemgr = new SpriteManager;
	MainMenu			menu(renderwindow, spritemgr);

	menu.menuLoop();
	std::cout << "after main lup" << std::endl;
	return 0;
}