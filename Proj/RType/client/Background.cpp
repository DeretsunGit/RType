#include <iostream>
#include "Background.h"

Background::Background(sf::Sprite sprite) : Drawable(sprite)
{
	this->_pos = 0;
}

void	Background::moveBackground(void)
{
	this->_pos = this->_pos - 1;
	if (this->_pos == -1600.0)
		this->_pos = 0.0;
	this->_sprite.setPosition(this->_pos, 0.0);
}

Background::~Background(void)
{
}
