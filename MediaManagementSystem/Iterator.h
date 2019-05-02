#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	bool haventStarted = true;
	bool calledNext = false;// Used for check when calling Remove()
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
		*retVal = (*m_pBegin)->GetData();
		m_pPrevious = *m_pBegin;
		m_pCurrent = (*m_pBegin)->GetNext();
		haventStarted = false;
		calledNext = true;
	}
	else if (!haventStarted  &&  m_pCurrent != nullptr)// Have started, but haven't reached the end
	{
		*retVal = m_pCurrent->GetData();
		m_pPrevious = m_pCurrent;
		m_pCurrent = m_pCurrent->GetNext();
		calledNext = true;
	}
	else// Either the list is empty or have reached the end
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

		// We are not deleting last node
		if (m_pCurrent != nullptr)
		{
			m_pPrevious->SetNext(m_pCurrent->GetNext());
			delete m_pCurrent;
			m_pCurrent = m_pPrevious->GetNext();
		}
		else // We are deleting last node
		{
			// delete last node and set previous nodes next to point to null
			delete m_pPrevious;
			m_pPrevious = m_pCurrent;
		}
			calledNext = false;
	}
}
