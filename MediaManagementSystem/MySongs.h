#pragma once
#include "Folder.h"


class MySongs
{
	int m_nTotalNumOfSongs;// Using this for the Print (all) songs method to know size of holding array; 
	//it might be a bigger size then actual because i am not subtracting when i delete a folder (would need to recursively count all subfolder song collections but didnt write it yet)
	Collection<Folder> m_collectionFolders;
	Collection<Song> m_collectionSongs;
	//Folder* GetFolder(const char* folderName);
	Song* SongExists(string title);
	Folder* FolderExists(const char* folderName);
	Folder* FolderExistsRecursive(const char* folderName);
	bool CreatedSubFolder(const char* subFolder, Folder* superFolder);
	// Returns the index following the last element
	int SongTitleRec(string* titles, int index = 0);
	//TODO: write Size() method using recursion
	void swap(string *xp, string *yp);
	void  bubbleSortCaseIns(string arr[], int n);
	int SongTitleArtistRec(string* titles, const char* artist, int index = 0);
	//Collection<Folder>* GetSuperFolderRec(const char* folderName);
	bool FolderRemoveRecursive(const char* folderName);


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
	bool Play(const char* title, const char* folderName="");
	bool PrintSongs(const char* artist="");
	bool PrintFolderSongs(const char* folderName="", const char* artist="");
};

