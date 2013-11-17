#pragma once
#include "Menu.h"
class PlayMenu :
	public Menu
{
private:
	ClientCommunication<Menu>	_comm;
	TCPSocketClient				*_tcpsock;
public:
	PlayMenu(sf::RenderWindow *, SpriteManager *, eMenus);
	virtual void			childAction();
	void					parseRoomList(void *data);
	void					defaultCallback(char opcode, IReadableSocket &);
	~PlayMenu(void);
};

