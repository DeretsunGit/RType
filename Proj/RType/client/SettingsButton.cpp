#include "SettingsButton.h"


SettingsButton::SettingsButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_SETT));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_SETT_ON));
}

void	SettingsButton::action(sf::Keyboard::Key, sf::RenderWindow *, bool *running)
{

}

SettingsButton::~SettingsButton(void)
{
}
