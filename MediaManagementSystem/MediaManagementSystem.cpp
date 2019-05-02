
#include "pch.h"
#include <iostream>
#include <string>
#include "TNode.h"
#include "Iterator.h"
#include "Collection.h"
using std::ostream;
using std::cout;
using std::endl;
using std::string;

int main()
{
	
	
		Collection<string> stringCollection;
		stringCollection.Add("Hello");
		stringCollection.Add("World");
		//stringCollection.Add("Zen");

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
		return 0;
	
	
	
	//Collection<int> co;
	//Iterator<int> it = co.GetIterator();
	//int* i = new int(7);
	//TNode<int>* n = new TNode<int>(i);
	/*co.Add(7);
	co.Add(8);
	co.Add(3);
	co.Add(9);
	co.Add(2);
	co.Add(2);
	co.Add(4);
	co.Add(15);*/

	/*co.printList();

	cout << it.HasNext() << endl;

	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;

	cout << it.HasNext() << endl;


	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;
	/*cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;
	cout << it.Next() << endl;

	cout << it.HasNext() << endl;*/




	//cout<<co.Size()<<endl;
	//cout<<(ll.GetNode(to_string(11))->GetData());
}

