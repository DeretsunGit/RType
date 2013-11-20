#include <string>
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma once


class TextHandler
{
	std::map<sf::Keyboard::Key, char>	_assoc;
public:
	TextHandler();
	void		keyPressed(sf::Keyboard::Key, std::string *);
	TextHandler(TextHandler &);
	~TextHandler(void);
};
