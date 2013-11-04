#pragma once
#include <vector>
#include <iostream>
#include "SpriteManager.h"


class Menu
{
public:
	enum eMenuActions
{
	OPENMAIN,
	OPENCREDITS,
	OPENSETTINGS,
	STARTGAME,
	QUIT
};

private:
	std::vector<eSprites>				_buttons;
	std::vector<eMenuActions>			_menuactions;
	unsigned int						_active;
	unsigned int						_size;
public:
	Menu(const int, const eSprites [], const eMenuActions []);
	void								setActive(unsigned int);
	void								incActive(void);
	void								decActive(void);
	unsigned int						getActive(void) const;
	unsigned int						getSize(void) const;
	eSprites							getSpriteId(int) const;
	Menu::eMenuActions					getMenuAction(int) const;
	Menu::eMenuActions					getActiveMenuAction(void) const;
	~Menu(void);
};

