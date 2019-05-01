#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	bool haventStarted = true;
	bool calledNext = false;
public:
	TNode<T>* m_pPrevious = nullptr;
	TNode<T>* m_pCurrent = nullptr;
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
	T retVal;

	if (haventStarted  &&  *m_pBegin != nullptr)
	{
		retVal = (*m_pBegin)->GetData();
		m_pPrevious = *m_pBegin;
		m_pCurrent = (*m_pBegin)->GetNext();
		haventStarted = false;
		calledNext = true;
	}
	else if (!haventStarted  &&  m_pCurrent != nullptr)
	{
		retVal = m_pCurrent->GetData();
		m_pPrevious = m_pCurrent;
		m_pCurrent = m_pCurrent->GetNext();
		calledNext = true;
	}
	else
	{
		 retVal = static_cast<T>(0);
		 calledNext = false;
	}
	return retVal;
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
		delete m_pPrevious;
		m_pPrevious = m_pCurrent;
		calledNext = false;
	}
}
