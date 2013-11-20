#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#pragma once
class SettingsParser
{
	std::string					_nick;
	std::string					_server;
	std::string					_fname;
public:
	SettingsParser(const std::string &fname);
	SettingsParser(SettingsParser &);
	void						parseFile(const std::string &);
	const std::string			&getNick(void) const;
	const std::string			&getServer(void) const;
	const std::string			&getFname(void) const;
	void						setNick(const std::string &);
	void						setServer(const std::string &);
	void						writeServer(const std::string &);
	~SettingsParser(void);
};

