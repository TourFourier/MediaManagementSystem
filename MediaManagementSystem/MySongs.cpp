#include "pch.h"
#include "TNode.h"
#include "Song.h"
#include "Folder.h"
#include "Iterator.h"
#include "Collection.h"
#include "MySongs.h"


MySongs::MySongs()
{
}


MySongs::~MySongs()
{
}



Folder& MySongs::GetFolder(const char* folderName)
{
	Folder& retVal = new Folder;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();

	// Iterate over the collection of folders and check if the name of each existing folder matches the name of the new folder we are creating
	while (i_collectionFolders.HasNext())
	{
		retVal = i_collectionFolders.Next();
		if (retVal.GetFolderName() == folderName)
		{
			return retVal;
		}
	}

}


bool MySongs::FolderExists(const char* folderName)
{
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		if (i_collectionFolders.Next().GetFolderName() == folderName)
		{
			return true;
		}
	}
	return false;
}

bool MySongs::CreatedSubFolder(const char* folderName, const char* superFolder)
{
	Folder outerFolder = GetFolder(superFolder);
	// Check if outer folder does not contain an inner folder with the same name as new folder
	if (!(outerFolder.FolderExists(folderName)))
	{
		outerFolder.GetFolderCollection().Add(new Folder(folderName));
		return true;
	}
	return false;
}

bool MySongs::AddFolder(const char* folderName, const char* superFolder = "")
{
	//returns false if 1)name of file already exists both in current folder and sub 
	//2) name of folder-to-create-in doesnt exist
	// create a folder obj and...
	//If has-a: Collection<folder>.Add(folder obj);
	//If is-a:  Add(folder obj);

	// ie. Not placing new folder in an existing directory
	if (superFolder == "")
	{
		// no directory exist with this name therefor create directory
		if (!FolderExists)
		{
			m_collectionFolders.Add(new Folder(folderName));
			return true;
		}
		// A directory exists with this name, therefor if directory doesn't contain an identical subfolder, create new folder in that directory, else return false
		else
		{
			return (CreatedSubFolder(folderName, superFolder));
		}
	}
	// Placing new folder in an existing directory
	else
	{
		// Check if the directory exists; if not function returns false 
		if (FolderExists(superFolder))
		{
			// Check if directory contains a folder with given name
			if (CreatedSubFolder(folderName, superFolder))// no subfolder with given name therefor successfully created a subfolder
			{
				return true;
			}
			else // Subfolder with given name exists, therefor check if the subfolder has a folder with given name...
			{
				return GetFolder(superFolder).CreatedSubFolder(folderName, folderName);// if no, create new folder and return true, if yes return false
			}
		}
		// Super folder does not exist, therefor return false
		return false;
	}
	//return true;
}

// ???????ADD CHECK FOR EMPTY STRINGS????????  AND NULL POINTERS?????
bool MySongs::AddSong(const char* title, const char* artist, const char* lyrics)
{
	// create a song obj and...
	//If has-a: Collection<Song>.Add(song obj);
	//If is-a:  Add(song obj);
	return true;
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