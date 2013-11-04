#include <SFML/Graphics.hpp>

#pragma once
class Drawable
{
protected:
	sf::Sprite				_sprite;
public:
	Drawable(sf::Sprite);
	float			getPosX() const;
	float			getPosY() const;
	sf::Sprite		getSprite() const;
	void			setPosX(float);
	void			setPosY(float);
	void			setSprite(sf::Sprite);
	~Drawable(void);
};

