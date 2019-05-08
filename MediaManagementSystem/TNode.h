#pragma once

template<class T>
class TNode
{
private:
	T m_tData;
	TNode<T>* m_pNext = nullptr;
public:
	TNode() {}
	TNode(T rData) {m_tData = rData;}
	~TNode() {};

	T& GetData() { return m_tData; }
	TNode<T>* GetNext() { return m_pNext; }

	void SetData(T pData) { m_tData = pData; };
	void SetNext(TNode<T>* pPtr) { m_pNext = pPtr; }
};


