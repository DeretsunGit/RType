#include "RoomButton.h"
#include "GameLoop.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<RoomButton>;

RoomButton::RoomButton(SpriteManager *sprmgr, std::string name, TCPSocketClient *tcpsock, int id)
{
	this->_name = name;
	this->_roomId = id;
	this->_tcpsock = tcpsock;
	if (!_font.loadFromFile("assets/arial.ttf"))
	{
		std::cerr << "Error loading font" << std::endl;
	}
	_text.setFont(_font);
	_text.setString(this->_name);
	_text.setCharacterSize(30);
}

void	RoomButton::action(sf::Keyboard::Key, sf::RenderWindow *window, bool *running)
{
	GameLoop	loop(window, this->_tcpsock);
	this->_comm.TCPselectRoom(this->_p, this->_roomId);
	this->_tcpsock->send(this->_p);

	while (loop.getUdpState() == LOADING);
	*running = false;
	if (loop.getUdpState() == SUCCESS)
		loop.mainLoop();
	else
		return;
}

void	RoomButton::displayButton(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	if (this->_highlight)
		_text.setColor(sf::Color::Magenta);
	else
		_text.setColor(sf::Color::Cyan);
	_text.setPosition(static_cast<float>(SIZEX / 2) - _text.getGlobalBounds().width,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(_text);
}


RoomButton::~RoomButton(void)
{
}
