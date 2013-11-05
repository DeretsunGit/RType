#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

#pragma once
#define NB_SPRITES	(31)

enum eSprites
{
	SHIP_IDLE = 0,
	SHIP_DOWN = 1,
	SHIP_DOWNMAX = 2,
	SHIP_UP = 3,
	SHIP_UPMAX = 4,
	ENGINE_SLOW = 5,
	ENGINE_NORM = 6,
	ENGINE_FAST = 7,
	ENGINE_MAXI = 8,
	GAME_LOGO = 9,
	MENU_JOIN = 10,
	MENU_CREA = 11,
	MENU_SETT = 12,
	MENU_CRED = 13,
	MENU_QUIT = 14,
	MENU_JOIN_ON = 15,
	MENU_CREA_ON = 16,
	MENU_SETT_ON = 17,
	MENU_CRED_ON = 18,
	MENU_QUIT_ON = 19,
	SETT_RESO = 20,
	SETT_NICK = 21,
	SETT_SOUN = 22,
	SETT_SRVL = 23,
	BACK_MAIN = 24,
	SETT_RESO_ON = 25,
	SETT_NICK_ON = 26,
	SETT_SOUN_ON = 27,
	SETT_SRVL_ON = 28,
	BACK_MAIN_ON = 29,
	BG_IMG = 30
};

class SpriteManager
{
private:
	std::vector<sf::Sprite>	_sprites;
	sf::Texture				_shiptexture;
	sf::Texture				_menutexture;
	sf::Texture				_bgtexture;
public:
	SpriteManager(void);
	sf::Sprite	getSpritebyId(int);
	~SpriteManager(void);
};

