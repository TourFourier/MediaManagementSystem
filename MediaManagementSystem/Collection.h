#pragma once
#include "TNode.h"
#include "Iterator.h"
//#include "CLinkedList.h"


template<class T>
class Collection
{
private:
	TNode<T>* m_pHead = nullptr;
	Iterator<T> m_collectionIterator;
	//CLinkedList<T> m_collectionList;
	int m_listSize = 0;
public:
	Collection() 
	{
		m_collectionIterator.m_rBegin = m_pHead;
	}
	~Collection() {}

	void Add( T* newFile);
	const int Size() const { return m_listSize; };
	Iterator<T> GetIterator() { return m_collectionIterator; }
};


template<class T>
void Collection<T>::Add( T* newFile) 
{
	// If list is empty, asign node as head/first node
	if (m_pHead == nullptr) 
	{
		m_pHead = new TNode<T>(newFile);
	}
	else // Add node to list at head 
	{
		TNode<T>* newNode = new TNode<T>(newFile);
		newNode->SetNext(m_pHead);
		m_pHead = newNode;
	}
	m_listSize++;
}

