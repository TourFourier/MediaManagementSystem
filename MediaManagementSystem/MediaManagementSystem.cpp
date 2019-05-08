
#include "pch.h"
#include <iostream>
#include <string>
#include "TNode.h"
#include "Iterator.h"
#include "Collection.h"
#include "Song.h"
#include "Folder.h"
#include "MySongs.h"
//#define SIZE 26

using std::ostream;
using std::cout;
using std::endl;
using std::string;
/*
bool anagram(const char* str1, const char* str2)
{
	int arrOfLetters[SIZE] = { 0 }, i;
	for (i = 0; i < strlen(str1); i++)
	{
		if (str1[i] <= 'z' && str1[i] >= 'a')
			arrOfLetters[str1[i] - 'a'] ++;
		else if(str1[i] <= 'Z' && str1[i] >= 'A')
			arrOfLetters[str1[i] - 'A'] ++;	
	}
	for (i = 0; i < strlen(str2); i++)
	{
		if (str2[i] <= 'z' && str2[i] >= 'a')
			arrOfLetters[str2[i] - 'a'] --;
		else if(str2[i] <= 'Z' && str2[i] >= 'A')
			arrOfLetters[str2[i] - 'A'] --;
	}
	for (i = 0; i < SIZE; i++)
	{
		if (arrOfLetters[i] != 0)
			return false;
	}
	return true;
}
int main()
{
	cout << anagram("Hello World!", "Hello Word!");
}*/
int main()
{	//Remove parameter superfolder from method RemoveFolder()

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
	mySongs.AddFolder("hebrew");
	mySongs.AddFolder("old" , "hebrew");
	//mySongs.AddFolder("new", "Hebrew");
	mySongs.AddSong("Road of the King", "Gili", "Road of the king is my onlyroute...", "old");
	mySongs.AddSong("Road of the queen", "Prison 6", "Road of the queen is myonly route..." , "hebrew");
	mySongs.PrintFolderSongs("hebrew" , "Prison 6");
	cout << endl;
	mySongs.PrintFolderSongs("old" , "Gili");
	cout << endl;
	cout << endl;

	mySongs.Play("Road of the queen", "hebrew");
	mySongs.Play("Road of the King", "old");
	//mySongs.RemoveSong("Road of the King", "old");
	//mySongs.Play("Road of the King", "old");
	//mySongs.MoveSong("Road of the King", "hebrew", "old");
	mySongs.RemoveFolder("old");

	cout << endl;
	cout << endl;
	//cout << "moving song" << endl;
	//mySongs.Play("Road of the King", "hebrew");


	//mySongs.PrintSongs();
	//mySongs.Play("Road of the King", "old");



	//Iterator<Folder> itr = mySongs.GetFolderCollection().GetIterator();
	//while (itr.HasNext())
	//{
		//cout << itr.Next().GetFolderName() << endl;
	//}
	//mySongs.PrintFolderSongs("new", "Prison 6");
	//mySongs.AddSong("Road of the King", "Prison 6", "Road of the king is myonly route...", "new");
	//>>>>>mySongs.MoveSong("MATAM EX4", "Hebrew");
	//>>>>>mySongs.PrintFolderSongs("Hebrew");...
	/*.Play("MATAM EX4", "Hebrew"); // This will fail!
	mySongs.PrintSongs("Shlomo"); // Will print nothing.
	mySongs.RemoveSong("Road of the King"); // This will fail!*/
	return 0;
}

