#pragma once
#include "TNode.h"
#include "CLinkedList.h"


template<class T>
class Iterator
{
	TNode<T>* m_rBegin;
public:
	Iterator(TNode<T>* a) { m_rBegin = a; }
	~Iterator() {}

	T& Next();
	bool HasNext();
	void Remove();
};

template<class T>
T& Iterator<T>::Next()
{
	//TNode<T>* nodeRef = m_collectionList.GetHead();
}

template<class T>
bool Iterator<T>::HasNext()
{
	
}

template<class T>
void Iterator<T>::Remove() {}
