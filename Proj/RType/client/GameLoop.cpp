#include "GameLoop.h"
#include "PlayerShip.h"
#include "Background.h"
#include "IngameMenu.h"
#include "Clock.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<GameLoop>;

GameLoop::GameLoop(sf::RenderWindow *window, TCPSocketClient* tcpsock, short udpport)
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
}

GameLoop::~GameLoop(void)
{

}

void	GameLoop::handleScreenState(void *data)
{
	s_screen_state*	state(static_cast<s_screen_state*>(data));
	std::list<std::pair<u_long, t_coord> >::iterator  it(state->elements.begin());
	std::list<std::pair<u_long, t_coord> >::iterator  end(state->elements.end());

	while (it != end)
	{
		this->displaySprite(it->second._posX, it->second._posY, static_cast<eSprites>(it->first));
		std::cout << "\tSprite " << static_cast<int>(it->first) << " at ("
		<< it->second._posX << ", "
		<< it->second._posY << ')' << std::endl;
		++it;
	}
	std::cout << "--- END SCREEN STATE ---" << std::endl;
}

void	GameLoop::handleStartLoading(void *data)
{
	s_start_loading*	loader(static_cast<s_start_loading*>(data));

	std::cout << loader->udp << std::endl;
	this->_udpsock = new UDPSocketClient("127.0.0.1", loader->udp);
	this->_comm.UDPReady(this->_p, "ledp");
	this->_udpsock->send(this->_p);
}

void			GameLoop::defaultCallback(char opcode, IReadableSocket& sock)
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
    while (this->_window->pollEvent(event))
    {
		switch (event.type)
		{
			case sf::Event::Closed:
				this->_window->close();
				break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->openBackMenu(running);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player->setPosY(player->getPosY() + 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player->setPosY(player->getPosY() - 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player->setPosX(player->getPosX() - 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->setPosX(player->getPosX() + 1);
	}
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
		loopTimer.initialise();
		this->handleNetwork();
        this->manageEvent(&running, &ship);
		if (running)
		{
			this->_window->clear();
			bg.moveBackground();
			this->_window->draw(bg.getSprite());
			this->_window->draw(ship.getSprite());
			this->_window->display();
		}
		execTime = loopTimer.getTimeBySec();
		Sleep((unsigned long)(LOOPTIME - execTime));
    }
}