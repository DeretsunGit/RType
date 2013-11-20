#include "Menu.h"
#include "PlayButton.h"
#include "SettingsButton.h"
#include "CreditsButton.h"
#include "QuitButton.h"
#include "RoomButton.h"
#include "BackMainButton.h"
#include "BackGameButton.h"

Menu::Menu(sf::RenderWindow *window, SpriteManager *spritemgr)
{
	this->_active = 0;
	this->_spritemgr = spritemgr;
	this->_window = window;
}

Menu::Menu(Menu &ref)
{
	this->_active = ref.getActive();
	this->_size = ref.getSize();
	this->_buttons.resize(this->_size);
	this->_window = ref.getWindow();
	this->_spritemgr = ref.getSpriteMgr();
	for (int i = 0 ; i < this->_size ; i++)
	{
		this->_buttons[i] = ref._buttons[i];
	}

}

void			Menu::setMenuContent(eMenus menu)
{
	switch (menu)
	{
	case	MAIN:
		this->_size = 4;
		this->_buttons.resize(this->_size);
		this->_buttons[0] = new PlayButton(this->_spritemgr);
		this->_buttons[1] = new SettingsButton(this->_spritemgr);
		this->_buttons[2] = new CreditsButton(this->_spritemgr);
		this->_buttons[3] = new QuitButton(this->_spritemgr);
		break;
	/*case	PLAY:
		this->_size = 4;
		this->_buttons.resize(this->_size);
		this->_buttons[0] = new RoomButton(this->_spritemgr, "LA ROOM 2 LA MOR");
		this->_buttons[1] = new RoomButton(this->_spritemgr, "[EASY][NO AWP][16000$]");
		this->_buttons[2] = new RoomButton(this->_spritemgr, "only fags");
		this->_buttons[3] = new RoomButton(this->_spritemgr, "give diretide");
		break;*/
	case	INGAME:
		this->_size = 2;
		this->_buttons.resize(this->_size);
		this->_buttons[0] = new BackGameButton(this->_spritemgr);
		this->_buttons[1] = new BackMainButton(this->_spritemgr);
		break;
	}
}

void			Menu::displayMenu() const
{
	for (unsigned int i = 0; i < _size; i++)
	{
		if (i == _active)
			this->_buttons[i]->setHighlight(true);
		else
			this->_buttons[i]->setHighlight(false);
		this->_buttons[i]->displayButton(i, _size, this->_window);
	}
}

void			Menu::menuLoop()
{
	sf::Sprite	logo;
	bool		running = true;

	logo = this->_spritemgr->getSpritebyId(GAME_LOGO);
	logo.setPosition(1400 / 2 - static_cast<float>(logo.getTextureRect().width) / 2, 100); 
	while (running)
	{
		this->childAction();
		sf::Event event;
        while (this->_window->pollEvent(event))
        {
			if(event.type == sf::Event::Closed)
				this->_window->close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				running = false;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				this->decActive();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				this->incActive();
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return ||
				(event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Num9) ||
				event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Period))
				this->_buttons[this->_active]->action(event.key.code, this->_window, &running);
		}
		this->_window->clear();
		this->_window->draw(logo);
		this->displayMenu();
		this->_window->display();
	}
	return;
}

void			Menu::setActive(unsigned int id)
{
	this->_active = id;
}

void			Menu::incActive(void)
{
	if (this->_active < this->_size - 1)
		this->_active++;
}


void			Menu::decActive(void)
{
	if (this->_active > 0)
		this->_active--;
}


unsigned int				Menu::getActive(void) const
{
	return this->_active;
}


unsigned int				Menu::getSize(void) const
{
	return this->_size;
}

sf::RenderWindow*			Menu::getWindow() const
{
	return this->_window;
}

SpriteManager*				Menu::getSpriteMgr(void) const
{
	return this->_spritemgr;
}

void			Menu::childAction()
{

}

Menu::~Menu(void)
{

}