#include "RoomButton.h"
#include "GameLoop.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<RoomButton>;

RoomButton::RoomButton(SpriteManager *sprmgr, std::string name, TCPSocketClient *tcpsock, int id, short udpport) //virer dernier param
{
	this->_udpport = udpport;
	this->_name = name;
	this->_roomId = id;
	this->_tcpsock = tcpsock;
	//this->_comm.setCallback(Opcodes::startLoading, &RoomButton::handleStartLoading);
}

void	RoomButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	this->_comm.TCPsetRoom(this->_p, "jougiere");
	this->_tcpsock->send(this->_p);

	std::cout << "room button action" << std::endl;
	GameLoop	loop(window, this->_tcpsock, 1234); //virer dernier param

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

	//temp
}


RoomButton::~RoomButton(void)
{
}
