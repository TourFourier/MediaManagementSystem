#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	bool haventStarted = true;
	bool calledNext = false;// Used for check when calling Remove()
	bool afterRemoveCalled = false;
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

	// Haven't started traversing list and the list is not empty
	if (haventStarted  &&  *m_pBegin != nullptr)
	{
		// Retrieve the value of the first node and save it in retVal
		m_pCurrent = *m_pBegin;
		*retVal = m_pCurrent->GetData();
		//m_pPrevious = *m_pBegin;
		haventStarted = false;
		calledNext = true;
	}
	else if (!haventStarted  &&  m_pCurrent->GetNext() != nullptr  &&  !afterRemoveCalled)// Have started, but haven't reached the end
	{
		m_pPrevious = m_pCurrent;
		m_pCurrent = m_pCurrent->GetNext();
		*retVal = m_pCurrent->GetData();
		calledNext = true;
	}
	else if (afterRemoveCalled  &&  m_pCurrent != nullptr)// dont need to check if started because Remove() can only come after call to Next()
	{
		// Get current value and then move current to next node
		*retVal = m_pCurrent->GetData();
		//m_pPrevious = m_pCurrent;
		//m_pCurrent = m_pCurrent->GetNext();
		calledNext = true;
		afterRemoveCalled = false;
	}
	else// Either the list is empty or have reached the end <<<<<< consider having it loop from beginning
	{
		 *retVal = static_cast<T>(0);
		 calledNext = false;
	}
	return *retVal;
}

template<class T>
bool Iterator<T>::HasNext()
{
	// Haven't started traversing list, but there are nodes in list 
	if (haventStarted  &&  *m_pBegin != nullptr)  
	{
		return true;
	}
	// Have started and not at end and not after a call to Remove()
	if ((!haventStarted  &&  m_pCurrent != nullptr)  &&  (!haventStarted  &&  m_pCurrent->GetNext() != nullptr)  &&  !afterRemoveCalled)
	{
		return true;
	}

	// Have started and are possibly at end but after a call to Remove()
	if ((!haventStarted  &&  m_pCurrent != nullptr) && afterRemoveCalled)
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
		//  Removing from second node and onwards 
		if (m_pPrevious != nullptr)
		{
			m_pPrevious->SetNext(m_pCurrent->GetNext());
			delete m_pCurrent;
			m_pCurrent = m_pPrevious->GetNext();
		}
		else // Removing current first node 
		{
			m_pCurrent = m_pCurrent->GetNext();
			delete *m_pBegin;
			*m_pBegin = m_pCurrent;
		}
		calledNext = false;
		afterRemoveCalled = true;
	}
}
