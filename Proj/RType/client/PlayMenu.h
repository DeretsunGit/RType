#pragma once
#include "Menu.h"
class PlayMenu :
	public Menu
{
private:
	ClientCommunication<PlayMenu>	_comm;
	TCPSocketClient					*_tcpsock;
	bool							_tcp_success;
	short							_udpport;
public:
	PlayMenu(sf::RenderWindow *, SpriteManager *);
	virtual void					childAction();
	void							parseRoomList(void *);
	//void							handleStartLoading(void *);
	void							defaultCallback(char, IReadableSocket &);
	~PlayMenu(void);
};

