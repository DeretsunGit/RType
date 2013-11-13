#pragma once
#include "Button.h"
class CreditsButton :
	public Button
{
	sf::Sprite		_sprite;
public:
	CreditsButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *);
	~CreditsButton(void);
};
