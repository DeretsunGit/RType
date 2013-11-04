#include "Element.h"

Element::Element()
{
}

Element::~Element()
{
}

void	Element::setHP(int hp)
{
	this->_hp = hp;
}

t_coord	Element::getPos() const
{
	return (this->_pos);
}

char	Element::getSpriteId() const
{
	return (this->_spriteId);
}

int		Element::getHP() const
{
	return (this->_hp);
}