#include "pch.h"
#include <algorithm>
#include <string> 
#include <iostream>
#include "TNode.h"
#include "Iterator.h"
#include "Collection.h"
#include "Song.h"
#include "Folder.h"
#include "MySongs.h"

using std::cout;
using std::endl;
using std::string;
using std::transform;

MySongs::MySongs()
{
}


MySongs::~MySongs()
{
}



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
bool MySongs::SongExists(string title)
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
	Folder* existingFolder;
	// ie. Not placing new song in an existing directory
	if (folder == "")
	{
		// no song exist with this name therefor create song
		if (!SongExists(title))
		{
			m_collectionSongs.Add(*(new Song(title, artist, lyrics)));
			m_nTotalNumOfSongs++;
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
				m_nTotalNumOfSongs++;
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
	Folder* existingFolder;
	// Song to remove is not in a directory
	if (folderName == "")
	{
		// song exists with this name therefor delete it
		if (SongExists(title))
		{
			Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
			while (i_collectionSongs.HasNext())
			{
				if (i_collectionSongs.Next().GetTitle() == title)
				{
					i_collectionSongs.Remove();
					m_nTotalNumOfSongs--;
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
					m_nTotalNumOfSongs--;
					return true;
				}
			}
		}
		// either folder does not exist or song with given name does not exist, therefor return false
		return false;
	}
}

bool MySongs::RemoveFolder(const char* folderName)
{
	Folder* existingFolder;
	if ((existingFolder = FolderExistsRecursive(folderName)) != nullptr)
	{
		FolderRemoveRecursive(folderName);
		return true;
	}
	// Folder does not exist, therefor return false
	return false;

	// Folder to remove is not in a directory
	

	// If a folder exists with given name
}

bool MySongs::MoveSong( string title, const char* destinationFolderName, const char* sourceFolderName)
{
	Folder* sourceFolder = FolderExistsRecursive(sourceFolderName);
	Folder* destinationFolder = FolderExistsRecursive(destinationFolderName);
	Song songToMove;
	// Check if folder(s) and song exist(s). If yes, copy song objects fileds to songToMove and if not return false
	if (sourceFolderName == "")// No source folder was provided
	{
		if (destinationFolder == nullptr  || (!SongExists(title)))
		{
			return false;
		}
		else 
		{
			Iterator<Song> itr = m_collectionSongs.GetIterator();
			while (itr.HasNext())
			{
				songToMove = itr.Next();
				if (songToMove.GetTitle() == title)
				{
					break;// Exit the while loop; songToMove now contains the song details
				}
			}
		}
	}
	else // A source folder was provided
	{
		if (sourceFolder == nullptr || destinationFolder == nullptr  || !(sourceFolder->SongExists(title)))
		{
			return false;
		}
		else
		{
			Iterator<Song> itr = sourceFolder->GetSongCollection().GetIterator();
			while (itr.HasNext())
			{
				songToMove = itr.Next();
				if (songToMove.GetTitle() == title)
				{
					break;// Exit the while loop; songToMove now contains the song details
				}
			}
		}
	}

	// At this point we have verified existence of source and destination folders and song 
	// Delete source node 
	if (sourceFolderName == "")
	{
		Iterator<Song> itr = m_collectionSongs.GetIterator();
		while (itr.HasNext())
		{
			if (itr.Next().GetTitle() == title)
			{
				itr.Remove();
			}
		}
	}
	else
	{
		Iterator<Song> itr = sourceFolder->GetSongCollection().GetIterator();
		while (itr.HasNext())
		{
			if (itr.Next().GetTitle() == title)
			{
				itr.Remove();
			}
		}
	}

	// Create new node in destination folder and add song to it
	destinationFolder->GetSongCollection().Add(songToMove);

	return true;
}

bool MySongs::Play(const char* title, const char* folderName)
{
	Song songToPlay;
	Folder* songsFolder = FolderExistsRecursive(folderName);
	// Check if folder(s) and song exist(s). If not return false
	if (folderName == "")// No source folder was provided
	{
		if (!(this->SongExists(title)))
		{
			return false;
		}
		else
		{
			Iterator<Song> itr = m_collectionSongs.GetIterator();
			while (itr.HasNext())
			{
				songToPlay = itr.Next();
				if (songToPlay.GetTitle() == title)
				{
					songToPlay.PrintSongLyrics();
					cout << endl;
				}
			}
		}
	}
	else// A folder name was provided
	{
		if (songsFolder == nullptr  || !(songsFolder->SongExists(title)))
		{
			return false;
		}
		else
		{
			Iterator<Song> itr = FolderExistsRecursive(folderName)->GetSongCollection().GetIterator();
			while (itr.HasNext())
			{
				songToPlay = itr.Next();
				if (songToPlay.GetTitle() == title)
				{
					songToPlay.PrintSongLyrics();
					cout << endl;
				}
			}
		}
	}
	return true;
}

bool MySongs::PrintFolderSongs(const char* folderName, const char* artist)
{
	Folder* folderToPrint = FolderExistsRecursive(folderName);
	
	Song currentSong;

	// Print root song collection
	if (folderName == "")
	{
		Iterator<Song> i_collectionSongs = m_collectionSongs.GetIterator();
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
	else// Print songs of a selected folder
	{
		// Folder doesn't exist
		if (folderToPrint == nullptr)
		{
			return false;
		}
		// Folder exists
		folderToPrint->PrintSongCollection(artist);
	}
	
	return true;
}

bool MySongs::PrintSongs(const char* artist)
{
	int i;
	string* titleArray = new string[m_nTotalNumOfSongs];

	// Print all songs regardless of artists
	if (artist == "")
	{
		int numOfSongs = SongTitleRec(titleArray);
		bubbleSortCaseIns(titleArray, numOfSongs);
		for (i = 0; i < numOfSongs; i++)
		{
			cout << titleArray[i] << endl;
		}
	}
	else // Print only songs of particular artist
	{
		int numOfSongs = SongTitleArtistRec(titleArray, artist);
		bubbleSortCaseIns(titleArray, numOfSongs);
		//add check for if array is empty ie. no songs of this artist:  if (titleArray[0] != "").. then print
		for (i = 0; i < numOfSongs; i++)
		{
			cout << titleArray[i] << endl;
		}
	}
	return true;
}


void MySongs::swap(string *xp, string *yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A case insensitive version of Bubble Sort 
void  MySongs::bubbleSortCaseIns(string arr[], int n)
{
	int i, j;
	bool swapped;
	string tempJ, tempJPlusOne;

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			tempJ = arr[j];
			transform(tempJ.begin(), tempJ.end(), tempJ.begin(), ::tolower);
			tempJPlusOne = arr[j + 1];
			transform(tempJPlusOne.begin(), tempJPlusOne.end(), tempJPlusOne.begin(), ::tolower);

			if (tempJ > tempJPlusOne)
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

int MySongs::SongTitleRec(string* titles, int index)
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

int MySongs::SongTitleArtistRec(string* titles, const char* artist, int index)
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

bool MySongs::FolderRemoveRecursive(const char* folderName)
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
