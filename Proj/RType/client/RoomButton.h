#pragma once
#include <string>
#include "Button.h"
#include "TCPSocketClient.h"
#include "UDPSocketClient.h"
#include "ClientCommunication.hpp"

class RoomButton :
	public Button
{
	std::string						_name;
	short							_udpport;
	int								_roomId;
	ClientCommunication<RoomButton>	_comm;
	TCPSocketClient					*_tcpsock;
	Packet							_p;
public:
	RoomButton(SpriteManager *, std::string, TCPSocketClient*, int);
	virtual void		action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void		displayButton(unsigned int, unsigned int, sf::RenderWindow *);
	~RoomButton(void);
};

