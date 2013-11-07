#include "SFML/Window.hpp"

int main()
{
  sf::Window  window(sf::VideoMode(800, 600), "My window");
  sf::Event   e;

  while (window.isOpen())
  {
    while (window.waitEvent(e))
      if (e.type == sf::Event::Closed)
	window.close();
  }
  return (0);
}