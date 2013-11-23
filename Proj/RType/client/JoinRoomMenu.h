#pragma once
#include "Menu.h"
#include "TCPSocketClient.h"

class JoinRoomMenu :
	public Menu
{
private:

public:
	JoinRoomMenu(sf::RenderWindow *, SpriteManager *, TCPSocketClient *, std::list<s_room_info>	*);
	~JoinRoomMenu(void);
};

