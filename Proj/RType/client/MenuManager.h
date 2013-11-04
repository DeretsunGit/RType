#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "SpriteManager.h"
#include "Menu.h"
#include "GameLoop.h"

#define	SIZEX	(1600)
#define	SIZEY	(900)

class MenuManager
{
private:
	SpriteManager					_spritemgr;
	sf::RenderWindow				*_window;
	std::map<std::string, Menu*>	_menus;
	Menu							*_activeMenu;
	GameLoop						*_gameLoop;
public:
	MenuManager(void);
	~MenuManager(void);
	void						init(void);
	void						triggerMenuAction(Menu::eMenuActions);
	void						displayMenu(const Menu *);
	int							menuLoop(void);

};

