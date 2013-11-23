#pragma once

#define NB_SPRITES	(67)

enum eSprites
{
	SHIP_BLUE_IDLE = 0,
	SHIP_BLUE_DOWN = 1,
	SHIP_BLUE_DOWNMAX = 2,
	SHIP_BLUE_UP = 3,
	SHIP_BLUE_UPMAX = 4,
	SHIP_GREEN_IDLE = 5,
	SHIP_GREEN_DOWN = 6,
	SHIP_GREEN_DOWNMAX = 7,
	SHIP_GREEN_UP = 8,
	SHIP_GREEN_UPMAX = 9,
	SHIP_YELLOW_IDLE = 10,
	SHIP_YELLOW_DOWN = 11,
	SHIP_YELLOW_DOWNMAX = 12,
	SHIP_YELLOW_UP = 13,
	SHIP_YELLOW_UPMAX = 14,
	SHIP_RED_IDLE = 15,
	SHIP_RED_DOWN = 16,
	SHIP_RED_DOWNMAX = 17,
	SHIP_RED_UP = 18,
	SHIP_RED_UPMAX = 19,
	ENGINE_SLOW = 20,
	ENGINE_NORM = 21,
	ENGINE_FAST = 22,
	ENGINE_MAXI = 23,
	WALL_UP = 24,
	WALL_DOWN = 25,
	BULLETS_PLAYER = 26,
	BULLETS_AI = 27,
	ENEMY_RED_1 = 28,
	ENEMY_RED_2 = 29,
	ENEMY_RED_3 = 30,
	ENEMY_RED_4 = 31,
	ENEMY_RED_5 = 32,
	ENEMY_RED_6 = 33,
	ENEMY_RED_7 = 34,
	ENEMY_RED_8 = 35,
	GAME_LOGO, 
	MENU_PLAY,
	MENU_SETT,
	MENU_CRED,
	MENU_QUIT,
	MENU_PLAY_ON,
	MENU_SETT_ON,
	MENU_CRED_ON,
	MENU_QUIT_ON,
	SETT_RESO,
	SETT_NICK,
	SETT_SOUN,
	SETT_SRVL,
	SETT_PORT,
	BACK_MAIN,
	SETT_RESO_ON,
	SETT_NICK_ON,
	SETT_SOUN_ON,
	SETT_SRVL_ON,
	SETT_PORT_ON,
	BACK_MAIN_ON,
	CREATE_ROOM,
	CREATE_ROOM_ON,
	JOIN_ROOM,
	JOIN_ROOM_ON,
	BG_IMG,
	CREDITS
};