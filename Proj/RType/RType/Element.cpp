#include "Element.h"

Element::Element()
{
}

Element::~Element()
{
}

t_coord	Element::getPos() const
{
	return (this->_pos);
}

char	Element::getSpriteId() const
{
	return (this->_spriteId);
}