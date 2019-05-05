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
	Folder* retVal = new Folder;
	Iterator<Folder> i_collectionFolders = m_collectionFolders.GetIterator();

	while (i_collectionFolders.HasNext())
	{
		if ()
	}


}

bool MySongs::FolderExists(const char* folderName)
{
	int n_flag = 0;
	Iterator<Folder> i_collectionFolders =  m_collectionFolders.GetIterator();
	while (i_collectionFolders.HasNext())
	{
		if (i_collectionFolders.Next().GetFolderName() == folderName)
		{
			n_flag = 1;
		}
	}
	(n_flag == 1) ? return true : return false
}


bool MySongs::AddFolder(const char* folderName, const char* superFolder="")
{
	//returns false if 1)name of file already exists both in current folder and sub 
	//2) name of folder-to-create-in doesnt exist
	// create a folder obj and...
	//If has-a: Collection<folder>.Add(folder obj);
	//If is-a:  Add(folder obj);
	// ie. Not placing in an existing directory
	if (superFolder == "")
	{
		if (!FolderExists)
		{
			m_collectionFolders.Add(folderName);
		}
		else
		{


		}
	}
	// Placing in an existing directory
	else
	{

	}

	return true;
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