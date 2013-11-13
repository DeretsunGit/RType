#pragma once
#include "Button.h"
class QuitButton :
	public Button
{
	sf::Sprite		_sprite;
public:
	QuitButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *);
	~QuitButton(void);
};
