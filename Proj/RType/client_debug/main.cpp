#include <sstream>
#include <iostream>
#include "Opcodes.h"
#include "SFML/Window.hpp"
#include "Debugger.h"
#include "DynLib.h"
#include <arpa/inet.h>

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
  return (0);
}
