#include "Script.h"

Script::Script()
{
	this->_patternFile = new std::ifstream(PATTERNFILE);
	this->getPattern();
}

Script::~Script(void)
{
	delete this->_scriptFile;
	delete this->_patternFile;
}

void	Script::LoadMap(std::string	*map)
{
	if (!this->_isRandom && !map->empty())
		{
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
	this->setRandomMap();
}

void	Script::setRandomMap()
{
	char rand;
	short int topLen = 0;
	short int botLen = 0;

	std::default_random_engine generator;
	std::uniform_int_distribution<char> distribution(1, this->_patternList.size());
	while (topLen < this->_mapSize || botLen < this->_mapSize) // top
	{
		rand = distribution(generator);
		if (this->_patternList[rand]._isTop = true)
		{
			if(topLen += this->_patternList[rand]._len <= this->_mapSize)
				this->_map._topMap.append(&rand);
		}
		else
		{
			if(botLen += this->_patternList[rand]._len <= this->_mapSize)
				this->_map._topMap.append(&rand);
		}
		//on random un pattern, et len += la longueur du pattern.
	}
}

void	Script::getPattern()
{
	int				pos = 0;
	int				pos2 = 0;
	std::string		line;
	std::string		temp;
	t_pattern		newPattern;

	if (!this->_patternFile)
	{
	  std::cout << "Script " << this->_patternFile <<  ": No such file or directory" << std::endl;
	}
	while (std::getline(*(this->_patternFile), line))
	{
		if ((*this->_patternFile).eof() || line.find("/") == 0)
		{
			std::cout << line;

	// on lit dans le fichier, get line, on cut sur les ':', 1er = no patern, 2eme = longueur, 3eme on cut sur les ',', et on get la hauteur
	// on met tout dans une liste
		}
		else
		{
			std::cout << line << std::endl;			
			if (pos2 = line.find(":", pos) != std::string::npos)
			{
				temp = line.substr(pos, pos2);
				(newPattern._id = std::stoi(temp) >= 100) ? newPattern._isTop = true : newPattern._isTop = false;
				pos = pos2 + 1;
			}
			else
				std::cout << "Pattern file corrupted." << std::endl;
			if (pos2 = line.find(":", pos) != std::string::npos)
			{
				temp = line.substr(pos, pos2);
				newPattern._len = std::stoi(temp);
				pos = pos2 + 1;
			}
			else
				std::cout << "Pattern file corrupted." << std::endl;			
			while (pos2 = line.find(",", pos) != std::string::npos)
			{
				temp = line.substr(pos, pos2);
				newPattern._elemHeight.push_back(std::stoi(temp));
				pos = pos2 + 1;
			}
		}
		this->_patternList.push_back(newPattern);
	}
}

bool		Script::getRandom()
{
	return (this->_isRandom);
}

void		Script::setScriptFile(std::string *newfile)
{
	this->_scriptFile = new std::ifstream(*newfile);
}

void		Script::setRandom(bool rand)
{
	this->_isRandom = rand;
}