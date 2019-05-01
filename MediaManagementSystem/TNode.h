#pragma once

template<class T>
class TNode
{
private:
	T m_pData;
	TNode<T>* m_pNext = nullptr;
public:
	TNode() {}
	TNode(T rData) {m_pData = rData;}
	~TNode() {};

	//friend class Iterator<T>;

	T GetData() { return m_pData; }
	TNode<T>* GetNext() { return m_pNext; }

	void SetData(T pData) { m_pData = pData; };
	void SetNext(TNode<T>* pPtr) { m_pNext = pPtr; }
};


