#include "GameLoop.h"
#include "PlayerShip.h"
#include "Background.h"
#include "Menu.h"

GameLoop::GameLoop(sf::RenderWindow *window)
{
	this->_window = window;
}


GameLoop::~GameLoop(void)
{
}

void	GameLoop::openBackMenu(bool *running)
{
	Menu	backmenu(this->_window, &this->_spritemgr);

	backmenu.menuLoop();
	if (backmenu.getActive() == backmenu.getSize() - 1)
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

void	GameLoop::mainLoop(void)
	{
	PlayerShip			ship(this->_spritemgr.getSpritebyId(SHIP_IDLE));
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