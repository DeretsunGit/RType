#pragma once
#include <string>
#include "Button.h"
#include "SettingsParser.h"
#include "TextHandler.h"
#include "TCPSocketClient.h"
#include "ClientCommunication.hpp"

class CreateRoomButton :
	public Button
{
	sf::Sprite								_sprite;
	SettingsParser							*_sett;
	std::string								_roomname;
	TextHandler								_txthandler;
	ClientCommunication<CreateRoomButton>	_comm;
	TCPSocketClient							*_tcpsock;
	Packet									_p;
public:
	CreateRoomButton(SpriteManager *, TCPSocketClient *);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void	extraDisplay(unsigned int, unsigned int, sf::RenderWindow *);
	~CreateRoomButton(void);
};
