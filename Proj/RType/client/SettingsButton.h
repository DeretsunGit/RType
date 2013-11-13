#pragma once
#include "Button.h"
class SettingsButton :
	public Button
{
public:
	SettingsButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *);
	~SettingsButton(void);
};
