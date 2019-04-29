#pragma once

template<class T>
class Collection
{
	Iterator<T> m_collectionIterator;
	T 
public:
	Collection() {};
	~Collection() {};

	void Add(const T newFile);
	const int Size() const;
	Iterator GetIterator() { return m_collectionIterator; }
};

