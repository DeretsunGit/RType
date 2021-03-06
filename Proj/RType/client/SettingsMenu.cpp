#include "SettingsMenu.h"
#include "PlayButton.h"
#include "SettingsButton.h"
#include "CreditsButton.h"
#include "BackMainButton.h"
#include "SetIpButton.h"
#include "SetPortButton.h"
#include "SetNickButton.h"

SettingsMenu::SettingsMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	Packet p;
	unsigned short res[2] = {1600, 900}; //recup via seufeumeul
	this->_size = 4;
	this->_buttons.resize(this->_size);
	this->_buttons[0] = new SetNickButton(this->_spritemgr);
	this->_buttons[1] = new SetIpButton(this->_spritemgr);
	this->_buttons[2] = new SetPortButton(this->_spritemgr);
	this->_buttons[3] = new BackMainButton(this->_spritemgr);
	
}

SettingsMenu::~SettingsMenu(void)
{
}
