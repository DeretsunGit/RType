#include "SetIpButton.h"


SetIpButton::SetIpButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(SETT_SRVL));
	this->setSpriteOn(sprmgr->getSpritebyId(SETT_SRVL_ON));
	this->_sett = new SettingsParser("assets/settings.ini");
	this->_serv = this->_sett->getServer();
}

void	SetIpButton::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{
	switch (key)
	{
	case sf::Keyboard::BackSpace:
		this->_serv = this->_serv.substr(0, this->_serv.length() - 1);
		break;

	}
}

void	SetIpButton::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("assets/arial.ttf"))
	{
	}
	text.setFont(font);
	text.setString(this->_serv);
	text.setCharacterSize(30);
	if (this->_highlight)
		text.setColor(sf::Color::Magenta);
	else
		text.setColor(sf::Color::Cyan);
	text.setPosition(static_cast<float>(SIZEX / 2) + 250,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(text);
}

SetIpButton::~SetIpButton(void)
{
}
