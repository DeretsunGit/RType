#pragma once
#include <string>
#include <list>
#include "Button.h"
#include "SettingsParser.h"
#include "TextHandler.h"
#include "TCPSocketClient.h"
#include "ClientCommunication.hpp"

class JoinRoomButton :
	public Button
{
	sf::Sprite								_sprite;
	SettingsParser							*_sett;
	std::string								_roomname;
	TextHandler								_txthandler;
	ClientCommunication<JoinRoomButton>		_comm;
	TCPSocketClient							*_tcpsock;
	Packet									_p;
	std::list<s_room_info>					_list;
	SpriteManager							*_sprmgr;
public:
	JoinRoomButton(SpriteManager *, TCPSocketClient *, std::list<s_room_info>);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	~JoinRoomButton(void);
};
