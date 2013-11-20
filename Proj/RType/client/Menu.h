#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Button.h"
#include "ClientCommunication.hpp"

enum eMenus
{
	MAIN,
	PLAY,
	SETTINGS,
	INGAME
};

class Menu
{
protected:
	sf::RenderWindow			*_window;
	std::vector<Button*>		_buttons;
	unsigned int				_active;
	unsigned int				_size;
	eMenus						_type;
	SpriteManager				*_spritemgr;
public:
	Menu(sf::RenderWindow *, SpriteManager *);
	Menu(Menu&);
	void						displayMenu() const;
	void						menuLoop();
	void						setMenuContent(eMenus);
	void						setActive(unsigned int);
	void						incActive(void);
	void						decActive(void);
	unsigned int				getActive(void) const;
	unsigned int				getSize(void) const;
	virtual void				childAction();
	sf::RenderWindow*			getWindow(void) const;
	SpriteManager*				getSpriteMgr(void) const;
	~Menu();
};
