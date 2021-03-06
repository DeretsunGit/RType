#include "SpriteManager.h"
#include <iostream>


SpriteManager::SpriteManager(void)
{
	//segfault, faire une gestion derreur un peu moins inexistante
	if (!this->_shiptexture.loadFromFile("assets/ship.gif") ||
		!this->_menutexture.loadFromFile("assets/menu.png") ||
		!this->_bgtexture.loadFromFile("assets/bg.png")	||
		!this->_bgtexture2.loadFromFile("assets/bg2.png") ||
		!this->_creditstexture.loadFromFile("assets/credits.png") ||
		!this->_walltexture.loadFromFile("assets/mur.png")	||
		!this->_enemyTexture.loadFromFile("assets/enemy.gif") ||
		!this->_bgmenutexture.loadFromFile("assets/menubg.jpg"))
		std::cerr << "Error opening texture file" << std::endl;
	this->_sprites.resize(NB_SPRITES);
	for (int i = SHIP_BLUE_IDLE ; i <= SHIP_RED_UPMAX ; i++)
	{
		this->_sprites[i].setTexture(this->_shiptexture);
		this->_sprites[i].setScale(3, 3);
	}
	for (int i = GAME_LOGO ; i <= JOIN_ROOM_ON ; i++)
	{
		this->_sprites[i].setTexture(this->_menutexture);
	}
	for (int i = ENEMY_RED_1 ; i <= ENEMY_RED_8 ; i++)
	{
		this->_sprites[i].setTexture(this->_enemyTexture);

	}
	this->_sprites[WALL_DOWN].setTexture(this->_walltexture);
	this->_sprites[WALL_UP].setTexture(this->_walltexture);
	this->_sprites[CREDITS].setTexture(this->_creditstexture);
	this->_sprites[BG_IMG].setTexture(this->_bgtexture);
	this->_sprites[BG_IMG2].setTexture(this->_bgtexture2);
	this->_sprites[BG_IMG_MENU].setTexture(this->_bgmenutexture);
	this->_sprites[SHIP_BLUE_IDLE].setTextureRect(sf::IntRect(67, 0, 33, 18));
	this->_sprites[SHIP_BLUE_UPMAX].setTextureRect(sf::IntRect(123, 0, 32, 18));
	this->_sprites[SHIP_BLUE_UP].setTextureRect(sf::IntRect(90, 0, 32, 18));
	this->_sprites[SHIP_BLUE_DOWNMAX].setTextureRect(sf::IntRect(0, 0, 32, 18));
	this->_sprites[SHIP_BLUE_DOWN].setTextureRect(sf::IntRect(33, 0, 32, 18));
	this->_sprites[SHIP_RED_IDLE].setTextureRect(sf::IntRect(67, 18, 33, 18));
	this->_sprites[SHIP_RED_UPMAX].setTextureRect(sf::IntRect(123, 18, 32, 18));
	this->_sprites[SHIP_RED_UP].setTextureRect(sf::IntRect(90, 18, 32, 18));
	this->_sprites[SHIP_RED_DOWNMAX].setTextureRect(sf::IntRect(0, 18, 32, 14));
	this->_sprites[SHIP_RED_DOWN].setTextureRect(sf::IntRect(33, 18, 32, 14));
	this->_sprites[SHIP_GREEN_IDLE].setTextureRect(sf::IntRect(67, 36, 33, 18));
	this->_sprites[SHIP_GREEN_UPMAX].setTextureRect(sf::IntRect(123, 36, 32, 14));
	this->_sprites[SHIP_GREEN_UP].setTextureRect(sf::IntRect(90, 36, 32, 14));
	this->_sprites[SHIP_GREEN_DOWNMAX].setTextureRect(sf::IntRect(0, 36, 32, 14));
	this->_sprites[SHIP_GREEN_DOWN].setTextureRect(sf::IntRect(33, 36, 32, 14));
	this->_sprites[SHIP_YELLOW_IDLE].setTextureRect(sf::IntRect(67, 54, 33, 18));
	this->_sprites[SHIP_YELLOW_UPMAX].setTextureRect(sf::IntRect(123, 54, 32, 14));
	this->_sprites[SHIP_YELLOW_UP].setTextureRect(sf::IntRect(90, 54, 32, 14));
	this->_sprites[SHIP_YELLOW_DOWNMAX].setTextureRect(sf::IntRect(0, 54, 32, 14));
	this->_sprites[SHIP_YELLOW_DOWN].setTextureRect(sf::IntRect(33, 54, 32, 14));
	//this->_sprites[ENGINE_SLOW].setTextureRect(sf::IntRect(234, 18, 32, 32));
	//this->_sprites[ENGINE_NORM].setTextureRect(sf::IntRect(200, 18, 32, 32));
	//this->_sprites[ENGINE_FAST].setTextureRect(sf::IntRect(167, 18, 32, 32));
	//this->_sprites[ENGINE_MAXI].setTextureRect(sf::IntRect(134, 18, 32, 32));
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
	this->_sprites[CREATE_ROOM].setTextureRect(sf::IntRect(0, 730, 450, 54));
	this->_sprites[JOIN_ROOM].setTextureRect(sf::IntRect(0, 790, 450, 54));
	this->_sprites[SETT_RESO_ON].setTextureRect(sf::IntRect(480, 400, 450, 54));
	this->_sprites[SETT_SOUN_ON].setTextureRect(sf::IntRect(480, 450, 450, 54));
	this->_sprites[SETT_NICK_ON].setTextureRect(sf::IntRect(480, 510, 450, 54));
	this->_sprites[SETT_SRVL_ON].setTextureRect(sf::IntRect(480, 560, 450, 54));
	this->_sprites[BACK_MAIN_ON].setTextureRect(sf::IntRect(480, 620, 450, 54));
	this->_sprites[SETT_PORT_ON].setTextureRect(sf::IntRect(480, 675, 450, 54));
	this->_sprites[CREATE_ROOM_ON].setTextureRect(sf::IntRect(480, 730, 450, 54));
	this->_sprites[JOIN_ROOM_ON].setTextureRect(sf::IntRect(480, 790, 450, 54));
	this->_sprites[ENEMY_RED_1].setTextureRect(sf::IntRect(2, 3, 25, 30));
	this->_sprites[ENEMY_RED_2].setTextureRect(sf::IntRect(35, 3, 25, 30));
	this->_sprites[ENEMY_RED_3].setTextureRect(sf::IntRect(70, 3, 25, 30));
	this->_sprites[ENEMY_RED_4].setTextureRect(sf::IntRect(95, 3, 25, 30));
	this->_sprites[ENEMY_RED_5].setTextureRect(sf::IntRect(120, 3, 25, 30));
	this->_sprites[ENEMY_RED_6].setTextureRect(sf::IntRect(145, 3, 25, 30));
	this->_sprites[ENEMY_RED_7].setTextureRect(sf::IntRect(170, 3, 25, 30));
	this->_sprites[ENEMY_RED_8].setTextureRect(sf::IntRect(195, 3, 25, 30));
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