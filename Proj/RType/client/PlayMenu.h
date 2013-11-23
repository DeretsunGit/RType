#pragma once
#include "Menu.h"
#include "SettingsParser.h"

class PlayMenu :
	public Menu
{
private:
	ClientCommunication<PlayMenu>	_comm;
	TCPSocketClient					*_tcpsock;
	bool							_tcp_success;
	short							_udpport;
	SettingsParser					*_set;
public:
	PlayMenu(sf::RenderWindow *, SpriteManager *);
	virtual void					childAction();
	void							parseRoomList(void *);
	//void							handleStartLoading(void *);
	void							defaultCallback(unsigned int, IReadableSocket &);
	bool							getTcpSuccess(void) const;
	~PlayMenu(void);
};

