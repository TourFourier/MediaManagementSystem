#pragma once
#include "TNode.h"
//#include "Collection.h"


template<class T>
class Iterator
{
private:
	bool haventStarted = true;
	bool calledNext = false;// Used for check when calling Remove()
	bool removeNodeCalled = false;
public:
	// Will point to member pointer to (first node of) list in Collection object; only weak point about this calss is this public member; 
	//necessary to allow collection class to give me access to its List-head pointer
	TNode<T>* m_pPrevious = nullptr;
	TNode<T>* m_pCurrent = nullptr;
	TNode<T>** m_pBegin = nullptr;

	//Iterator(TNode<T>* head) : m_pBegin(&head) {}
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
	T* retVal;
	static T* somethingToReturn = new T;// No mem leak because its static
	// Haven't started traversing list and the list is not empty
	if (haventStarted  &&  *m_pBegin != nullptr)
	{
		// Point to first node and retrieve the value and save it in retVal
		m_pCurrent = *m_pBegin;
		retVal = &(m_pCurrent->GetData()); //m_pCurrent->GetData() - returns a reference to the data stored in the node, therefor store its address in retVal pointer and return address
		//m_pPrevious = *m_pBegin;
		haventStarted = false;
		calledNext = true;
	}
	// Have started, but haven't reached the end; move to next node and retreive value
	else if (!haventStarted  &&  m_pCurrent->GetNext() != nullptr  &&  !removeNodeCalled)
	{
		m_pPrevious = m_pCurrent;
		m_pCurrent = m_pCurrent->GetNext();
		retVal = &(m_pCurrent->GetData());
		calledNext = true;
	}
	// Dont need to check if started because Remove() can only come after call to Next()
	else if (m_pCurrent != nullptr  &&  removeNodeCalled)
	{
		// Get current nodes value but keep current pointer on this node (b/c every call to next first shifts the pointer)
		retVal = &(m_pCurrent->GetData());
		calledNext = true;
		removeNodeCalled = false;
	}
	else// Either the list is empty or have reached the end 
		//<<<<<< consider having it loop to beginning, but would need to fix HasNext() to recognize that
	{
		 calledNext = false;
		 return *somethingToReturn;
	}
	return *retVal;
}

template<class T>
bool Iterator<T>::HasNext()
{
	// Haven't started traversing list, and there are nodes in list 
	if (haventStarted  &&  *m_pBegin != nullptr)  
	{
		return true;
	}
	// Have started and not at end and not following a call to Remove()
	if ((!haventStarted  &&  m_pCurrent != nullptr)  &&  (!haventStarted  &&  m_pCurrent->GetNext() != nullptr)  &&  !removeNodeCalled)
	{
		return true;
	}

	// Have started and are possibly at end but are following a call to Remove()
	if ((!haventStarted  &&  m_pCurrent != nullptr) && removeNodeCalled)
	{
		return true;
	}

	return false;
}

// Deletes current node
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
		removeNodeCalled = true;
	}
}
