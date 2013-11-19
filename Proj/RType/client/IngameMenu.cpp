#include "IngameMenu.h"
#include "PlayButton.h"
#include "BackGameButton.h"
#include "BackMainButton.h"

IngameMenu::IngameMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	this->_size = 2;
	this->_buttons.resize(this->_size);
	this->_buttons[0] = new BackGameButton(this->_spritemgr);
	this->_buttons[1] = new BackMainButton(this->_spritemgr);
}

IngameMenu::~IngameMenu(void)
{
}
