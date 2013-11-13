#include "CreditsButton.h"


CreditsButton::CreditsButton(SpriteManager *sprmgr)
{
	this->setSprite(sprmgr->getSpritebyId(MENU_CRED));
	this->setSpriteOn(sprmgr->getSpritebyId(MENU_CRED_ON));
	this->_sprite = sprmgr->getSpritebyId(CREDITS);
	this->_sprite.setPosition(static_cast<float>(SIZEX / 2) - this->_sprite.getTextureRect().width / 2,
			static_cast<float>(SIZEY / 2) - this->_sprite.getTextureRect().height / 2);
}

void	CreditsButton::action(sf::Keyboard::Key, sf::RenderWindow *window)
{
	bool			running = true;

	while (running)
	{
		sf::Event event;
        while (window->pollEvent(event))
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				running = false;
		window->clear();
		window->draw(this->_sprite);
		window->display();
	}
}

CreditsButton::~CreditsButton(void)
{
}
