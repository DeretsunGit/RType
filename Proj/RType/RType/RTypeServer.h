#pragma once

#include <ostream>

class RTypeServer
{
	int	_port;
	int	_maxRoom;
	// std::ofstream _blFile;

public:
	RTypeServer(int, int, std::string);
	~RTypeServer();

	bool	start();
	bool	loadDynEnnemy(std::string);
};