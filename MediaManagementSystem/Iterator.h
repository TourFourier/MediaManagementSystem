#pragma once

template<class T>
class Iterator
{
public:
	Iterator() {};
	~Iterator() {};

	T& Next();
	bool HasNext();
	void Remove();
};

