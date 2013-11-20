#include "SetPortButton.h"


SetPortButton::SetPortButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(SETT_PORT));
	this->setSpriteOn(sprmgr->getSpritebyId(SETT_PORT_ON));
	this->_sett = new SettingsParser("assets/settings.ini");
	this->_port = this->_sett->getPort();
}

void	SetPortButton::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{
	if (key == sf::Keyboard::Return)
		this->_sett->setPort(this->_port);
	else
		this->_txthandler.keyPressed(key, &this->_port);
}

void	SetPortButton::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;

	if (!this->_highlight)
		this->_port = this->_sett->getPort();
	if (!font.loadFromFile("assets/arial.ttf"))
	{
	}
	text.setFont(font);
	text.setString(this->_port);
	text.setCharacterSize(30);
	if (this->_highlight)
		text.setColor(sf::Color::Magenta);
	else
		text.setColor(sf::Color::Cyan);
	text.setPosition(static_cast<float>(SIZEX / 2) + 250,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(text);
}

SetPortButton::~SetPortButton(void)
{
}
