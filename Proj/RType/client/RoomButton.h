#pragma once
#include <string>
#include "Button.h"
class RoomButton :
	public Button
{
	std::string		_name;
public:
	RoomButton(SpriteManager *, std::string);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void	displayButton(unsigned int, unsigned int, sf::RenderWindow *);
	~RoomButton(void);
};

