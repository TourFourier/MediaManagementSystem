#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	Collection<T>* m_pCollection;
public:
	TNode<T>** m_pBegin;
	//Collection<T>* m_pCollection;

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
	//return Collection::Next(m_pCollection);
	T retVal = (*m_pBegin)->GetData();
	m_pBegin = &((*m_pBegin)->GetNext());
	return retVal;
	//T* retVal = m_pHead->GetData();
	//return retVal;
}

template<class T>
bool Iterator<T>::HasNext()
{
	
}

template<class T>
void Iterator<T>::Remove() {}
