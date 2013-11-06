//
// main.cpp for RType in /home/edmond_j//rendu/B5/Rtype/r-type-riva_p/Proj/RType
//
// Made by julien edmond
// Login   <edmond_j@epitech.net>
//
// Started on  Thu Oct 24 14:57:20 2013 julien edmond
// Last update Wed Nov  6 02:07:22 2013 maxime miramond
//

#include "RTypeServer.h"

int main()
{
  RTypeServer serv(1234, 20, "");

  return (serv.start());
}