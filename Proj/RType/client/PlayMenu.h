#pragma once
#include "Menu.h"
class PlayMenu :
	public Menu
{
private:
	ClientCommunication<PlayMenu>	_comm;
	TCPSocketClient					*_tcpsock;
public:
	PlayMenu(sf::RenderWindow *, SpriteManager *);
	virtual void			childAction();
	void					parseRoomList(void *data);
	void					defaultCallback(char opcode, IReadableSocket &);
	~PlayMenu(void);
};

