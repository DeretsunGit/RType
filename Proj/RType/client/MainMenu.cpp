#include "MainMenu.h"
#include "PlayButton.h"
#include "SettingsButton.h"
#include "CreditsButton.h"
#include "QuitButton.h"

MainMenu::MainMenu(sf::RenderWindow *window, SpriteManager *spritemgr) : Menu(window, spritemgr)
{
	Packet p;
	unsigned short res[2] = {1600, 900}; //recup via seufeumeul
	this->_size = 4;
	this->_buttons.resize(this->_size);
	this->_buttons[0] = new PlayButton(this->_spritemgr);
	this->_buttons[1] = new SettingsButton(this->_spritemgr);
	this->_buttons[2] = new CreditsButton(this->_spritemgr);
	this->_buttons[3] = new QuitButton(this->_spritemgr);
}

MainMenu::~MainMenu(void)
{
}
