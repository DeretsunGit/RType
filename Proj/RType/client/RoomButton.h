#pragma once
#include <string>
#include "Button.h"
class RoomButton :
	public Button
{
	std::string		_name;
	short			_udpport;
public:
	RoomButton(SpriteManager *, std::string);
	virtual void	action(sf::Keyboard::Key, sf::RenderWindow *, bool *);
	virtual void	displayButton(unsigned int, unsigned int, sf::RenderWindow *);
	void			setUdpPort(short);
	short			getUdpPort(void) const;
	~RoomButton(void);
};

