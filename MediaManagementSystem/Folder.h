#pragma once
class Folder
{
	Collection<Folder> m_collectionFolders;
	Collection<Song> m_collectionSongs;
	string m_sFolderName;
public:
	Folder(const string folderName);
	~Folder();

	string GetFolderName() { return m_sFolderName; }
	void SetFolderName(const string folderName) { m_sFolderName = folderName; }

	Collection<Folder> GetFolderCollection() { return m_collectionFolders; }
	Collection<Song> GetSongCollection() { return m_collectionSongs; }

};

