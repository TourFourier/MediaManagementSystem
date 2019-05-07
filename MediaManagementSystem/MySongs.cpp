#include "pch.h"
#include <algorithm>
#include <string> 
#include "TNode.h"
#include "Iterator.h"
#include "Collection.h"
#include "Song.h"
#include "Folder.h"
#include "MySongs.h"

using std::string;
using std::transform;

MySongs::MySongs()
{
}


MySongs::~MySongs()
{
}



/*Folder* MySongs::GetFolder(const char* folderName)
{
	Folder* retVal;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();

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

Folder* MySongs::FolderExists(const char* folderName)
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

// Returns nullptr if folder doesn't exist otherwise returns a pointer to the folder obj.
Folder* MySongs::FolderExistsRecursive(const char* folderName)
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

bool MySongs::CreatedSubFolder(const char* subFolder, Folder* superFolder)
{
	// Check if outer folder does not contain an inner folder with the same name as new folder
	if (!(superFolder->FolderExists(subFolder)))
	{
		superFolder->GetFolderCollection().Add(*(new Folder(subFolder)));
		return true;
	}
	return false;
}

// Returns pointer to null if song doesn't exist, otherwise returns a pointer to the song obj.
Song* MySongs::SongExists(string title)
{
	Song* retVal = nullptr;
	Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
	while (i_collectionSongs.HasNext())
	{
		retVal = &(i_collectionSongs.Next());
		if (retVal->GetTitle() == title)
		{
			return retVal;
		}
		retVal = nullptr;
	}
	return retVal;
}



bool MySongs::AddFolder(const char* folderName, const char* superFolder)
{
	//returns false if 1)name of file already exists both in current folder and sub 
	//2) name of folder-to-create-in doesnt exist

	Folder* existingFolder;
	// ie. Not placing new folder in an existing directory
	if (superFolder == "")
	{
		// no directory exist with this name therefor create directory
		if ((existingFolder = this->FolderExists(folderName)) == nullptr)
		{
			m_collectionFolders.Add(*(new Folder(folderName)));
			return true;
		}
		// A directory exists with this name, therefor if directory doesn't contain an identical subfolder, create new folder in that directory, else return false
		else
		{
			return false;// (CreatedSubFolder(folderName, existingFolder));
		}
	}
	// Placing new folder in an existing directory
	else
	{
		// Check if the directory exists before trying to create a folder in it
		if ((existingFolder = this->FolderExistsRecursive(superFolder)) != nullptr)
		{
			// Check if directory contains a folder with given name
			if (existingFolder->FolderExists(folderName) != nullptr)// subfolder with given name exists
			{
				return false;
			}
			else // Subfolder with given name does not exist, therefor check if the subfolder has a folder with given name...
			{
				existingFolder->CreateSubFolder(folderName);// if no, create new folder and return true, if yes return false
				return true;
			}
		}
		// Super folder does not exist, therefor return false
		return false;
	}
}

// TODO: ADD CHECK FOR EMPTY STRINGS AND NULL POINTERS
bool MySongs::AddSong(string title, const char* artist, const char* lyrics, const char* folder)
{
	Song* existingSong;
	Folder* existingFolder;
	// ie. Not placing new song in an existing directory
	if (folder == "")
	{
		// no song exist with this name therefor create song
		if ((existingSong = SongExists(title)) == nullptr)
		{
			m_collectionSongs.Add(*(new Song(title, artist, lyrics)));
			return true;
		}
		// A directory exists with this name, therefor if directory doesn't contain an identical subfolder, create new folder in that directory, else return false
		else
		{
			return false;
		}
	}
	// Placing new song in an existing directory
	else
	{
		// Check if the directory exists before trying to add new song to it
		if ((existingFolder = this->FolderExistsRecursive(folder)) != nullptr)
		{
			// Check if directory contains a song with given name
			if (!(existingFolder->SongExists(title)))// song with given name does not exist therefor add new song and return true
			{
				existingFolder->GetSongCollection().Add(*(new Song(title, artist, lyrics)));
				return true;
			}
			else // song with given name exists
			{
				return false;
			}
		}
		// folder does not exist, therefor return false
		return false;
	}
}


bool MySongs::RemoveSong(string title, const char* folderName)
{
	transform(title.begin(), title.end(), title.begin(), ::tolower);

	//TODO: revert the returned int results back to a string

	Song* existingSong;
	Folder* existingFolder;
	// Song to remove is not in a directory
	if (folderName == "")
	{
		// song exists with this name therefor delete it
		if ((existingSong = SongExists(title)) != nullptr)
		{
			Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
			while (i_collectionSongs.HasNext())
			{
				if (i_collectionSongs.Next().GetTitle() == title)
				{
					i_collectionSongs.Remove();
					return true;
				}
			}
		}
		// Song doesn't exist in current area
		return false;
	}
	// deleting song from a directory
	else
	{
		// If the folder exists and contains a song with given name
		if ((existingFolder = this->FolderExistsRecursive(folderName)) != nullptr && (existingFolder->SongExists(title)))
		{
			Iterator<Song> i_collectionSongs = existingFolder->GetSongCollection().GetIterator();
			while (i_collectionSongs.HasNext())
			{
				if (i_collectionSongs.Next().GetTitle() == title)
				{
					i_collectionSongs.Remove();
					return true;
				}
			}
		}
		// either folder does not exist or song with given name does not exist, therefor return false
		return false;
	}
}

bool MySongs::RemoveFolder(const char* folderName, const char* superFolder)
{
	Folder* existingFolder;
	// Folder to remove is not in a directory
	if (superFolder == "")
	{
		// Folder exists with this name therefor delete it
		if ((existingFolder = FolderExists(folderName)) != nullptr)
		{
			Iterator<Folder> i_collectionFolder = m_collectionFolders.GetIterator();
			while (i_collectionFolder.HasNext())
			{
				if (i_collectionFolder.Next().GetFolderName() == folderName)
				{
					i_collectionFolder.Remove();
					return true;
				}
			}
		}
		// Folder doesn't exist
		return false;
	}
	// deleting folder from a directory
	else
	{
		// If the outer folder exists and contains a folder with given name
		if ((existingFolder = this->FolderExists(superFolder)) != nullptr && (existingFolder->FolderExists(folderName)))
		{
			Iterator<Folder> i_collectionFolder = existingFolder->GetFolderCollection().GetIterator();
			while (i_collectionFolder.HasNext())
			{
				if (i_collectionFolder.Next().GetFolderName() == folderName)
				{
					i_collectionFolder.Remove();
					return true;
				}
			}
		}
		// either folder does not exist or song with given name does not exist, therefor return false
		return false;
	}
}

	


bool MySongs::MoveSong( string title, const char* destinationFolder, const char* sourceFolder)
{
	// what do i have to do...move the node or just move the song obj. and delete the node
    //>It is clear that since i am just given the title and not the rest of the song obj, it is clear i must move the obj itself to the new folder 
	//2)find if song exists...if no source:search mysong.m_collectionSongs and get point
	//1)find if destination folder exists - recursively?? 

	transform(title.begin(), title.end(), title.begin(), ::tolower);
	//TODO: revert the returned int results back to a string
	Song temp;
	Song* existingSong;
	Folder* existingFolder;
	// Song is not in an existing directory
	if (sourceFolder == "")
	{
		// no song exists with this name in this destination
		if ((existingSong = SongExists(title)) == nullptr)
		{
			return false;
		}
		else// a song exists with this name in this destination
		{
			
		}
	}
}


bool MySongs::Play(const char* title)
{
	return true;
}

bool MySongs::PrintSongs()
{
	// Get iterator and iterate over songs and cout the GetData().m_sTitle;
	return true;
}

bool MySongs::PrintFolderSongs(const char* folderName)
{
	//// Get iterator for songCollection in particular folder,and iterate over songs(nodes) and cout GetLowerCaseTitle()
	return true;
}