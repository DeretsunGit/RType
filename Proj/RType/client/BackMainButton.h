#pragma once
#include "Button.h"
class BackMainButton :
	public Button
{
public:
	BackMainButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	~BackMainButton(void);
};
