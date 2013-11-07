#include <sstream>
#include "SFML/Window.hpp"
#include "Debugger.h"

template<typename T>
T		      stringTo(const std::string& str)
{
  std::istringstream  stream(str);
  T		      sent;

  stream >> sent;
  return (sent);
}

int main(int ac, char** av)
{
/*  sf::Window  window(sf::VideoMode(800, 600), "My window");
  sf::Event   e;

  while (window.isOpen())
  {
    while (window.waitEvent(e))
      if (e.type == sf::Event::Closed)
	window.close();
  }*/
  if (ac == 3)
  {
    Debugger  d(av[1], stringTo<unsigned short>(av[2]));

    d.start();
  }
  return (0);
}