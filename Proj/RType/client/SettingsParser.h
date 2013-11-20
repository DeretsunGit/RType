#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#pragma once
class SettingsParser
{
	std::string					_nick;
	std::string					_server;
	std::string					_port;
	std::string					_fname;
public:
	SettingsParser(const std::string &fname);
	SettingsParser(SettingsParser &);
	void						parseFile(const std::string &);
	const std::string			&getNick(void) const;
	const std::string			&getServer(void) const;
	const std::string			&getFname(void) const;
	const std::string			&getPort(void) const;
	void						setNick(const std::string &);
	void						setPort(const std::string &);
	void						setServer(const std::string &);
	void						writeConfig();
	~SettingsParser(void);
};

