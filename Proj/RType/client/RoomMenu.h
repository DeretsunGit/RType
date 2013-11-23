#pragma once
#include "Menu.h"
class RoomMenu :
	public Menu
{
private:
	ClientCommunication<RoomMenu>	_comm;
	TCPSocketClient					*_tcpsock;
	bool							_tcp_success;
	short							_udpport;
public:
	RoomMenu(sf::RenderWindow *, SpriteManager *);
	virtual void					childAction();
	void							parseRoomList(void *);
	//void							handleStartLoading(void *);
	void							defaultCallback(char, IReadableSocket &);
	~RoomMenu(void);
};

