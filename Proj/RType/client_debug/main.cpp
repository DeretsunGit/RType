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
  return (0);
}
