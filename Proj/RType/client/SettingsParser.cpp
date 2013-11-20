#include "SettingsParser.h"

SettingsParser::SettingsParser(const std::string &fname)
{
  this->parseFile(fname);
}

SettingsParser::SettingsParser(SettingsParser &ref)
{
	this->_nick = ref.getNick();
	this->_server = ref.getServer();
}

void						SettingsParser::parseFile(const std::string &fname)
{
	std::string line;
	std::ifstream myfile (fname.c_str());
	this->_fname = fname;
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if (line.substr(0, line.find('=')) == "NICK")
				this->setNick(line.substr(line.find('=') + 1, line.size() - line.find('=') + 1));
			else if (line.substr(0, line.find('=')) == "SERVER")
				this->setServer(line.substr(line.find('=') + 1, line.size() - line.find('=') + 1));
			else if (line.substr(0, line.find('=')) == "PORT")
				this->setPort(line.substr(line.find('=') + 1, line.size() - line.find('=') + 1));
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file";
}

const std::string			&SettingsParser::getNick(void) const
{
	return this->_nick;
}

const std::string			&SettingsParser::getFname(void) const
{
	return this->_fname;
}

const std::string			&SettingsParser::getServer(void) const
{
	return this->_server;
}

const std::string			&SettingsParser::getPort(void) const
{
	return this->_port;
}

void						SettingsParser::setPort(const std::string &port)
{
	this->_port = port;
	this->writeConfig();
}

void						SettingsParser::setNick(const std::string &nick)
{
	this->_nick = nick;
	this->writeConfig();
}

void						SettingsParser::setServer(const std::string &server)
{
	this->_server = server;
	this->writeConfig();
}

void						SettingsParser::writeConfig()
{
	std::string line;
	std::ofstream myfile (this->_fname.c_str());
	
	myfile.clear();
	if (myfile.is_open())
	{
		myfile << "NICK=" << this->_nick << std::endl;
		myfile << "SERVER=" << this->_server << std::endl;
		myfile << "PORT=" << this->_port << std::endl;
	}
}

SettingsParser::~SettingsParser(void)
{
}
