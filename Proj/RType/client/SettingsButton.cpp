#include "SettingsButton.h"
#include "SettingsMenu.h"

SettingsButton::SettingsButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_SETT));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_SETT_ON));
	this->_sprmgr = sprmgr;
}

void	SettingsButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	SettingsMenu	menu(window, this->_sprmgr);

	menu.menuLoop();
}

SettingsButton::~SettingsButton(void)
{
}
