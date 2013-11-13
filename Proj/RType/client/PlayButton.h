#pragma once
#include "Button.h"
class PlayButton :
	public Button
{
	SpriteManager	*_sprmgr;
public:
	PlayButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *);
	~PlayButton(void);
};

