#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "ESprites.h"

#pragma once
//enum eSprites
//{
//	SHIP_IDLE = 0,
//	SHIP_DOWN = 1,
//	SHIP_DOWNMAX = 2,
//	SHIP_UP = 3,
//	SHIP_UPMAX = 4,
//	ENGINE_SLOW = 5,
//	ENGINE_NORM = 6,
//	ENGINE_FAST = 7,
//	ENGINE_MAXI = 8,
//	GAME_LOGO = 9,
//	MENU_PLAY = 10,
//	MENU_SETT = 11,
//	MENU_CRED = 12,
//	MENU_QUIT = 13,
//	MENU_PLAY_ON = 14,
//	MENU_SETT_ON = 15,
//	MENU_CRED_ON = 16,
//	MENU_QUIT_ON = 17,
//	SETT_RESO = 18,
//	SETT_NICK = 19,
//	SETT_SOUN = 20,
//	SETT_SRVL = 21,
//	BACK_MAIN = 22,
//	SETT_RESO_ON = 23,
//	SETT_NICK_ON = 24,
//	SETT_SOUN_ON = 25,
//	SETT_SRVL_ON = 26,
//	BACK_MAIN_ON = 27,
//	BG_IMG = 28,
//	CREDITS = 29,
//	WALL = 30
//};

class SpriteManager
{
private:
	std::vector<sf::Sprite>	_sprites;
	sf::Texture				_shiptexture;
	sf::Texture				_menutexture;
	sf::Texture				_bgtexture;
	sf::Texture				_creditstexture;
	sf::Texture				_walltexture;
public:
	SpriteManager(void);
	sf::Sprite	getSpritebyId(int);
	~SpriteManager(void);
};

