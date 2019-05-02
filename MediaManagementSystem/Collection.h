#pragma once
#include "TNode.h"
#include "Iterator.h"


template<class T>
class Collection
{
private:
	TNode<T>* m_pHead = nullptr;
	Iterator<T> m_collectionIterator;
	void bubbleSort(T arr[], int n);
	void swap(T *xp, T *yp);

		/*static T& Next(Collection<T>* pThis) 
		{
			T retVal = pThis->m_pHead->GetData();
			pThis->m_pHead = pThis->m_pHead->GetNext();
			return retVal;
		}*/
public:
	Collection()
	{
		m_collectionIterator.m_pBegin = &m_pHead;
	}
	~Collection() {}

			void printList()
			{
				TNode<T>* temp = m_pHead;
				while (temp != nullptr)
				{
					std::cout << temp->GetData() << std::endl;
					temp = temp->GetNext();
				}
			}
			//friend class Iterator<T>;

	void Add( T newFile);
	int Size();
	Iterator<T> GetIterator() 
	{
		// Null Iterator's m_pCurrent pointer, so that Iterator's Next() method gives access to the first element in  the list
		//m_collectionIterator.m_pCurrent = nullptr;
		//m_collectionIterator.m_pPrevious = nullptr;

		return m_collectionIterator; 
	}
};




template<class T>
void Collection<T>::Add( T newFile) 
{
	// If list is empty, asign node as head/first node
	if (m_pHead == nullptr) 
	{
		m_pHead = new TNode<T>(newFile);
	}
	else // Add new node to list at head and sort the list
	{
		int i = 0;
		int m_listSize = (Size()+1);
		TNode<T>* temp;
		T* dataArray = new T[m_listSize];
		// Adding new node
		TNode<T>* newNode = new TNode<T>(newFile);
		newNode->SetNext(m_pHead);
		// Reset head pointer
		m_pHead = newNode;

		temp = m_pHead;
		// Fill array with node data 
		while (temp != nullptr)
		{
			dataArray[i] = temp->GetData();
			temp = temp->GetNext();
			i++;
		}
		
		bubbleSort(dataArray, m_listSize);
		// Insert data into list in sorted order
		i = 0;
		temp = m_pHead;
		while (temp != nullptr)
		{
			temp->SetData(dataArray[i]);
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
	TNode<T>* temp = m_pHead;

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