#include "SpriteManager.h"
#include <iostream>


SpriteManager::SpriteManager(void)
{
	//segfault, faire une gestion derreur un peu moins inexistante
	if (!this->_shiptexture.loadFromFile("assets/ship.gif"))
	{
		std::cerr << "Error opening texture file" << std::endl;
	}
	if (!this->_menutexture.loadFromFile("assets/menu.png"))
	{
		std::cerr << "Error opening texture file" << std::endl;
	}
	if (!this->_bgtexture.loadFromFile("assets/bg.png"))
	{
		std::cerr << "Error opening texture file" << std::endl;
	}
	if (!this->_creditstexture.loadFromFile("assets/credits.png"))
	{
		std::cerr << "Error opening texture file" << std::endl;
	}
	if (!this->_walltexture.loadFromFile("assets/mur.png"))
	{
		std::cerr << "Error opening texture file" << std::endl;
	}
	this->_sprites.resize(NB_SPRITES);
	for (int i = SHIP_BLUE_IDLE ; i <= SHIP_BLUE_UPMAX ; i++)
	{
		this->_sprites[i].setTexture(this->_shiptexture);
	}
	for (int i = GAME_LOGO ; i <= BACK_MAIN_ON ; i++)
	{
		this->_sprites[i].setTexture(this->_menutexture);
	}
	this->_sprites[WALL_DOWN].setTexture(this->_walltexture);
	this->_sprites[WALL_UP].setTexture(this->_walltexture);
	this->_sprites[CREDITS].setTexture(this->_creditstexture);
	this->_sprites[BG_IMG].setTexture(this->_bgtexture);
	this->_sprites[SHIP_BLUE_IDLE].setTextureRect(sf::IntRect(167, 3, 32, 14));
	this->_sprites[SHIP_BLUE_IDLE].setScale(3, 3);
	this->_sprites[SHIP_BLUE_UPMAX].setTextureRect(sf::IntRect(233, 3, 32, 14));
	this->_sprites[SHIP_BLUE_UP].setTextureRect(sf::IntRect(200, 3, 32, 14));
	this->_sprites[SHIP_BLUE_DOWNMAX].setTextureRect(sf::IntRect(134, 3, 32, 14));
	this->_sprites[SHIP_BLUE_DOWN].setTextureRect(sf::IntRect(134, 3, 32, 14));
	this->_sprites[ENGINE_SLOW].setTextureRect(sf::IntRect(234, 18, 32, 32));
	this->_sprites[ENGINE_NORM].setTextureRect(sf::IntRect(200, 18, 32, 32));
	this->_sprites[ENGINE_FAST].setTextureRect(sf::IntRect(167, 18, 32, 32));
	this->_sprites[ENGINE_MAXI].setTextureRect(sf::IntRect(134, 18, 32, 32));
	this->_sprites[GAME_LOGO].setTextureRect(sf::IntRect(0, 0, 480, 85));
	this->_sprites[MENU_PLAY].setTextureRect(sf::IntRect(0, 90, 450, 54));
	this->_sprites[MENU_SETT].setTextureRect(sf::IntRect(0, 213, 450, 54));
	this->_sprites[MENU_CRED].setTextureRect(sf::IntRect(0, 268, 450, 54));
	this->_sprites[MENU_QUIT].setTextureRect(sf::IntRect(0, 325, 450, 54));
	this->_sprites[MENU_PLAY_ON].setTextureRect(sf::IntRect(480, 90, 450, 54));
	this->_sprites[MENU_SETT_ON].setTextureRect(sf::IntRect(480, 213, 450, 54));
	this->_sprites[MENU_CRED_ON].setTextureRect(sf::IntRect(480, 268, 450, 54));
	this->_sprites[MENU_QUIT_ON].setTextureRect(sf::IntRect(480, 325, 450, 54));
	this->_sprites[SETT_RESO].setTextureRect(sf::IntRect(0, 400, 450, 54));
	this->_sprites[SETT_SOUN].setTextureRect(sf::IntRect(0, 450, 450, 54));
	this->_sprites[SETT_NICK].setTextureRect(sf::IntRect(0, 510, 450, 54));
	this->_sprites[SETT_SRVL].setTextureRect(sf::IntRect(0, 560, 450, 54));
	this->_sprites[BACK_MAIN].setTextureRect(sf::IntRect(0, 620, 450, 54));
	this->_sprites[SETT_PORT].setTextureRect(sf::IntRect(0, 675, 450, 54));
	this->_sprites[SETT_RESO_ON].setTextureRect(sf::IntRect(480, 400, 450, 54));
	this->_sprites[SETT_SOUN_ON].setTextureRect(sf::IntRect(480, 450, 450, 54));
	this->_sprites[SETT_NICK_ON].setTextureRect(sf::IntRect(480, 510, 450, 54));
	this->_sprites[SETT_SRVL_ON].setTextureRect(sf::IntRect(480, 560, 450, 54));
	this->_sprites[BACK_MAIN_ON].setTextureRect(sf::IntRect(480, 620, 450, 54));
	this->_sprites[SETT_PORT_ON].setTextureRect(sf::IntRect(480, 675, 450, 54));
}

SpriteManager::~SpriteManager(void)
{

}

sf::Sprite	SpriteManager::getSpritebyId(int id)
{
	if (id > this->_sprites.size())
		return this->_defaultSprite;
	return (this->_sprites[id]);
}