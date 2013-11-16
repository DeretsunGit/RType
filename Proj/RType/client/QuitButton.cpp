#include "QuitButton.h"


QuitButton::QuitButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_QUIT));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_QUIT_ON));
}

void	QuitButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	window->close();
}

QuitButton::~QuitButton(void)
{
}
