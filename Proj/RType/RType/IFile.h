/* FILE API by gilmai_k */

#pragma once

#include <ctime>

enum FileError {NONE, ERROR_NO_FILE, ERROR_ALLOCATION, ERROR_MD5, ERROR_CREATE_COPY};

class IFile
{
public:
	virtual int append(const char* data, int size) = 0; // ajoute <size> octect(s) de <data> � la fin du fichier.
	/*virtual int append(int start, const char* data, int size) = 0; // ajoute <size> octet(s) de <data> � partir de <start> dans le fichier.
	virtual bool erase(int start, int size) = 0; // supprime <size> octet(s) � partir de <start> dans le fichier.
	virtual bool eraseFromStart(int size) = 0; // supprime <size> octect(s) � partir du d�but du fichier.
	virtual bool eraseFromEnd(int size) = 0; // supprime <size> octet(s) depuis la fin du fichier.
	virtual bool replace(int start, const char* data, int size) = 0; // remplace <size> octet(s) � partir de <start> dans le fichier.
	*/virtual int get(int start, char* data, int size) = 0; // lit <size> octet(s) dans le buffer <data> depuis <start> dans le fichier. <data> doit �tre d'une taille sup�rieur ou �gale � <size>
	virtual bool copy(const char* dest) = 0; // copie le fichier actuel dans le fichier point� par le chemin <dest>. Si <dest> est un dossier, le fichier est copi� � l'interieur avec "_copy" �crit � la suite du nom.
	
	virtual const char* getFilename() const = 0; // retourne le nom du fichier.
	virtual const char* getPath() const = 0; // retourne le chemin complet du fichier.
	virtual const char* getDirPath() const = 0; // retourne le chemin vers le dossier contenant le fichier.
	virtual const char* getMd5() const = 0; // retourne le hash md5 du fichier.

	virtual bool setFilename(const std::string& filename) = 0; // change le nom du fichier par <filename>.
	virtual bool operator==(const char* path) const = 0; // compare une instance de classe File avec un chemin et retourne vrai si les chemins complets correspondent.

	virtual FileError getLastError() const = 0; // retourne la derni�re erreur
	virtual void printLastError() const = 0; // �crit sur la sortie d'erreur les raisons de la derni�re erreur.


	virtual ~IFile() {};
};