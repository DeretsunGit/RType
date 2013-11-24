#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteManager.h"
#include "PlayerShip.h"
#include "ClientCommunication.hpp"
#include "UDPSocketClient.h"
#include "TCPSocketClient.h"
#include "SettingsParser.h"

#pragma once

enum eUdpState
{
	LOADING,
	SUCCESS,
	FAILURE
};

class GameLoop
{
private:
	SpriteManager					_spritemgr;
	SettingsParser					*_set;
	sf::RenderWindow				*_window;
	ClientCommunication<GameLoop>	_comm;
	UDPSocketClient					*_udpsock;
	TCPSocketClient					*_tcpsock;
	Packet							_p;
	s_screen_state					_screenstate;
	s_inputs						_input;
	eUdpState						_udpState;
	s_room_state_info				_roomstate;
	bool							_started;
	bool							_roomStateFilled;
	sf::Font						_font;
	sf::Text						_text[4];
public:
	GameLoop(sf::RenderWindow*, TCPSocketClient*);
	void		manageEvent(bool *, PlayerShip *);
	void		openBackMenu(bool *);
	void		drawBackground(void);
	void		displaySprite(short, short, eSprites);
	void		handleUDPOkay(void *);
	void		handleStartLoading(void *);
	void		handleScreenState(void *);
	void		defaultCallback(char, IReadableSocket&);
	void		handleNetwork(bool*);
	void		mainLoop(void);
	void		initNetwork(void);
	void		drawScreenState(void);
	void		sendMovement(void);
	eUdpState	getUdpState(void) const;
	void		readyUp(void);
	void		drawLobby(void);
	void		handleRoomState(void *);
	~GameLoop(void);
};

