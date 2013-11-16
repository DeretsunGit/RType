#include "Button.h"

Button::Button(void)
{

}

void	Button::setSprite(sf::Sprite sprite)
{
	this->_sprite = sprite;
}

void	Button::setSpriteOn(sf::Sprite sprite)
{
	this->_sprite_on = sprite;
}

void	Button::displayButton(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{
	if (_highlight)
	{
		this->_sprite_on.setPosition(static_cast<float>(SIZEX / 2) - this->_sprite.getTextureRect().width,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
		window->draw(this->_sprite_on);
	}
	else
	{
		this->_sprite.setPosition(static_cast<float>(SIZEX / 2) - this->_sprite.getTextureRect().width,
		250 + static_cast<float>(pos) * ((SIZEY - 250) / static_cast<float>(max)));
		window->draw(this->_sprite);
	}
	this->extraDisplay(pos, max, window);
}

void	Button::extraDisplay(unsigned int pos, unsigned int max, sf::RenderWindow *window)
{

}

void	Button::action(sf::Keyboard::Key key, sf::RenderWindow *window, bool *running)
{

}

void	Button::setHighlight(bool b)
{
	this->_highlight = b;
}

Button::~Button(void)
{
}
