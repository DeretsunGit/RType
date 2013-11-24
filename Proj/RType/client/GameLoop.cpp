#include "GameLoop.h"
#include "PlayerShip.h"
#include "Background.h"
#include "IngameMenu.h"
#include "Clock.hpp"
#include "ClientCommunication.cpp"
#include "rtype_common.h"
#include "SystemException.h"

template class ClientCommunication<GameLoop>;

GameLoop::GameLoop(sf::RenderWindow *window, TCPSocketClient* tcpsock)
{
	this->_udpState = LOADING;
	this->_window = window;
	this->_udpsock = NULL;
	this->_tcpsock = tcpsock;
	this->_comm.setHandler(this);
	this->_comm.setDefaultCallback(&GameLoop::defaultCallback);
	this->_comm.setCallback(Opcodes::UDPOkay, &GameLoop::handleUDPOkay);
	this->_comm.setCallback(Opcodes::screenState, &GameLoop::handleScreenState);
	this->_comm.setCallback(Opcodes::startLoading, &GameLoop::handleStartLoading);
	this->_comm.setCallback(Opcodes::roomState, &GameLoop::handleRoomState);
	this->_set = new SettingsParser("assets/settings.ini");
	this->_started = false;
	if (!_font.loadFromFile("assets/arial.ttf"))
		std::cerr << "Error loading font" << std::endl;
	for (int i = 0 ; i < 4 ; i++)
	{
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		_text[i].setPosition(static_cast<float>(800), static_cast<float>(250 + i * 100));
	}
	this->_comm.TCProomState(*this->_tcpsock);
	this->_roomStateFilled = false;
}

GameLoop::~GameLoop(void)
{

}

void	GameLoop::drawScreenState(void)
{
	std::list<std::pair<unsigned int, t_coord> >::iterator  it(this->_screenstate.elements.begin());
	std::list<std::pair<unsigned int, t_coord> >::iterator  end(this->_screenstate.elements.end());

	if (this->_screenstate.elements.size() > 0)
	{
		while (it != end)
		{
			//std::cout << "id sprite : " << static_cast<eSprites>(it->first) << " pakasté : " << it->first << std::endl;
			this->displaySprite(it->second._posX, it->second._posY, static_cast<eSprites>(it->first));
			++it;
		}
	}
}

void	GameLoop::handleScreenState(void *data)
{
	s_screen_state*	state(static_cast<s_screen_state*>(data));

	if (state->elements.size() == 0)
		return;
	this->_screenstate = *state;
}

eUdpState	GameLoop::getUdpState(void) const
{
	return this->_udpState;
}

void	GameLoop::handleStartLoading(void *data)
{
	s_start_loading*	loader(static_cast<s_start_loading*>(data));

	std::cout << loader->udp << std::endl;
	try
	{
		this->_udpsock = new UDPSocketClient(this->_set->getServer().c_str(), loader->udp);
	}
	catch (SystemException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_udpState = FAILURE;
		return;
	}
	this->_udpState = SUCCESS;
	this->_comm.UDPReady(this->_p, this->_set->getNick().c_str());
	this->_udpsock->send(this->_p);
}

void			GameLoop::defaultCallback(char opcode, IReadableSocket& sock)
{
	//std::cout << "default callbak opcode :" << (int)opcode << std::endl;
}

void	GameLoop::readyUp(void)
{
	this->_comm.TCPsetReady(this->_p);
	this->_tcpsock->send(this->_p);
	
}

void	GameLoop::handleUDPOkay(void *data)
{
	this->_comm.TCPletsPlay(this->_p);
	this->_tcpsock->send(this->_p);
	this->_started = true;
}

void	GameLoop::openBackMenu(bool *running)
{
	IngameMenu	igmenu(this->_window, &this->_spritemgr);

	igmenu.menuLoop();
	if (igmenu.getActive() == igmenu.getSize() - 1)
		*running = false;
}

void	GameLoop::manageEvent(bool *running, PlayerShip *player)
{
	sf::Event event;
	this->_input.fire = 0;
	this->_input.shield = LIGHT;
	this->_input.x = 0;
	this->_input.y = 0;
    while (this->_window->pollEvent(event))
    {
		switch (event.type)
		{
			case sf::Event::Closed:
				this->_window->close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					this->openBackMenu(running);
					break;
				case sf::Keyboard::Up:
					this->_input.y = 2;
					break;
				case sf::Keyboard::Right:
					this->_input.x = 1;
					break;
				case sf::Keyboard::Left:
					this->_input.x = 2;
					break;
				case sf::Keyboard::Down:
					this->_input.y = 1;
					break;
				case sf::Keyboard::F1:
					if (this->_started) {
						this->readyUp();
					}
					break;
				}
				break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->openBackMenu(running);
	}
}

void	GameLoop::sendMovement()
{
	this->_comm.UDPinputs(this->_p, this->_input);
	this->_udpsock->send(this->_p);
}

void	GameLoop::displaySprite(short x, short y, eSprites id)
{
	sf::Sprite	tmp = this->_spritemgr.getSpritebyId(id);

	tmp.setPosition(x, y);
	this->_window->draw(tmp);
}

void	GameLoop::initNetwork(void)
{
	while (this->_udpsock == NULL)
	{
		this->_comm.interpretCommand(*this->_tcpsock);
	}
	this->_comm.interpretCommand(*this->_udpsock);
}

void	GameLoop::handleNetwork(void)
{
	if (!_started)
	{
		this->_comm.interpretCommand(*this->_tcpsock);
		this->_comm.TCProomState(*this->_tcpsock);
	}
	else
	{
		this->_comm.interpretCommand(*this->_udpsock);
		this->_comm.UDPscreenState(*this->_udpsock);
	}
}

void		GameLoop::handleRoomState(void *data)
{
	std::cout << "handleroomstate" << std::endl;
	s_room_state_info*	state(static_cast<s_room_state_info*>(data));
	
	this->_roomstate = *state;
	this->_roomStateFilled = true;
}

void	GameLoop::drawLobby(void)
{
	unsigned int i = 0;
	std::string	tmp;
	
	std::cout << "drawlobby" << std::endl;
	if (this->_roomStateFilled)
	{
		while (i < 4)
		{
			std::cout << "in da loop" << std::endl;
			tmp = "Name: ";
			tmp.append(_roomstate.players[i]);
			tmp.append((_roomstate.playerState[i] ? "Ready" : "Waiting"));
			_text[i].setString(tmp);
			++i;
			this->_window->draw(_text[i]);
		}
		if (this->_udpState != SUCCESS)
			this->_udpState = SUCCESS;
	}
	std::cout << "end drawlobby" << std::endl;
}

void	GameLoop::mainLoop(void)
{
	PlayerShip			ship(this->_spritemgr.getSpritebyId(SHIP_BLUE_IDLE));
	Background			bg(this->_spritemgr.getSpritebyId(BG_IMG));
	Clock				loopTimer;
	float				execTime;
	bool				running = true;
	bool				initNet = true;
	

	std::cout << "mainloop" << std::endl;
	while (running)
    {
		if (this->_started && initNet) {
			initNet = false;
			this->initNetwork();
		}
		this->_window->clear();
		loopTimer.initialise();
		this->handleNetwork();
        this->manageEvent(&running, &ship);
		if (running && _started)
			this->sendMovement();
		if (running)
		{
			std::cout << "ife" << std::endl;
			bg.moveBackground();
			this->_window->draw(bg.getSprite());
			if (!this->_started)
			{
				std::cout << "!started" << std::endl;
				this->drawLobby();
			}
			else
			{
				this->drawScreenState();
			}
			this->_window->display();
		}
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(GAMELOOPTIME - execTime));
    }
}