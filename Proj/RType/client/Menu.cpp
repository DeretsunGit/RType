#include "Menu.h"


Menu::Menu(int size, const eSprites buttons[], const eMenuActions actions[])
{
	this->_active = 0;
	this->_size = size;
	this->_buttons.resize(size);
	this->_menuactions.resize(size);
	for (int i = 0 ; i < size ; i++)
	{
		this->_buttons[i] = buttons[i];
		this->_menuactions[i] = actions[i];
	}
}

void			Menu::setActive(unsigned int id)
{
	this->_active = id;
}

void			Menu::incActive(void)
{
	if (this->_active < this->_size - 1)
		this->_active++;
}

void			Menu::decActive(void)
{
	if (this->_active > 0)
		this->_active--;
}

unsigned int	Menu::getActive(void) const
{
	return (this->_active);
}

unsigned int	Menu::getSize(void) const
{
	return (this->_size);
}

eSprites		Menu::getSpriteId(int id) const
{
	return this->_buttons[id];
}

Menu::eMenuActions	Menu::getMenuAction(int id) const
{
	return this->_menuactions[id];
}

Menu::eMenuActions	Menu::getActiveMenuAction(void) const
{
	return this->_menuactions[this->_active];
}

Menu::~Menu(void)
{
}
