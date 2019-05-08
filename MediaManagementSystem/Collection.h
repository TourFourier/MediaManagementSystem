#pragma once
#include "TNode.h"
#include "Iterator.h"


template<class T>
class Collection
{
private:
	TNode<T>* m_pCollectionListHead = nullptr;
	//Iterator<T> m_collectionIterator;
	void bubbleSort(T arr[], int n);
	void swap(T *xp, T *yp);
public:
	Collection()
	{
		//m_collectionIterator.m_pBegin = &m_pCollectionListHead;

	}
	//Alternative way to give iterator acess to list: friend class Iterator<T>;
	~Collection() {} // TODO: ADD DELETE IN DESTRUCTOR TO m_pCollectionListHead TO DELETE THE LIST AND FREE THE HEAP??

	void Add( T newFile);
	int Size();
	Iterator<T> GetIterator() 
	{
		// Null Iterator's m_pCurrent pointer, so that Iterator's Next() method gives access to the first element in  the list
		//m_collectionIterator.m_pCurrent = nullptr;
		//m_collectionIterator.m_pPrevious = nullptr;
		//return m_collectionIterator; 

		Iterator<T> itr(this->m_pCollectionListHead);
		return itr;
	}
};




template<class T>
void Collection<T>::Add(T newFile) 
{
	// If list is empty, asign node as head/first node
	if (m_pCollectionListHead == nullptr) 
	{
		m_pCollectionListHead = new TNode<T>(newFile);
	}
	else // Add new node to list at head and then sort the list
	{
		int i = 0;
		int sizeOfList;
		T* dataArray;
		TNode<T>* temp;

		// Adding new node to head of list
		TNode<T>* newNode = new TNode<T>(newFile);
		newNode->SetNext(m_pCollectionListHead);
		// Reset head pointer
		m_pCollectionListHead = newNode;

		// Create array of proper size for sorting the nodes 
		sizeOfList = Size();
		dataArray = new T[sizeOfList];
		temp = m_pCollectionListHead;
		// Fill array with node data 
		while (temp != nullptr)
		{
			dataArray[i] = temp->GetData();
			temp = temp->GetNext();
			i++;
		}
		
		// Sort from smallest to greatest
		bubbleSort(dataArray, sizeOfList);
		// Insert data back into list, in sorted order
		i = 0;
		temp = m_pCollectionListHead;
		while (temp != nullptr)
		{
			temp->SetData(dataArray[i]);// not so efficient because we are copying data--if it is big objects it could be costly
			temp = temp->GetNext();
			i++;
		}
		delete[]dataArray;
	}
}

template<class T>
int Collection<T>::Size()
{
	int retVal = 0;
	TNode<T>* temp = m_pCollectionListHead;

	while (temp != nullptr)
	{
		retVal++;
		temp = temp->GetNext();
	}
	return retVal;
};

template<class T>
void Collection<T>::swap(T *xp, T *yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort 
template<class T>
void Collection<T>::bubbleSort(T arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
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