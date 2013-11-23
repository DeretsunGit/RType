#include "GameLoop.h"
#include "PlayerShip.h"
#include "Background.h"
#include "IngameMenu.h"
#include "Clock.h"
#include "ClientCommunication.cpp"
#include "rtype_common.h"

template class ClientCommunication<GameLoop>;

GameLoop::GameLoop(sf::RenderWindow *window, TCPSocketClient* tcpsock)
{
	this->_window = window;
	this->_udpsock = NULL;
	this->_tcpsock = tcpsock;
	this->_comm.setHandler(this);
	this->_comm.setDefaultCallback(&GameLoop::defaultCallback);
	this->_comm.setCallback(Opcodes::UDPOkay, &GameLoop::handleUDPOkay);
	this->_comm.setCallback(Opcodes::screenState, &GameLoop::handleScreenState);
	this->_comm.setCallback(Opcodes::startLoading, &GameLoop::handleStartLoading);
	this->_comm.TCPsetReady(this->_p);
	this->_tcpsock->send(this->_p);
	this->_set = new SettingsParser("assets/settings.ini");
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
			std::cout << "id sprite : " << static_cast<eSprites>(it->first) << " pakasté : " << it->first << std::endl;
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

void	GameLoop::handleStartLoading(void *data)
{
	s_start_loading*	loader(static_cast<s_start_loading*>(data));

	std::cout << loader->udp << std::endl;
	this->_udpsock = new UDPSocketClient(this->_set->getServer().c_str(), loader->udp);
	this->_comm.UDPReady(this->_p, this->_set->getNick().c_str());
	this->_udpsock->send(this->_p);
}

void			GameLoop::defaultCallback(unsigned int opcode, IReadableSocket& sock)
{
	//std::cout << "default callbak opcode :" << (int)opcode << std::endl;
}

void	GameLoop::handleUDPOkay(void *data)
{
	this->_comm.TCPletsPlay(this->_p);
	this->_tcpsock->send(this->_p);
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
					std::cout << "upe" << std::endl;
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

//void	GameLoop::handleNetwork()
//{
//	if (this->_socktype == UDP)
//		this->_comm.interpretCommand(*this->_udpsock);
//	else
//		this->_comm.interpretCommand(*this->_tcpsock);
//}

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
	this->_comm.interpretCommand(*this->_udpsock);
	this->_comm.UDPscreenState(*this->_udpsock);
}

void	GameLoop::mainLoop(void)
{
	PlayerShip			ship(this->_spritemgr.getSpritebyId(SHIP_BLUE_IDLE));
	Background			bg(this->_spritemgr.getSpritebyId(BG_IMG));
	Clock				loopTimer;
	float				execTime;
	bool running = true;
	
	this->initNetwork();
	std::cout << "after initnet" << std::endl;
	while (running)
    {
		this->_window->clear();
		loopTimer.initialise();
		this->handleNetwork();
        this->manageEvent(&running, &ship);
		this->sendMovement();
		if (running)
		{
			bg.moveBackground();
			this->_window->draw(bg.getSprite());
			this->drawScreenState();
			//this->_window->draw(ship.getSprite());
			this->_window->display();
		}
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(GAMELOOPTIME - execTime + 1));
    }
}