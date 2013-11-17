#include <sstream>
#include <iostream>
#include "Hash.h"
#include "Opcodes.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Debugger.h"
#include "DynLib.h"

int main(int ac, char** av)
{
  if (ac == 3)
  {
    try
    {
      Debugger  d(av[1], stringTo<unsigned short>(av[2]));

      d.start();
    }
    catch (const std::exception& e)
    {
      std::cerr << "EXCEPTION: " << e.what() << std::endl;
      std::cin.get();
    }
  }
  else if (ac == 2)
  {
    std::cout << Hash::MD5(av[1]) << std::endl;
  }
  else
  {
    sf::RenderWindow  w(sf::VideoMode(800, 600), "Test");
    sf::Texture t;
    sf::Sprite	s;
    sf::Event	e;

    t.loadFromFile("assets/ship.gif");
    s.setTexture(t);
    while (w.isOpen())
    {
      w.clear();
      w.draw(s);
      w.display();
      w.waitEvent(e);
      if (e.type == sf::Event::Closed)
	w.close();
    }
  }
  return (0);
}
