#pragma once
//#include "Collection.h"
#include "TNode.h"


template<class T>
class Iterator
{
private:
	Collection<T>* m_pCollection;
public:
	TNode<T>* m_pBegin;

	Iterator(Collection<T>* c) 
	{ 
		m_pCollection = c; 
	}
	~Iterator() {}

	T& Next();
	bool HasNext();
	void Remove();
};

template<class T>
T& Iterator<T>::Next()
{
	TNode<T>* temp = m_pBegin;
	//T arr[m_pCollection->Size()];
	while (!temp->GetNext() == nullptr) {}
}

template<class T>
bool Iterator<T>::HasNext()
{
	
}

template<class T>
void Iterator<T>::Remove() {}
