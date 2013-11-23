#include "TextHandler.h"
#include <SFML/Graphics.hpp>

TextHandler::TextHandler()
{
	this->_assoc[sf::Keyboard::A] = 'a';
	this->_assoc[sf::Keyboard::B] = 'b';
	this->_assoc[sf::Keyboard::C] = 'c';
	this->_assoc[sf::Keyboard::D] = 'd';
	this->_assoc[sf::Keyboard::E] = 'e';
	this->_assoc[sf::Keyboard::F] = 'f';
	this->_assoc[sf::Keyboard::G] = 'g';
	this->_assoc[sf::Keyboard::H] = 'h';
	this->_assoc[sf::Keyboard::I] = 'i';
	this->_assoc[sf::Keyboard::J] = 'j';
	this->_assoc[sf::Keyboard::Q] = 'k';
	this->_assoc[sf::Keyboard::L] = 'l';
	this->_assoc[sf::Keyboard::M] = 'm';
	this->_assoc[sf::Keyboard::N] = 'n';
	this->_assoc[sf::Keyboard::O] = 'o';
	this->_assoc[sf::Keyboard::P] = 'p';
	this->_assoc[sf::Keyboard::Q] = 'q';
	this->_assoc[sf::Keyboard::R] = 'r';
	this->_assoc[sf::Keyboard::S] = 's';
	this->_assoc[sf::Keyboard::T] = 't';
	this->_assoc[sf::Keyboard::U] = 'u';
	this->_assoc[sf::Keyboard::V] = 'v';
	this->_assoc[sf::Keyboard::W] = 'w';
	this->_assoc[sf::Keyboard::X] = 'x';
	this->_assoc[sf::Keyboard::Y] = 'y';
	this->_assoc[sf::Keyboard::Z] = 'z';
	this->_assoc[sf::Keyboard::Period] = '.';
	this->_assoc[sf::Keyboard::Num0] = '0';
	this->_assoc[sf::Keyboard::Num1] = '1';
	this->_assoc[sf::Keyboard::Num2] = '2';
	this->_assoc[sf::Keyboard::Num3] = '3';
	this->_assoc[sf::Keyboard::Num4] = '4';
	this->_assoc[sf::Keyboard::Num5] = '5';
	this->_assoc[sf::Keyboard::Num6] = '6';
	this->_assoc[sf::Keyboard::Num7] = '7';
	this->_assoc[sf::Keyboard::Num8] = '8';
	this->_assoc[sf::Keyboard::Num9] = '9';
	this->_assoc[sf::Keyboard::Dash] = '-';
	this->_assoc[sf::Keyboard::Subtract] = '-';
	this->_assoc[sf::Keyboard::Space] = ' ';
}

TextHandler::TextHandler(TextHandler &ref)
{
	
}

void		TextHandler::keyPressed(sf::Keyboard::Key key, std::string *str)
{
	std::map<sf::Keyboard::Key, char>::iterator pair;

	if (key == sf::Keyboard::BackSpace)
		*str = str->substr(0, str->length() - 1);
	else
	{
		std::cout << "before find" << std::endl;
		pair = this->_assoc.find(key);
		*str += pair->second;
	}
}

TextHandler::~TextHandler(void)
{
}
