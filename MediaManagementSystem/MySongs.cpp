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

// Returns nullptr if folder doesn't exist otherwise returns a pointer to the folder obj.
Folder* MySongs::FolderExists(const char* folderName)
{
	Folder* retVal = nullptr;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		retVal = &(i_collectionFolders.Next());
		if ( retVal->GetFolderName() == folderName)
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


bool MySongs::AddFolder(const char* folderName, const char* superFolder = "")
{
	//returns false if 1)name of file already exists both in current folder and sub 
	//2) name of folder-to-create-in doesnt exist
	
	Folder* existingFolder;
	// ie. Not placing new folder in an existing directory
	if (superFolder == "")
	{
		// no directory exist with this name therefor create directory
		if ((existingFolder = FolderExists(folderName)) == nullptr)
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
		if ((existingFolder = this->FolderExists(superFolder)) != nullptr)
		{
			// Check if directory contains a folder with given name
			if (existingFolder->FolderExists(folderName))// subfolder with given name exists
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
bool MySongs::AddSong(string title, const char* artist, const char* lyrics, const char* folder="")
{
	transform(title.begin(), title.end(), title.begin(), ::tolower);

	//TODO: revert the returned int results back to a string
	
	Song* existingSong;
	Folder* existingFolder;
	// ie. Not placing new song in an existing directory
	if (folder == "")
	{
		// no song exist with this name therefor create song
		if ((existingSong = SongExists(title)) == nullptr)
		{
			m_collectionSongs.Add(*(new Song(title,artist,lyrics)));
			return true;
		}
		// A directory exists with this name, therefor if directory doesn't contain an identical subfolder, create new folder in that directory, else return false
		else
		{
			return false;// (CreatedSubFolder(folderName, existingFolder));
		}
	}
	// Placing new song in an existing directory
	else
	{
		// Check if the directory exists before trying to add new song to it
		if ((existingFolder = this->FolderExists(folder)) != nullptr)
		{
			// Check if directory contains a song with given name
			if (!(existingFolder->SongExists(title)))// song with given name does not exist therefor add new song and return true
			{
				existingFolder->GetSongCollection().Add(*(new Song(title, artist,lyrics)));
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


bool MySongs::RemoveSong(const char* title)
{
	//If has-a: Collection<Song>.GetIterator().Next() [till: title == current.GetData()].Remove();
	//If is-a:  GetIterator().Next() [till: title == current.GetData()].Remove;
	return true;
}

bool MySongs::RemoveFolder(const char* folderName)
{
	//If has-a: Collection<folder>.GetIterator().Next() [till: title == current.GetData()].Remove();
	//If is-a:  GetIterator().Next() [till: title == current.GetData()].Remove;
	return true;
}

bool MySongs::MoveSong(const char* tiltle, const char* destinationFolderName)
{
	return true;
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
	//// Get iterator and iterate over songs and cout the GetData().m_sTitle;
	return true;
}