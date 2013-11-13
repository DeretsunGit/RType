#include "RoomButton.h"


RoomButton::RoomButton(SpriteManager *sprmgr, std::string name)
{
	this->_name = name;
}

void	RoomButton::action(sf::Keyboard::Key, sf::RenderWindow *window)
{
	window->close();
}

void	RoomButton::displayButton(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("assets/arial.ttf"))
	{
		// error...
	}
	text.setFont(font);
	text.setString(this->_name);
	text.setCharacterSize(30);
	if (this->_highlight)
		text.setColor(sf::Color::Magenta);
	else
		text.setColor(sf::Color::Cyan);
	text.setPosition(static_cast<float>(SIZEX / 2) - text.getGlobalBounds().width,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(text);
}

RoomButton::~RoomButton(void)
{
}
