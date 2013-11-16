#pragma once
#include "Button.h"
class BackGameButton :
	public Button
{
public:
	BackGameButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	~BackGameButton(void);
};
