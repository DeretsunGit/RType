#include "BackMainButton.h"


BackMainButton::BackMainButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(BACK_MAIN));
	this->setSpriteOn(sprmgr->getSpritebyId(BACK_MAIN_ON));
}

void	BackMainButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	*running = false;
}

BackMainButton::~BackMainButton(void)
{
}
