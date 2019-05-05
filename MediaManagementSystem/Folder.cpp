#include "pch.h"
#include <string>
#include "Collection.h"
#include "Song.h"
#include "Folder.h"

using std::string;

Folder::Folder(const string folderName):
	m_sFolderName(folderName)
{}


Folder::~Folder()
{
}


Folder& Folder::GetFolder(const char* folderName)
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

bool Folder::FolderExists(const char* folderName)
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

bool Folder::CreatedSubFolder(const char* folderName, const char* superFolder)
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