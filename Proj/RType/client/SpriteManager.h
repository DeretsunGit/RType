#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "ESprites.h"

#pragma once

class SpriteManager
{
private:
	std::vector<sf::Sprite>	_sprites;
	sf::Sprite				_defaultSprite;
	sf::Texture				_shiptexture;
	sf::Texture				_menutexture;
	sf::Texture				_bgtexture;
	sf::Texture				_bgtexture2;
	sf::Texture				_creditstexture;
	sf::Texture				_walltexture;
	sf::Texture				_enemyTexture;
public:
	SpriteManager(void);
	sf::Sprite	getSpritebyId(int);
	~SpriteManager(void);
};

