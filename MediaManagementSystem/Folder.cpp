#include "pch.h"
#include <string>
#include "Collection.h"
#include "Song.h"
#include "Folder.h"

using std::string;

Folder::Folder(const string folderName) :
	m_sFolderName(folderName)
{}


Folder::~Folder()
{
}

// THis is only ever called after verifying that there is a folder with this folder name
/*Folder* Folder::GetFolder(const char* folderName)
{
	Folder* retVal = nullptr;
	Iterator<Folder> i_collectionFolders = this->m_collectionFolders.GetIterator();

	// Iterate over the collection of folders and check if the name of each existing folder matches the name of the new folder we are creating
	while (i_collectionFolders.HasNext())
	{
		retVal = &(i_collectionFolders.Next());
		if (retVal->GetFolderName() == folderName)
		{
			return retVal;
		}
	}


}*/

bool Folder::SongExists(const string title)
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