#include "Menu.h"
#include "PlayButton.h"


PlayButton::PlayButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_PLAY));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_PLAY_ON));
	this->_sprmgr = sprmgr;
}

void	PlayButton::action(sf::Keyboard::Key, sf::RenderWindow *window)
{
	Menu	playmenu(window, this->_sprmgr, PLAY);

	playmenu.menuLoop();

}

PlayButton::~PlayButton(void)
{
}
