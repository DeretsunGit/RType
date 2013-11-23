/* FILE API by gilmai_k */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#define SEPARATOR '\\'
#else
#include <unistd.h>
#include <cstring>
#define MAX_PATH 260
#define SEPARATOR '/'
#endif

class Path
{
private:
	std::string _absolute;
	std::vector<std::string> _directories;
	std::string _str_directories;
	std::string _filename;

	bool _isFile;
	bool _isDirectory;

public:
	Path() {
	_isFile = false;
	_isDirectory = false;
	}

	Path(const Path& other)
	{
		this->_absolute = other._absolute;
		this->_directories = other._directories;
		this->_filename = other._filename;
		this->_isDirectory = other._isDirectory;
		this->_isFile = other._isFile;
	}

	Path operator=(const Path& other)
	{
		this->set(other.getAbsolutePath());
		return (*this);
	};

	Path(const char* path)
	{
		this->_isDirectory = false;
		this->_isFile = false;
		set(std::string(path));
	}

	Path(const std::string& path)
	{
		this->_isDirectory = false;
		this->_isFile = false;
		set(path);
	}

	~Path()
	{}

	void set(const char* path)
	{
		set(std::string(path));
	}

#ifdef _WIN32
	void set(const std::string& path)
	{
		char absolute_path[MAX_PATH]; 
		char save_path[MAX_PATH];

		GetCurrentDirectory(MAX_PATH, save_path);

		if (SetCurrentDirectory(path.c_str()))
		{
			this->_isDirectory = true;
			GetCurrentDirectory(MAX_PATH, absolute_path);
		}			
		else if (SetCurrentDirectory(path.substr(0, path.find_last_of(SEPARATOR)).c_str()))
		{
			this->_isFile = true;
			this->_filename = path.substr(path.find_last_of(SEPARATOR) + 1);
			GetCurrentDirectory(MAX_PATH, absolute_path);	
		}
		else
			memcpy(absolute_path, path.c_str(), MAX_PATH);

		_absolute = std::string(absolute_path) + SEPARATOR + _filename;
		_str_directories = std::string(absolute_path) + SEPARATOR;
		std::stringstream ss(absolute_path);
		std::string tmp;

		while (std::getline(ss, tmp, SEPARATOR))
		{
			_directories.push_back(tmp);
		}
		SetCurrentDirectory(save_path);
	}
#else
	void set(const std::string& path)
	{
		char save_path[MAX_PATH];
		char absolute_path[MAX_PATH]; 

		getcwd(save_path, MAX_PATH);
		if (chdir(path.c_str()) != -1)
		{
			this->_isDirectory = true;
			getcwd(absolute_path, MAX_PATH);
		}			
		else if (chdir(path.substr(0, path.find_last_of(SEPARATOR)).c_str()) != -1)
		{
			this->_isFile = true;
			this->_filename = path.substr(path.find_last_of(SEPARATOR) + 1);
			getcwd(absolute_path, MAX_PATH);	
		}
		else
			memcpy(absolute_path, path.c_str(), MAX_PATH);

		_absolute = std::string(absolute_path) + SEPARATOR + _filename;
		_str_directories = std::string(absolute_path) + SEPARATOR;
		std::stringstream ss(absolute_path);
		std::string tmp;

		while (std::getline(ss, tmp, SEPARATOR))
		{
			_directories.push_back(tmp);
		}
		chdir(save_path);
	}
#endif
	const std::string& getAbsolutePath() const
	{
		return this->_absolute;
	}

	const std::string& getLastDirectory() const
	{
		return this->_directories.back();
	}

	const std::string& getFilename() const
	{
		return this->_filename;
	}

	const std::vector<std::string>& getDirectories() const
	{
		return this->_directories;
	}

	const std::string& getStrDirectories() const
	{
		return _str_directories;
	}

	bool isFilePath() const
	{
		return _isFile;
	}

	bool isDirectoryPath() const
	{
		return _isDirectory;
	}
};