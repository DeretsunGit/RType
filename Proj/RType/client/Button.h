#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteManager.h"


#define SIZEX (1600)
#define SIZEY (900)

class Button
{
protected:
	sf::Sprite	_sprite;
	sf::Sprite	_sprite_on;
	bool		_highlight;

public:
	Button(void);
	void			setSprite(sf::Sprite);
	void			setSpriteOn(sf::Sprite);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *);
	virtual void	displayButton(unsigned int, unsigned int, sf::RenderWindow *);
	virtual void	extraDisplay(unsigned int, unsigned int, sf::RenderWindow *);
	void			setHighlight(bool);
	~Button(void);
};

