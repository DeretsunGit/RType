#include "Script.h"
#include "Randomisation.cpp"
template class Randomisation<char>;

Script::Script()
{
	this->_patternFile = new std::ifstream();
	this->getPattern();
	std::cout << "Pattern list Retrived !" << std::endl;
	this->_rand = new Randomisation<char>;
	this->_mapSize = 256;
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

	Randomisation<char> my_rand;
	while (topLen < this->_mapSize || botLen < this->_mapSize) // top
	{
//		std::cout << topLen << "<->" << botLen << std::endl;
		rand = this->_rand->tRand(1, this->_patternList.size());
		//rand = distribution(generator);
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

void	Script::getPattern()
{
	int				len = 0;
	int				pos = 0;
	int				pos2 = 0;
	std::string		line;
	std::string		temp;
	t_pattern		newPattern;

	this->_patternFile->open(PATTERNFILE);
	if(this->_patternFile->fail())
	{
	  std::cout << "Script " << PATTERNFILE <<  ": No such file or directory" << std::endl;
	  return;
	}
	while (std::getline(*(this->_patternFile), line))
	{
		if ((*this->_patternFile).eof() || line.find("/") == 1)
		{
			std::cout << "END :" <<line << std::endl;

	// on lit dans le fichier, get line, on cut sur les ':', 1er = no patern, 2eme = longueur, 3eme on cut sur les ',', et on get la hauteur
	// on met tout dans une liste
		}
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
				{
					newPattern._isTop = true;
				}
				else
				{
					newPattern._isTop = false;
				}
				//((newPattern._id = strTo<int>(temp)) >= 100) ? newPattern._isTop = true : newPattern._isTop = false;
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
	}
}

bool		Script::getRandom()
{
	return (this->_isRandom);
}

void		Script::setScriptFile(std::string *newfile)
{
  this->_scriptFile = new std::ifstream(newfile->c_str());
}

void		Script::setRandom(bool rand)
{
	this->_isRandom = rand;
}

t_scriptMap	*Script::getMap()
{
	return (&this->_map);
}
