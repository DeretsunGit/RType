#include "MenuManager.h"


MenuManager::MenuManager(void)
{
	this->_window = new sf::RenderWindow(sf::VideoMode(SIZEX, SIZEY), "R-TYPE");
	this->_gameLoop = new GameLoop(this->_window);
}


void	MenuManager::displayMenu(const Menu *menu)
{
	std::vector<sf::Sprite>		buttons;
	
	buttons.resize(menu->getSize());
	for (unsigned int i = 0 ; i < menu->getSize() ; i++)
	{
		if (menu->getActive() == i)
		{
			buttons[i] = this->_spritemgr.getSpritebyId(menu->getSpriteId(i) + menu->getSize());
		}
		else
			buttons[i] = this->_spritemgr.getSpritebyId(menu->getSpriteId(i));
		buttons[i].setPosition(static_cast<float>(SIZEX / 2) - buttons[i].getTextureRect().width,
			250 + static_cast<float>(i) * ((SIZEY - 250)/ static_cast<float>(menu->getSize())));
		this->_window->draw(buttons[i]);
	}
}

void	MenuManager::init(void)
{
	eSprites main[] = {MENU_JOIN, MENU_CREA, MENU_SETT, MENU_CRED, MENU_QUIT};
	Menu::eMenuActions	mainact[] = {Menu::STARTGAME, Menu::QUIT, Menu::OPENSETTINGS, Menu::QUIT, Menu::QUIT};
	eSprites sett[] = {SETT_RESO, SETT_NICK, SETT_SOUN, SETT_SRVL, BACK_MAIN};
	Menu::eMenuActions	settact[] = {Menu::QUIT, Menu::QUIT, Menu::QUIT, Menu::QUIT, Menu::OPENMAIN};
//	this->_menus.insert(std::make_pair("mainmenu", new Menu(5, main, mainact)));
//	this->_menus.insert(std::make_pair("settings", new Menu(5, sett, settact)));
	//this->_activeMenu = this->_menus.find("mainmenu")->second;
	this->menuLoop();
}

void	MenuManager::triggerMenuAction(Menu::eMenuActions action)
{
	switch (action)
	{
		case Menu::QUIT:
			this->_window->close();
			break;
		case Menu::OPENSETTINGS:
			this->_activeMenu = this->_menus.find("settings")->second;
			break;
		case Menu::OPENMAIN:
			this->_activeMenu = this->_menus.find("mainmenu")->second;
			break;
		case Menu::STARTGAME:
			this->_gameLoop->mainLoop();

			break;
	}
}

int		MenuManager::menuLoop(void)
{
	sf::Sprite	logo;
	logo = this->_spritemgr.getSpritebyId(GAME_LOGO);
	logo.setPosition(1400 / 2 - static_cast<float>(logo.getTextureRect().width) / 2, 100);
	
	while (this->_window->isOpen())
	{
		sf::Event event;
        while (this->_window->pollEvent(event))
        {
			if(event.type == sf::Event::Closed)
				this->_window->close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				this->_activeMenu->decActive();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				this->_activeMenu->incActive();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
				;
				//this->triggerMenuAction(this->_activeMenu->getActiveMenuAction());
		}
		this->_window->clear();
		this->_window->draw(logo);
		this->displayMenu(this->_activeMenu);
		this->_window->display();
	}
	return (0);
}

MenuManager::~MenuManager(void)
{
}
