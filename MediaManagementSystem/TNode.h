#pragma once
#include "Iterator.h"

template<class T>
class TNode
{
private:
	T* m_pData = nullptr;
	TNode* m_pNext = nullptr;
public:
	TNode(T* rData);
	~TNode();

	//friend class Iterator<T>;

	T GetData() { return m_pData; }
	TNode* GetNext() { return m_pNext; }

	//void SetData(T* pData) { m_pData = pData; };
	void SetNext(TNode* pPtr) { m_pNext = pPtr; }
};

template<class T>
TNode<T>::TNode(T* rData)
{
	m_pData = rData;
}


template<class T>
TNode<T>::~TNode()
{
}
