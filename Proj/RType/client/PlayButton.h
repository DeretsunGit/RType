#pragma once
#include "Button.h"
class PlayButton :
	public Button
{
	SpriteManager	*_sprmgr;
	bool			_connectError;
	sf::Font		_font;
	sf::Text		_text;
public:
	PlayButton(SpriteManager *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	void			extraDisplay(unsigned int, unsigned int, sf::RenderWindow *);
	~PlayButton(void);
};