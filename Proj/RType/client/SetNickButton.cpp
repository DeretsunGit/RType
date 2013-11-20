#include "SetNickButton.h"


SetNickButton::SetNickButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(SETT_NICK));
	this->setSpriteOn(sprmgr->getSpritebyId(SETT_NICK_ON));
	this->_sett = new SettingsParser("assets/settings.ini");
	this->_nick = this->_sett->getNick();
}

void	SetNickButton::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{
	if (key == sf::Keyboard::Return)
		this->_sett->setNick(this->_nick);
	else
		this->_txthandler.keyPressed(key, &this->_nick);
}

void	SetNickButton::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;

	if (!this->_highlight)
		this->_nick = this->_sett->getNick();
	if (!font.loadFromFile("assets/arial.ttf"))
	{
	}
	text.setFont(font);
	text.setString(this->_nick);
	text.setCharacterSize(30);
	if (this->_highlight)
		text.setColor(sf::Color::Magenta);
	else
		text.setColor(sf::Color::Cyan);
	text.setPosition(static_cast<float>(SIZEX / 2) + 250,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(text);
}

SetNickButton::~SetNickButton(void)
{
}
