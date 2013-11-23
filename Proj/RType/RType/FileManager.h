/* FILE API by gilmai_k */

#pragma once

#include <list>
#include "File.h"

class FileManager
{
private:

	File _nofile;
	bool _loaded;
	FileManager(const FileManager&);
	FileManager operator=(const FileManager&);
	std::list<File> _files;

public:

	bool addFile(const char* path);
	bool removeFileByFilename(const char* filename);
	bool removeFileByPath(const char* path);

	bool loadDirectory(const char* dirPath);
	bool loadList(const std::list<File>& files);
	bool loadConfigFile(const char* configFilePath);

	std::list<File>& getFiles();
	File& getFileByFilename(const char* filename);
	File& getFileByPath(const char* path);

	void releaseRessources();
	FileManager();
	~FileManager();
};