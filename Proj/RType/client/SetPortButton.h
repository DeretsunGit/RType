#pragma once
#include <string>
#include "Button.h"
#include "SettingsParser.h"
#include "TextHandler.h"

class SetPortButton :
	public Button
{
	sf::Sprite		_sprite;
	SettingsParser	*_sett;
	std::string		_port;
	TextHandler		_txthandler;
public:
	SetPortButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void	extraDisplay(unsigned int, unsigned int, sf::RenderWindow *);
	~SetPortButton(void);
};
