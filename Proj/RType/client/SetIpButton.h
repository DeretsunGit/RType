#pragma once
#include <string>
#include "Button.h"
#include "SettingsParser.h"
#include "TextHandler.h"

class SetIpButton :
	public Button
{
	sf::Sprite		_sprite;
	SettingsParser	*_sett;
	std::string		_serv;
	TextHandler		_txthandler;
public:
	SetIpButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void	extraDisplay(unsigned int, unsigned int, sf::RenderWindow *);
	~SetIpButton(void);
};
