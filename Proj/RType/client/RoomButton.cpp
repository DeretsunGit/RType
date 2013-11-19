#include "RoomButton.h"
#include "GameLoop.h"


RoomButton::RoomButton(SpriteManager *sprmgr, std::string name)
{
	this->_name = name;
}

void	RoomButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	GameLoop	loop(window, 1234);

	*running = false;
	loop.mainLoop();
}

void	RoomButton::displayButton(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("assets/arial.ttf"))
	{
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

void			RoomButton::setUdpPort(short port)
{
	this->_udpport = port;
}


short			RoomButton::getUdpPort(void) const
{
	return this->_udpport;
}

RoomButton::~RoomButton(void)
{
}
