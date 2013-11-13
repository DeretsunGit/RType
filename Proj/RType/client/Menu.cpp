#include "Menu.h"
#include "PlayButton.h"
#include "SettingsButton.h"
#include "CreditsButton.h"
#include "QuitButton.h"
#include "RoomButton.h"


Menu::Menu(sf::RenderWindow *window, SpriteManager *spritemgr, eMenus menu)
{
	this->_active = 0;
	this->_spritemgr = spritemgr;
	this->_window = window;
	this->_type = menu;
	this->setMenuContent(menu);
}

void			Menu::setMenuContent(eMenus menu)
{
	switch (menu)
	{
	case	MAIN:
		std::cout << "caz main" << std::endl;
		this->_size = 4;
		this->_buttons.resize(this->_size);
		this->_buttons[0] = new PlayButton(this->_spritemgr);
		this->_buttons[1] = new SettingsButton(this->_spritemgr);
		this->_buttons[2] = new CreditsButton(this->_spritemgr);
		this->_buttons[3] = new QuitButton(this->_spritemgr);
		break;
	case	PLAY:
		this->_size = 4;
		this->_buttons.resize(this->_size);
		this->_buttons[0] = new RoomButton(this->_spritemgr, "LA ROOM 2 LA MOR");
		this->_buttons[1] = new RoomButton(this->_spritemgr, "[EASY][NO AWP][16000$]");
		this->_buttons[2] = new RoomButton(this->_spritemgr, "only fags");
		this->_buttons[3] = new RoomButton(this->_spritemgr, "give diretide");
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
	logo = this->_spritemgr->getSpritebyId(GAME_LOGO);
	logo.setPosition(1400 / 2 - static_cast<float>(logo.getTextureRect().width) / 2, 100); 
	while (this->_window->isOpen()) // a virer absolument, -3 parce que c'est mal cf martin
	{
		sf::Event event;
        while (this->_window->pollEvent(event))
        {
			if(event.type == sf::Event::Closed)
				this->_window->close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				this->decActive();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				this->incActive();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
				this->_buttons[this->_active]->action(event.key.code, this->_window);
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


unsigned int	Menu::getActive(void) const
{
	return (this->_active);
}


unsigned int	Menu::getSize(void) const
{
	return (this->_size);
}


Menu::~Menu(void)
{

}
//
//void			Menu::changeActiveMenu(eMenus menu)
//{
//	this->_crtMenuType = menu;
//	this->_active = 0;
//	switch (menu)
//	{
//		case	MAIN:
//			this->_size = 4;
//			this->_buttons.resize(4);
//			this->_menuActions.resize(4);
//			this->_buttons[0] = MENU_PLAY;
//			this->_buttons[1] = MENU_SETT;
//			this->_buttons[2] = MENU_CRED;
//			this->_buttons[3] = MENU_QUIT;
//			this->_menuActions[0] = &Menu::buttonPlayGame;
//			this->_menuActions[1] = &Menu::buttonSettings;
//			this->_menuActions[2] = &Menu::buttonCredits;
//			this->_menuActions[3] = &Menu::buttonQuit;
//			break;
//		case	SETTINGS:
//			this->_size = 5;
//			this->_buttons.resize(5);
//			this->_menuActions.resize(5);
//			this->_buttons[0] = SETT_RESO;
//			this->_buttons[1] = SETT_NICK;
//			this->_buttons[2] = SETT_SOUN;
//			this->_buttons[3] = SETT_SRVL;
//			this->_buttons[4] = BACK_MAIN;
//			this->_menuActions[0] = &Menu::buttonSetRes;
//			this->_menuActions[1] = &Menu::buttonSetNick;
//			this->_menuActions[2] = &Menu::buttonSetSound;
//			this->_menuActions[3] = &Menu::buttonSetServList;
//			this->_menuActions[4] = &Menu::buttonBackMain;
//			break;
//		case	PLAY:
//			this->_size = 5;
//			this->_buttons.resize(5);
//			this->_menuActions.resize(5);
//			this->_buttons[0] = SETT_RESO;
//			this->_buttons[1] = SETT_NICK;
//			this->_buttons[2] = SETT_SOUN;
//			this->_buttons[3] = SETT_SRVL;
//			this->_buttons[4] = BACK_MAIN;
//			this->_menuActions[0] = &Menu::buttonSetRes;
//			this->_menuActions[1] = &Menu::buttonSetNick;
//			this->_menuActions[2] = &Menu::buttonSetSound;
//			this->_menuActions[3] = &Menu::buttonSetServList;
//			this->_menuActions[4] = &Menu::buttonBackMain;
//			break;
//	}
//}
//

//
//
//eSprites		Menu::getSpriteId(int id) const
//{
//	return this->_buttons[id];
//}
//
//
//void			Menu::displayMenu(void)
//{
//	std::vector<sf::Sprite>		buttons;
//	buttons.resize(this->_size);
//	for (unsigned int i = 0 ; i < this->_size ; i++)
//	{
//		if (this->getActive() == i)
//		{
//			buttons[i] = this->_spriteMgr->getSpritebyId(this->_buttons[i] + this->_size);
//		}
//		else
//			buttons[i] = this->_spriteMgr->getSpritebyId(this->_buttons[i]);
//		buttons[i].setPosition(static_cast<float>(SIZEX / 2) - buttons[i].getTextureRect().width,
//			250 + static_cast<float>(i) * ((SIZEY - 250)/ static_cast<float>(this->_size)));
//		this->_window->draw(buttons[i]);
//	}
//}
//
//
//void		Menu::menuLoop()
//{
//	sf::Sprite	logo;
//	logo = this->_spriteMgr->getSpritebyId(GAME_LOGO);
//	logo.setPosition(1400 / 2 - static_cast<float>(logo.getTextureRect().width) / 2, 100); 
//	while (this->_window->isOpen()) // a virer absolument, -3 parce que c'est mal cf martin
//	{
//		sf::Event event;
//        while (this->_window->pollEvent(event))
//        {
//			if(event.type == sf::Event::Closed)
//				this->_window->close();
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
//				this->decActive();
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
//				this->incActive();
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
//				(this->*_menuActions[_active])(event.key.code);
//		}
//		this->_window->clear();
//		this->_window->draw(logo);
//		this->displayMenu();
//		this->_window->display();
//	}
//	return;
//}
//
//
//void	Menu::showFullScreenSprite(eSprites spriteId)
//{
//	sf::Sprite		sprite;
//	bool			running = true;
//
//	sprite = this->_spriteMgr->getSpritebyId(spriteId);
//	sprite.setPosition(static_cast<float>(SIZEX / 2) - sprite.getTextureRect().width / 2,
//			static_cast<float>(SIZEY / 2) - sprite.getTextureRect().height / 2);
//	while (running)
//	{
//		sf::Event event;
//        while (this->_window->pollEvent(event))
//			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//				running = false;
//		this->_window->clear();
//		this->_window->draw(sprite);
//		this->_window->display();
//	}
//}
//

//
///* MAIN MENU */
//
//void		Menu::buttonPlayGame(sf::Keyboard::Key)
//{
//	this->changeActiveMenu(PLAY);
//}
//void		Menu::buttonSettings(sf::Keyboard::Key)
//{
//	this->changeActiveMenu(SETTINGS);
//}
//
//void		Menu::buttonCredits(sf::Keyboard::Key)
//{
//	this->showFullScreenSprite(CREDITS);
//}
//
//void		Menu::buttonQuit(sf::Keyboard::Key)
//{
//	this->_window->close();
//}
//
///* SETTINGS MENU */
//
//void		Menu::buttonSetRes(sf::Keyboard::Key)
//{
//
//}
//
//void		Menu::buttonSetNick(sf::Keyboard::Key)
//{
//
//}
//
//void		Menu::buttonSetSound(sf::Keyboard::Key)
//{
//
//}
//
//void		Menu::buttonSetServList(sf::Keyboard::Key)
//{
//
//}
//
//void		Menu::buttonBackMain(sf::Keyboard::Key)
//{
//	this->changeActiveMenu(MAIN);
//}