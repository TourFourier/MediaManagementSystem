
#include "pch.h"
#include <iostream>
#include <string>
#include "TNode.h"
#include "Iterator.h"
#include "Collection.h"
#include "Song.h"
#include "Folder.h"
#include "MySongs.h"

using std::ostream;
using std::cout;
using std::endl;
using std::string;

int main()
{
	
	/*
		Collection<string> stringCollection;
		stringCollection.Add("Hello");
		stringCollection.Add("World");

		Iterator<string> itr = stringCollection.GetIterator();
		while (itr.HasNext())
		{
			cout << itr.Next() << endl;
		}
		itr = stringCollection.GetIterator();
		while (itr.HasNext())
		{
			const string& s = itr.Next();
			if (s == "Hello")
			{
				cout << s << endl;
			}		
			else
		    {
				itr.Remove();
			}
		}
		cout << "there are " << stringCollection.Size() << " elements in the collection. " << endl;
		itr = stringCollection.GetIterator();
		while (itr.HasNext())
		{
			cout << itr.Next() << endl;
		}
		stringCollection.Add("A");
		stringCollection.Add("B");
		stringCollection.Add("a");
		stringCollection.Add("b");
		stringCollection.Add("shalom");
		cout << "there are " << stringCollection.Size() << " elements in the collection. " << endl;

		itr = stringCollection.GetIterator();

		while (itr.HasNext())
		{
			cout << "removing " << itr.Next() << endl;
			itr.Remove();
		}
		if (!itr.HasNext())
		{
			cout << "No more elements!" << endl;
		}
	*/
			MySongs mySongs;
			//mySongs.AddSong("MATAM EX4", "Ari", "We like C++ programing...");
			mySongs.AddFolder("Hebrew");
			//mySongs.AddFolder("two");
			//mySongs.AddFolder("three");

			mySongs.AddFolder("old", "Hebrew");
			//mySongs.AddFolder("new", "Hebrew"); 

			Collection<Folder> superf = mySongs.GetFolderCollection();
			Iterator<Folder> isuperf = superf.GetIterator();
			//while (itr2.HasNext())
			//{
			//Folder f = itr2.Next();// the GetIterator() is returning an iterator that does not point to Folders first node rather null
			Folder& f = isuperf.Next();
			Collection<Folder> cf = f.GetFolderCollection();
			Iterator<Folder> icf = cf.GetIterator();
			Folder& subf = icf.Next();
			string subfName = subf.GetFolderName();

			cout << subfName;

				//Folder g = f.GetFolderCollection().GetIterator().Next();
				//cout << g.GetFolderName() << endl;

			//}
		/*	mySongs.AddSong("Road of the King", "Gili", "Road of the king is my onlyroute...", "old");
			mySongs.AddSong("Road of the King", "Prison 6", "Road of the king is myonly route...", "new");
			mySongs.PrintSongs();
			mySongs.Play("MATAM EX4");
			mySongs.MoveSong("MATAM EX4", "Hebrew");
			mySongs.PrintFolderSongs("Hebrew");
			mySongs.MoveSong("MATAM EX4", "new", "Hebrew");
			mySongs.Play("MATAM EX4", "Hebrew"); // This will fail!
			mySongs.PrintSongs("Shlomo"); // Will print nothing.
			mySongs.PrintFolderSongs("new", "Prison 6");
			mySongs.RemoveSong("Road of the King"); // This will fail!
			mySongs.RemoveSong("Road of the King", "old");
			mySongs.RemoveFolder("old");
		*/
			return 0;
}

