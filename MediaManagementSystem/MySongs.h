#pragma once
class MySongs
{

	Collection<Folder> m_collectionFolders;
	Collection<Song> m_collectionSongs;
	Folder& GetFolder(const char* folderName);
	bool FolderExists(const char* folderName);
	bool CreatedSubFolder(const char* folderName, const char* superFolder);
public:
	MySongs();
	~MySongs();

	Collection<Folder> GetFolderCollection() { return m_collectionFolders; }
	Collection<Song> GetSongCollection() { return m_collectionSongs; }


	bool AddFolder(const char* folderName, const char* superFolder);
	bool AddSong(const char* title, const char* artist, const char* lyrics);
	bool RemoveSong(const char* title);
	bool RemoveFolder(const char* folderName);
	bool MoveSong(const char* tiltle, const char* destinationFolderName);
	bool Play(const char* title);
	bool PrintSongs();
	bool PrintFolderSongs(const char* folderName);
};

