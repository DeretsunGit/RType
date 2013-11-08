#include <sstream>
#include <iostream>
#include "Opcodes.h"
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
  std::cout << sizeof(RTypeOpcodes) << std::endl;
  if (ac == 3)
  {
    try
    {
      Debugger  d(av[1], stringTo<unsigned short>(av[2]));

      d.start();
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cin.get();
  return (0);
}