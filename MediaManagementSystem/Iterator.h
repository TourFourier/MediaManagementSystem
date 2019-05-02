#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	bool haventStarted = true;
	bool calledNext = false;
	TNode<T>* m_pPrevious = nullptr;
	TNode<T>* m_pCurrent = nullptr;
public:
	// Will point to pointer to (first node of) list in Collection object
	TNode<T>** m_pBegin = nullptr;

	Iterator() {}
	~Iterator() {}

	T& Next();
	bool HasNext();
	void Remove();
};



template<class T>
T& Iterator<T>::Next() 
{
	// retVal must be on the heap to be returned as a reference
	T* retVal = new T;

	if (haventStarted  &&  *m_pBegin != nullptr)
	{
		*retVal = (*m_pBegin)->GetData();
		m_pPrevious = *m_pBegin;
		m_pCurrent = (*m_pBegin)->GetNext();
		haventStarted = false;
		calledNext = true;
	}
	else if (!haventStarted  &&  m_pCurrent != nullptr)
	{
		*retVal = m_pCurrent->GetData();
		m_pPrevious = m_pCurrent;
		m_pCurrent = m_pCurrent->GetNext();
		calledNext = true;
	}
	else
	{
		 *retVal = static_cast<T>(0);
		 calledNext = false;
	}
	return *retVal;
}

template<class T>
bool Iterator<T>::HasNext()
{
	// There are nodes in list and list hasn't been traversed till end
	if ((haventStarted  &&  *m_pBegin != nullptr)  || (!haventStarted  &&  m_pCurrent != nullptr))
	{
		return true;
	}
	return false;
}

template<class T>
void Iterator<T>::Remove()
{
	if (calledNext)
	{
		/*TNode<T>* temp = *m_pBegin;
		while (*m_pBegin != m_pPrevious)
		{
			*m_pBegin = *(m_pBegin)->GetNext();
		}
		delete m_pPrevious;
		m_pPrevious = m_pCurrent;// I have reassigned m_pPrevious pointer but not m_pHead in collection and it is dangling and pointing to freed mem
		*m_pBegin = m_pCurrent;
		*m_pBegin = temp;
		calledNext = false;*/
		m_pCurrent = m_pCurrent->GetNext();
		m_pPrevious->SetNext(m_pCurrent);
		delete m_pPrevious;
		calledNext = false;

	}
}
