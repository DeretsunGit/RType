#include  <iostream>
#include  <fstream>
#include  <ctime>
#include  "Debug.h"

const char*  Debug::_strLevel[Debug::emerg + 1] = {
						    "Debug",
						    "Information",
						    "Notification",
						    "Warning",
						    "Error",
						    "Critical",
						    "Alert",
						    "Emergency"
						  };

Debug::Debug()
  : Singleton<Debug>(), _level(err), _filename("log")
{}

Debug::~Debug()
{}

void		Debug::_log(const std::string& msg, Level lvl) const
{
  std::ofstream	file(this->_filename);
  char		buff[255];

  if (!file.is_open())
    std::cerr << "Wrong log file \"" << this->_filename << '"' << std::endl;
  else
  {
    time_t	t(time(NULL));
    struct tm*	lt(localtime(&t));

    if (lt)
    {
      strftime(buff, sizeof(buff), "%d/%m/%y at %H:%M:%S", lt);
      file << buff << ": " << this->_strLevel[lvl] << ": " << msg << std::endl;
    }
  }
  if (lvl >= this->_level)
  {}
//    std::cerr << this->_strLevel[lvl] << ": " << msg << std::endl;
}

void  Debug::_setLevel(Debug::Level lvl)
{
  this->_level = lvl;
}

Debug::Level  Debug::_getLevel() const
{
  return (this->_level);
}

void  Debug::_setLogFile(const std::string& filename)
{
  this->_filename = filename;
}

const std::string&  Debug::_getLogFile() const
{
  return (this->_filename);
}

void  Debug::log(const std::string& msg, Debug::Level lvl)
{
  Debug::getInstance()._log(msg, lvl);
}

void  Debug::setLevel(Debug::Level lvl)
{
  Debug::getInstance()._setLevel(lvl);
}

Debug::Level Debug::getLevel()
{
  return (Debug::getInstance()._getLevel());
}

void  Debug::setLogFile(const std::string& filename)
{
  Debug::getInstance()._setLogFile(filename);
}

const std::string& Debug::getLogFile()
{
  return (Debug::getInstance()._getLogFile());
}
