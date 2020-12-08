#pragma once
#include "ArrayList.h"
#include <iostream>
using namespace std;

template <class T>
class TArrayListIterator
{
protected:
	TArrayList<T>& list;
	int index;
public:
	TArrayListIterator(TArrayList<T>& _list, int _index = -2);
	TArrayListIterator(TArrayListIterator<T>& other);
	~TArrayListIterator();

	bool IsGoNext();
	void GoNext();

	TArrayListIterator<T>& operator = (const TArrayListIterator<T>& other);
	bool operator == (const TArrayListIterator<T>& other);
	bool operator != (const TArrayListIterator<T>& other);

	T GetData();
	int GetIndex();
};

template<class T>
inline TArrayListIterator<T>::TArrayListIterator(TArrayList<T>& _list, int _index) : list(_list)
{
	this->index = _index;
}

template<class T>
inline TArrayListIterator<T>::TArrayListIterator(TArrayListIterator<T>& other)
{
	this->list = other.list;
	this->index = other.index;
}

template<class T>
inline TArrayListIterator<T>::~TArrayListIterator()
{
	index = -2;
}

template<class T>
inline bool TArrayListIterator<T>::IsGoNext()
{
	if (index >= 0)
		return true;
	else return false;
}

template<class T>
inline void TArrayListIterator<T>::GoNext()
{
	if (this->IsGoNext())
		index = list.links[index];
	else throw - 1;
}

template<class T>
inline TArrayListIterator<T>& TArrayListIterator<T>::operator=(const TArrayListIterator<T>& other)
{
	list = other.list;
	index = other.index;
	return *this;
}

template<class T>
inline bool TArrayListIterator<T>::operator==(const TArrayListIterator<T>& other)
{
	if (this->index == other.index)
		return true;
	else return false;
}

template<class T>
inline bool TArrayListIterator<T>::operator!=(const TArrayListIterator<T>& other)
{
	if (*this == other)
		return false;
	else return true;
}

template<class T>
inline T TArrayListIterator<T>::GetData()
{
	if (index < 0)
		throw logic_error("out_of_range");
	return list.data[index];
}

template<class T>
inline int TArrayListIterator<T>::GetIndex()
{
	return index;
}
