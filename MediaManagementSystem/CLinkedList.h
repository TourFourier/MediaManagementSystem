#pragma once
#include <iostream>
#include <string>
#include "Iterator.h"
#include "TNode.h"
#include "CLinkedList.h"

using namespace std;
template<class T>
class CLinkedList
{
private:
	TNode<T>* m_pHead = nullptr;
public:
	CLinkedList(){};
	~CLinkedList() {};

	//friend class Iterator<T>;

	//int GetLength();
	TNode<T>* GetHead() { return m_pHead; }
	//void Insert(TNode<T>* pNode); // Inserts node at head of list 
	//TNode<T>* Delete(); // Deletes first node in the list and returns the deleted node
	//TNode<T>* GetNode(std::string sData);
	//void Display(); // Prints ...
	//const int ListLength()const;
};

/*

template<class T>
void CLinkedList<T>::Insert(TNode<T>* pNode)
{
	if (m_pHead == nullptr) // If list is empty, asign node as head/first node
	{
		m_pHead = pNode;
	}
	else // Add node to list at head 
	{
		pNode->SetNext(m_pHead);
		m_pHead = pNode;
	}
}

//Delete the first node in the list (at head)
template<class T>
TNode<T>* CLinkedList<T>::Delete()
{
	TNode<T>* temp;
	if (m_pHead == nullptr)
	{
		temp = nullptr;
	}
	else
	{
		temp = m_pHead;
		m_pHead = m_pHead->GetNext();
	}
	return temp; // return the deleted node
}

// the argument should be a generic key that can work on any node type // Returns pointer to desired node if exists, otherwise...
template<class T>
TNode<T>* CLinkedList<T>::GetNode(std::string sData)
{
	if (m_pHead != nullptr)

	{
		TNode<T>* temp = m_pHead;
		while (temp != nullptr)
		{
			if (to_string(temp->GetData()) == sData)  
			{
				return temp;
			}
			else
			{
				temp = temp->GetNext();
			}
		}
		return 0;
	}
	return 0;
}

template<class T>
const int CLinkedList<T>::ListLength()const
{
	int counter = 0;
	TNode<T>* temp = m_pHead;
	while (temp != nullptr)
	{
		temp = temp->GetNext();
		counter++;
	}

	return counter;
}
*/