#pragma once


class Folder
{
	Collection<Folder> m_collectionFolders;
	Collection<Song> m_collectionSongs;
	string m_sFolderName;
public:
	Folder(const string folderName="");
	~Folder();

	string GetFolderName() { return m_sFolderName; }
	void SetFolderName(const string folderName) { m_sFolderName = folderName; }

	Collection<Folder>& GetFolderCollection() { return m_collectionFolders; }
	Collection<Song>& GetSongCollection() { return m_collectionSongs; }

	//Folder* GetFolder(const char* folderName);
	Song* SongExists(const string title);
	Folder* FolderExists(const char* folderName);
	Folder* FolderExistsRecursive(const char* folderName);
	bool FolderRemoveRecursive(const char* folderName);
	void CreateSubFolder(const char* folderName);
	void PrintSongCollection(const char* artist);
	int SongTitleRec(string* titles, int index);
	int SongTitleArtistRec(string* titles, const char* artist, int index = 0);
	bool operator>(const Folder& f);
};

