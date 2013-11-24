#include "Script.h"
#include "Randomization.hpp"
template class Randomization<char>;

Script::Script()
{
	this->_patternFile = new std::ifstream();
	//this->getPattern();
	this->_rand = new Randomization<char>;
	this->_mapSize = 256;
}

Script::~Script(void)
{
	//delete this->_scriptFile;
	//delete this->_patternFile;
}

void	Script::LoadMap(std::string	*map)
{
	if (!this->_isRandom && !map->empty())
		{
			std::cout << "Reading From File" << std::endl;
			this->setScriptFile(map);
			this->interpretMap();
		}
	else
		this->makeRandomScript();
}

void	Script::interpretMap()
{
// on recup la map et on remplit les structures
}

void	Script::makeRandomScript()
{
	std::cout << "Making random script" << std::endl;
	this->setRandomMap();
}

void	Script::setRandomMap()
{
	char		rand;
	short int	topLen = 0;
	short int	botLen = 0;

	Randomization<char> my_rand;
	while (topLen < this->_mapSize || botLen < this->_mapSize)
	{
		rand = this->_rand->tRand(1, static_cast<char>(this->_patternList.size()));
		if (this->_patternList[rand]._isTop == true)
		{
			if((topLen += this->_patternList[rand]._len) <= this->_mapSize)
				this->_map._topMap.append(this->_patternList[rand]._elemHeight);
		}
		else
		{
			if((botLen += this->_patternList[rand]._len) <= this->_mapSize)
				this->_map._botMap.append(this->_patternList[rand]._elemHeight);
		}
	}
}

bool	Script::getPattern()
{
	size_t			len = 0;
	size_t			pos = 0;
	size_t			pos2 = 0;
	std::string		line;
	std::string		temp;
	t_pattern		newPattern;

	this->_patternFile->open(PATTERNFILE);
	if(this->_patternFile->fail())
	{
	  std::cout << "Script " << PATTERNFILE <<  ": No such file or directory" << std::endl;
	  return (false);
	}
	while (std::getline(*(this->_patternFile), line))
	{
		if ((*this->_patternFile).eof() || line.find("/") == 1)
			std::cout << "END :" <<line << std::endl;
		else
		{
			pos = 0;
			pos2 = 0;
			len = 0;
			if ((pos2 = line.find(":", pos)) != std::string::npos)
			{
				len = pos2 - pos;
				temp = line.substr(pos, len);
				pos = pos2 + 1;
				if ((newPattern._id = strTo<int>(temp)) < 100)
					newPattern._isTop = true;
				else
					newPattern._isTop = false;
			}
			else
				std::cout << "Pattern file corrupted." << std::endl;
			if ((pos2 = line.find(":", pos)) != std::string::npos)
			{
				len = pos2 - pos;
				temp = line.substr(pos, len);
				pos = pos2 + 1;
				newPattern._len = strTo<int>(temp);
			}
			else
				std::cout << "Pattern file corrupted." << std::endl;
			temp = line.substr(pos);
			newPattern._elemHeight.append(temp);
			this->_patternList.push_back(newPattern);
		}
	}
	if (this->_patternList.size() == 0)
	{
		std::cout << "Patternfile is empty" << std::endl;
		return (false);
	}
	else
		std::cout << "Pattern list OK !" << std::endl;
	return (true);
}

bool		Script::getRandom() const
{
	return (this->_isRandom);
}

void		Script::setScriptFile(std::string *newfile)
{
  this->_scriptFile = new std::ifstream(newfile->c_str());
}

void		Script::setPatternList(std::vector<t_pattern> newpattern)
{
	this->_patternList = newpattern;
}

void		Script::setRandom(bool rand)
{
	this->_isRandom = rand;
}

std::vector<t_pattern>	Script::getPatternList()
{
	return this->_patternList;
}

t_scriptMap	*Script::getMap()
{
	return (&this->_map);
}
