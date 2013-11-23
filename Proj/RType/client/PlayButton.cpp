#include "PlayMenu.h"
#include "PlayButton.h"


PlayButton::PlayButton(SpriteManager *sprmgr)
{
	if (!this->_font.loadFromFile("assets/arial.ttf"))
	{
	}
	this->setSprite(sprmgr->getSpritebyId(MENU_PLAY));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_PLAY_ON));
	this->_sprmgr = sprmgr;
	this->_connectError = false;
}

void	PlayButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	PlayMenu	playmenu(window, this->_sprmgr);

	if (!playmenu.getTcpSuccess())
		this->_connectError = true;
	else
	{
		this->_connectError = false;
		playmenu.menuLoop();
	}
}

void	PlayButton::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	if (this->_connectError)
	{
		_text.setFont(_font);
		_text.setString("Connection error");
		_text.setCharacterSize(30);
		_text.setColor(sf::Color::Cyan);
		_text.setPosition(static_cast<float>(SIZEX / 2) + 250,
			250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
		window->draw(_text);
	}
}

PlayButton::~PlayButton(void)
{
}
