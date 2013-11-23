/* FILE API by gilmai_k */

#include <algorithm>
#include <cstring>
#include "FileManager.h"
#ifndef _WIN32
#include <sys/types.h>
#include <dirent.h>
#endif

FileManager::FileManager()
	: _nofile(NULL)
{}

FileManager::~FileManager()
{}

FileManager::FileManager(const FileManager& other)
	: _nofile(NULL)
{
	(void)other;
}

FileManager FileManager::operator=(const FileManager& other)
{
	return (other);
}

std::list<File>& FileManager::getFiles()
{
	return _files;
}

File& FileManager::getFileByFilename(const char* filename)
{
	std::list<File>::iterator ite = _files.begin();

	while (ite != _files.end())
	{
		if (std::string(ite->getFilename()) == std::string(filename))
			return (*ite);
		++ite;
	}
	return _nofile;
}

File& FileManager::getFileByPath(const char* path)
{
	std::list<File>::iterator ite;

	ite = std::find(_files.begin(), _files.end(), path);
	if (ite != _files.end())
		return (*ite);
	return _nofile;
}

bool FileManager::addFile(const char* path)
{
	_files.push_back(path);
	if (_files.back().getLastError() != NONE)
	{
		_files.back().printLastError();
		_files.pop_back();
		return false;
	}
	return true;
}

bool FileManager::removeFileByFilename(const char* filename)
{
	std::list<File>::const_iterator ite = _files.begin();

	while (ite != _files.end())
	{
		if (std::string(ite->getFilename()) == std::string(filename))
		{
			_files.erase(ite);
			return true;
		}
		++ite;
	}
	return false;
}

bool FileManager::removeFileByPath(const char* path)
{
	std::list<File>::const_iterator ite;

	ite = std::find(_files.begin(), _files.end(), path);
	if (ite != _files.end())
	{
		_files.erase(ite);
		return true;
	}
	return false;
}

#ifdef _WIN32
bool FileManager::loadDirectory(const char* dirPath)
{
	char save_path[MAX_PATH];
	char current_dir[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, save_path);
	if (!SetCurrentDirectory(dirPath))
		return false;
	GetCurrentDirectory(MAX_PATH, current_dir);
	HANDLE handle;
	WIN32_FIND_DATA data;
	if ((handle = FindFirstFile("*.*", &data)) == INVALID_HANDLE_VALUE)
		return false;
	if (data.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
	{
		if (std::string(data.cFileName) != std::string(".") && std::string(data.cFileName) != std::string(".."))
			if (!loadDirectory(data.cFileName))
			{
				FindClose(handle);	
				return false;
			}
	}
	else if (!addFile((std::string(current_dir) + SEPARATOR +  std::string(data.cFileName)).c_str()))
	{
		FindClose(handle);
		return false;
	}
	while (FindNextFile(handle, &data))
	{
		if (data.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		{
			if (std::string(data.cFileName) != std::string(".") && std::string(data.cFileName) != std::string(".."))
				if (!loadDirectory(data.cFileName))
				{
					FindClose(handle);
					return false;
				}
		}
		else if (!addFile((std::string(current_dir) + SEPARATOR +  std::string(data.cFileName)).c_str()))
		{
				FindClose(handle);
				return false;
		}
	}
	_loaded = true;
	FindClose(handle);
	SetCurrentDirectory(save_path);
	return true;
}
#else
bool Filemanager::loadDirectory(const char* dirPath)
{
	DIR *dir;
	struct dirent *entry;
	char save_dir[MAX_PATH];
	char current_dir[MAX_PATH];

	getcwd(save_dir, MAX_PATH);
	if (chdir(dirPath) == -1)
		return false;
	getcwd(current_dir, MAX_PATH);
	if ((dir = opendir(current_dir)) == NULL)
		return false;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (std::string(entry->d_name) != std::string(".")
				&& std::string(entry->d_name) != std::string("..")) 
				if (!loadDirectory(entry->d_name))
				{
					closedir(dir);
					return false;
				}
		}
		else if (!addFile((std::string(current_dir) + SEPARATOR +  std::string(entry->d_name)).c_str()))
		{
			closedir(dir);
			return false;
		}
	}
	_loaded = true;
	closedir(dir);
	chdir(save_dir);
	return true;
}
#endif

bool FileManager::loadList(const std::list<File>& files)
{
	std::list<File>::const_iterator ite = files.begin();

	while (ite != files.end())
	{
		_files.push_back(*ite);
	}
	_loaded = true;
	return true;
}

bool FileManager::loadConfigFile(const char* configFilePath)
{
	(void)configFilePath;
	_loaded = true;
	return true;
}

void FileManager::releaseRessources()
{
	if (_loaded)
	{
		while (_files.size())
			_files.pop_back();
	}
	_loaded = false;
}