#include "BackGameButton.h"


BackGameButton::BackGameButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_PLAY));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_PLAY_ON));
}

void	BackGameButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	*running = false;
}

BackGameButton::~BackGameButton(void)
{
}
