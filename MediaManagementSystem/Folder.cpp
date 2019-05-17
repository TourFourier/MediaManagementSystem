#include "pch.h"
#include <string>
#include <iostream>
#include "Collection.h"
#include "Song.h"
#include "Folder.h"

using std::cout;
using std::endl;
using std::string;

Folder::Folder(const string folderName) :
	m_sFolderName(folderName)
{}


Folder::~Folder()
{
}


bool Folder::SongExists(string title)
{
	Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
	while (i_collectionSongs.HasNext())
	{
		if (i_collectionSongs.Next().GetTitle() == title)

		{
			return true;
		}
	}
	return false;
}

Folder* Folder::FolderExists(const char* folderName)
{
	Folder* retVal = nullptr;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		retVal = &(i_collectionFolders.Next());
		if (retVal->GetFolderName() == folderName)
		{
			return retVal;
		}
		retVal = nullptr;
	}
	return retVal;
}

Folder* Folder::FolderExistsRecursive(const char* folderName)
{
	Folder* retVal = nullptr;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		retVal = &(i_collectionFolders.Next());
		if (retVal->GetFolderName() == folderName)
		{
			return retVal;
		}

		retVal = retVal->FolderExistsRecursive(folderName);
		if (retVal != nullptr)
		{
			return retVal;
		}
		retVal = nullptr;
	}
	return retVal;
}

bool Folder::FolderRemoveRecursive(const char* folderName)
{
	bool flag;
	Folder* retVal = nullptr;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		retVal = &(i_collectionFolders.Next());
		if (retVal->GetFolderName() == folderName)
		{
			i_collectionFolders.Remove();
			return true;
		}
		flag = retVal->FolderRemoveRecursive(folderName);
		if (flag)
		{
			return true;
		}
	}
	return false;
}

void Folder::PrintSongCollection(const char* artist)
{
	Song currentSong;
	Iterator<Song> i_collectionSongs = this->m_collectionSongs.GetIterator();
	while (i_collectionSongs.HasNext())
	{
		if (artist == "")// All songs
		{
			i_collectionSongs.Next().PrintSongTitle();
			cout << endl;
		}
		else// Songs of a particular artist
		{
			currentSong = i_collectionSongs.Next();
			if (currentSong.GetArtist() == artist)
			{
				currentSong.PrintSongTitle();
				cout << endl;
			}
		}
	}
}

int Folder::SongTitleRec(string* titles, int index)
{
	Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
	while (i_collectionSongs.HasNext())
	{
		titles[index] = i_collectionSongs.Next().GetTitle();
		index++;
	}
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		index = i_collectionFolders.Next().SongTitleRec(titles, index);
	}
	return index;
}

int Folder::SongTitleArtistRec(string* titles, const char* artist, int index)
{
	Song currentSong;
	Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
	while (i_collectionSongs.HasNext())
	{
		currentSong = i_collectionSongs.Next();
		if (currentSong.GetArtist() == artist)
		{
			titles[index] = currentSong.GetTitle();
			index++;
		}
	}
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		index = i_collectionFolders.Next().SongTitleArtistRec(titles, artist, index);
	}
	return index;
}

	
	void Folder::CreateSubFolder(const char* folderName)
	{
		this->m_collectionFolders.Add(*(new Folder(folderName)));
	}

	bool Folder::operator >(const Folder& f)
	{
		if (m_sFolderName > f.m_sFolderName)
		{
			return true;
		}
		return false;
	}