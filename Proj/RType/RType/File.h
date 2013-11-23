/* FILE API by gilmai_k */

#pragma once

#include <ctime>
#include <map>
#include <string>
#include <fstream>
#include "IFile.h"
#include "Path.hpp"

class File : public IFile
{
private:
	std::fstream _fs;
	Path _path;
	char _md5[33];
	FileError _lastError;
	std::map<FileError, const char*> _errors;

	File operator=(const File&);
	bool _md5Encrypt();
	void _noFile();
	bool _update();

public:
	int append(const char* data, int size);
	/*int append(int start, const char* data, int size);
	bool erase(int start, int size);
	bool eraseFromStart(int size);
	bool eraseFromEnd(int size);
	bool replace(int start, const char* data, int size);*/
	int get(int start, char* data, int size);
	bool copy(const char* dest);
	
	const char* getFilename() const;
	const char* getPath() const;
	const char* getDirPath() const;
	const char* getMd5() const;

	bool set(const char* path);
	bool setFilename(const std::string& filename);
	bool operator==(const char* path) const;

	FileError getLastError() const;
	void printLastError() const;

	File();
	File(const File&);
	File(const char* path);
	~File();
};