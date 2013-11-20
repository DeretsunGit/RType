#pragma once
#include "SpriteManager.h"
#include "Button.h"
class SettingsButton :
	public Button
{
	SpriteManager	*_sprmgr;
public:
	SettingsButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	~SettingsButton(void);
};
