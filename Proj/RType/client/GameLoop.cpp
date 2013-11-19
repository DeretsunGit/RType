#include "GameLoop.h"
#include "PlayerShip.h"
#include "Background.h"
#include "IngameMenu.h"
#include "ClientCommunication.cpp"

template class ClientCommunication<GameLoop>;

GameLoop::GameLoop(sf::RenderWindow *window, short udpport)
{
	this->_window = window;
	this->_udpsock = new UDPSocketClient("127.0.0.1", udpport);
//	this->_comm.UDPsayHello(p, "ledp", res);
//	this->_udpsock->send(p);
}

GameLoop::~GameLoop(void)
{
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

void	GameLoop::mainLoop(void)
{
	PlayerShip			ship(this->_spritemgr.getSpritebyId(SHIP_BLUE_IDLE));
	Background			bg(this->_spritemgr.getSpritebyId(BG_IMG));
	bool running = true;
	while (running)
    {
        this->manageEvent(&running, &ship);
		if (running)
		{
			this->_window->clear();
			bg.moveBackground();
			this->_window->draw(bg.getSprite());
			this->_window->draw(ship.getSprite());
			this->_window->display();
		}
    }
}