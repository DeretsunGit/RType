#include "Drawable.h"


Drawable::Drawable(sf::Sprite sprite)
{
	this->_sprite = sprite;
}

Drawable::~Drawable(void)
{
}

float			Drawable::getPosX() const
{
	return this->_sprite.getPosition().x;
}

float			Drawable::getPosY() const
{
	return this->_sprite.getPosition().y;
}

void			Drawable::setPosX(float pos)
{
	this->_sprite.setPosition(pos, this->_sprite.getPosition().y);
}

void			Drawable::setPosY(float pos)
{
	this->_sprite.setPosition(this->_sprite.getPosition().x, pos);	
}

sf::Sprite		Drawable::getSprite() const
{
	return this->_sprite;
}

void			Drawable::setSprite(sf::Sprite sprite)
{
	this->_sprite = sprite;
}