#pragma once
#include "Folder.h"


class MySongs
{

	Collection<Folder> m_collectionFolders;
	Collection<Song> m_collectionSongs;
	//Folder* GetFolder(const char* folderName);
	Song* SongExists(string title);
	Folder* FolderExists(const char* folderName);
	Folder* FolderExistsRecursive(const char* folderName);
	bool CreatedSubFolder(const char* subFolder, Folder* superFolder);
public:
	MySongs();
	~MySongs();

	Collection<Folder>& GetFolderCollection() { return m_collectionFolders; }
	Collection<Song>& GetSongCollection() { return m_collectionSongs; }


	bool AddFolder(const char* folderName, const char* superFolder="");
	bool AddSong(string title, const char* artist, const char* lyrics, const char* folder="");
	bool RemoveSong(string title, const char* folderName = "");
	bool RemoveFolder(const char* folderName, const char* superFolder="");
	bool MoveSong(string title, const char* destinationFolder, const char* sourceFolder="");
	bool Play(const char* title);
	bool PrintSongs();
	bool PrintFolderSongs(const char* folderName);
};

