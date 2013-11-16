#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Button.h"

enum eMenus
{
	MAIN,
	PLAY,
	SETTINGS,
	INGAME
};

class Menu
{
private:
	sf::RenderWindow		*_window;
	std::vector<Button*>	_buttons;
	unsigned int			_active;
	unsigned int			_size;
	eMenus					_type;
	SpriteManager			*_spritemgr;
public:
	Menu(sf::RenderWindow *, SpriteManager *, eMenus);
	void					displayMenu() const;
	void					menuLoop();
	void					setMenuContent(eMenus);
	void					setActive(unsigned int);
	void					incActive(void);
	void					decActive(void);
	unsigned int			getActive(void) const;
	unsigned int			getSize(void) const;
	~Menu();

};











//enum eMenus
//{
//	MAIN,
//	PLAY,
//	SETTINGS
//};
//
//class Menu
//{	
//protected:
//	sf::RenderWindow								*_window;
//	SpriteManager									*_spriteMgr;
//	std::vector<eSprites>							_buttons;
//	std::vector<void (Menu::*)(sf::Keyboard::Key)>	_menuActions;
//	unsigned int									_active;
//	unsigned int									_size;
//	eMenus											_crtMenuType;
//public:
//	Menu(sf::RenderWindow *, SpriteManager *, eMenus);
//	void											changeActiveMenu(eMenus);
//	void											displayMenu();
//	void											showFullScreenSprite(eSprites);
//	void											menuLoop();
//	void											setActive(unsigned int);
//	void											incActive(void);
//	void											decActive(void);
//	unsigned int									getActive(void) const;
//	unsigned int									getSize(void) const;
//	eSprites										getSpriteId(int) const;
//	void											buttonPlayGame(sf::Keyboard::Key);
//	void											buttonSettings(sf::Keyboard::Key);
//	void											buttonCredits(sf::Keyboard::Key);
//	void											buttonQuit(sf::Keyboard::Key);
//	void											buttonSetRes(sf::Keyboard::Key);
//	void											buttonSetNick(sf::Keyboard::Key);
//	void											buttonSetSound(sf::Keyboard::Key);
//	void											buttonSetServList(sf::Keyboard::Key);
//	void											buttonBackMain(sf::Keyboard::Key);
//	~Menu(void);
//};
//
