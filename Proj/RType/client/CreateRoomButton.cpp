#include "CreateRoomButton.h"
#include "ClientCommunication.cpp"
#include "GameLoop.h"

template class ClientCommunication<CreateRoomButton>;

CreateRoomButton::CreateRoomButton(SpriteManager *sprmgr, TCPSocketClient *tcpsock)
{
	this->setSprite(sprmgr->getSpritebyId(CREATE_ROOM));
	this->setSpriteOn(sprmgr->getSpritebyId(CREATE_ROOM_ON));
	this->_sett = new SettingsParser("assets/settings.ini");
	//this->_comm.setHandler(this);
	this->_roomname = "New Room";
	this->_tcpsock = tcpsock;
}

void	CreateRoomButton::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{
	if (key == sf::Keyboard::Return)
	{
		this->_comm.TCPsetRoom(this->_p, this->_roomname.c_str());
		this->_tcpsock->send(this->_p);
		std::cout << "room button action" << std::endl;
		GameLoop	loop(window, this->_tcpsock); //virer dernier param
		*running = false;
		loop.mainLoop();
	}
	else
		this->_txthandler.keyPressed(key, &this->_roomname);
}

void	CreateRoomButton::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("assets/arial.ttf"))
	{
	}
	text.setFont(font);
	text.setString(this->_roomname);
	text.setCharacterSize(30);
	if (this->_highlight)
		text.setColor(sf::Color::Magenta);
	else
		text.setColor(sf::Color::Cyan);
	text.setPosition(static_cast<float>(SIZEX / 2) + 250,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
	window->draw(text);
}

CreateRoomButton::~CreateRoomButton(void)
{
}
