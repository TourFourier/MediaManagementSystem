#pragma once
#include "TNode.h"
#include "CLinkedList.h"
#include "Iterator.h"


template<class T>
class Collection
{
private:
	TNode<T>* a = nullptr;
	Iterator<T> m_collectionIterator;
	//CLinkedList<T> m_collectionList;
	int m_listSize = 0;
public:
	Collection():Iterator(a) {}
	~Collection() {}

	void Add( T* newFile);
	const int Size() const { return m_listSize; };
	//Iterator<T> GetIterator() { return new Iterator<T>(*(m_collectionList.GetHead())&; }
};


template<class T>
void Collection<T>::Add( T* newFile) 
{
	TNode<T>* newNode = new TNode<T>(newFile);
	//m_collectionList.Insert(newNode);
	m_listSize++;
}

