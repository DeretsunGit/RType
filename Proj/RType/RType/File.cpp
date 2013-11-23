/* FILE API by gilmai_k */

#pragma once

#include <cstring>
#include <cstdio>
#include <iostream>
#include "File.h"

File::File(const char* path)
{
	_errors[NONE] = "None";
	_errors[ERROR_NO_FILE] = "The File cannot be instanciated. Please verify your parameters";
	_errors[ERROR_ALLOCATION] = "File class has failed to allocate memory";
	_errors[ERROR_MD5] = "Md5 encryptage has failed.";
	_errors[ERROR_CREATE_COPY] = "Cannot create new file for copy.";
	_lastError = NONE;
	if (path == 0)
		_noFile();
	else
	{
		_path.set(path);
		if (!_path.isFilePath())
		{
			_noFile();
			return ;
		}
		if (!_update())
			return ;
		else
			_md5Encrypt();
	}
}

File::File()
{
	_errors[NONE] = "None";
	_errors[ERROR_NO_FILE] = "The File cannot be instanciated. Please verify your parameters";
	_errors[ERROR_ALLOCATION] = "File class has failed to allocate memory";
	_errors[ERROR_MD5] = "Md5 encryptage has failed.";
	_errors[ERROR_CREATE_COPY] = "Cannot create new file for copy.";
	_lastError = NONE;
}

File::File(const File& other)
{
	_errors[NONE] = "None";
	_errors[ERROR_NO_FILE] = "The File cannot be instanciated. Please verify your parameters";
	_errors[ERROR_ALLOCATION] = "File class has failed to allocate memory";
	_errors[ERROR_MD5] = "Md5 encryptage has failed.";
	_errors[ERROR_CREATE_COPY] = "Cannot create new file for copy.";
	_lastError = NONE;
	if (other.getPath() == 0)
		_noFile();
	else
	{
		_path.set(other.getPath());
		if (!_path.isFilePath())
		{
			_noFile();
			return ;
		}
		if (!_update())
			return ;
		else
			_md5Encrypt();
	}
}

File File::operator=(const File& other)
{
	return (other);
}

File::~File()
{}

bool File::_md5Encrypt()
{
	//todo
	return true;
}

void File::_noFile()
{
	_lastError = ERROR_NO_FILE;
	_path.set(".");
}

bool File::_update()
{
	_lastError = NONE;

	_fs.open(_path.getAbsolutePath().c_str(), std::fstream::out | std::fstream::app);
	if (!_fs)
	{
		_noFile();
		_fs.close();
		return false;
	}
	if (!_md5Encrypt())
	{
		_fs.close();
		return false;
	}
	_fs.close();
	return true;
}

int File::append(const char* data, int size)
{
	if (strlen(data) < static_cast<size_t>(size))
		size = static_cast<int>(strlen(data));

	_fs.open(_path.getAbsolutePath().c_str(), std::fstream::out | std::fstream::app | std::fstream::binary);
	if (!_fs)
	{
		_noFile();
		return (-1);
	}
	_fs.write(data, size);
	_fs.close();
	return size;
}

int File::get(int start, char* data, int size)
{
	if (size <= 0)
		return (0);

	_fs.open(_path.getAbsolutePath().c_str(), std::fstream::in | std::fstream::binary);
	if (!_fs)
	{
		_noFile();
		return (-1);
	}
	_fs.read(data, size);
	_fs.close();
	return (static_cast<int>(strlen(data)));
}

bool File::copy(const char* dest)
{
	Path path(dest);
	std::fstream new_fs;
	char buff[1025];
	int offset = 0, rsize = 0;
	memset(buff, 0, 1025);

	if (path.isFilePath())
	{
		new_fs.open(path.getAbsolutePath().c_str(), std::fstream::out | std::fstream::trunc);
		if (!new_fs)
		{
			_lastError = ERROR_CREATE_COPY;
			return false;
		}
	}
	else if (path.isDirectoryPath())
	{
		new_fs.open((path.getAbsolutePath() + std::string("_copy")).c_str(), std::fstream::out | std::fstream::trunc);
		if (!new_fs)
		{
			_lastError = ERROR_CREATE_COPY;
			return false;
		}
	}
	_fs.open(_path.getAbsolutePath().c_str(), std::fstream::in);
	if (!_fs)
	{
		_noFile();
		return false;
	}
	_fs.read(buff, 1024);
	rsize = static_cast<int>(strlen(buff));
	while (rsize > 0)
	{
		new_fs.write(buff, rsize);
		offset += rsize;
		memset(buff, 0, 1024);
		_fs.read(buff, 1024);
		rsize = static_cast<int>(strlen(buff));
	}
	_fs.close();
	new_fs.close();
	return true;
}

const char* File::getFilename() const
{
	return _path.getFilename().c_str();
}

const char* File::getPath() const
{
	return _path.getAbsolutePath().c_str();
}

const char* File::getDirPath() const
{
	return _path.getStrDirectories().c_str();
}

const char* File::getMd5() const
{
	return _md5;
}

bool File::set(const char* path)
{
	if (path == 0)
	{
		_noFile();
		return false;
	}
	_path.set(path);
	if (!_path.isFilePath())
	{
		_noFile();
		return false;
	}
	if (!_update())
		return false;
	else
		_md5Encrypt();
	_lastError = NONE;
	return true;
}

bool File::setFilename(const std::string& filename)
{
	if (rename(_path.getAbsolutePath().c_str(), (_path.getStrDirectories() + std::string(filename)).c_str()))
		return false;

	_path.set(_path.getStrDirectories() + std::string(filename));
	return true;
}

bool File::operator==(const char* path) const
{
	Path c_path(path);

	if (_path.getAbsolutePath() == c_path.getAbsolutePath())
		return true;
	return false;
}

FileError File::getLastError() const
{
	return _lastError;
}

void File::printLastError() const
{
	if (_errors.find(_lastError) != _errors.end())
		std::cerr << _errors.at(_lastError) << std::endl;
	else
		std::cerr << "cannot find current error" << std::endl;
}

