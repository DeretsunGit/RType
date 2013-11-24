#pragma once
#include "Background.h"
#include "Button.h"
class CreditsButton :
	public Button
{
	sf::Sprite		_sprite;
	Background		*_bg;
public:
	CreditsButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	~CreditsButton(void);
};
