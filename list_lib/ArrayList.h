#pragma once
#include <iostream>
using namespace std;

template <class T>
class TArrayListIterator;

template <class T>
class TArrayList
{
private:
	T* data;
	T* links;
	int size;
	int count;
	int root;
public:
	TArrayList(int _size);
	TArrayList(TArrayList<T>& other);
	~TArrayList();

	TArrayList<T>& operator = (TArrayList<T>& other);

	void InsFirst(T d);
	void InsLast(T d);
	void Ins(TArrayListIterator<T>& i, T d);
	
	bool IsFull();
	bool IsEmpty();

	void DelFirst();
	void DelLast();
	void Del(TArrayListIterator<T>& i);

	int GetCount();
	T GetFirst();
	T GetLast();

	TArrayListIterator<T> begin();
	TArrayListIterator<T> end();

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TArrayList<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TArrayList<T1>& A);

	template <class T>
	friend class TArrayListIterator;
};

template<class T>
inline TArrayList<T>::TArrayList(int _size)
{
	if (_size <= 0)
		throw logic_error("invalid_argument");
	size = _size;
	data = new T[size];
	links = new int[size];
	count = 0;
	root = -1;
	for (int i = 0; i < size; i++)
		links[i] = -2;
}

template<class T>
inline TArrayList<T>::TArrayList(TArrayList<T>& other)
{
	count = other.count;
	size = other.size;
	root = other.root;

	data = new T[size];
	links = new int[size];

	for (int i = 0; i < size; i++)
	{
		links[i] = other.links[i];
		data[i] = other.data[i];
	}
}

template<class T>
inline TArrayList<T>::~TArrayList()
{
	if (data != 0)
	{
		delete[] data;
		delete[] links;
		data = NULL;
		links = NULL;
		size = 0;
		count = 0;
		root = -1;
	}
}

template<class T>
inline TArrayList<T>& TArrayList<T>::operator=(TArrayList<T>& other)
{
	count = other.count;
	size = other.size;
	root = other.root;

	if (data != 0)
	{
		delete[] data;
		delete[] links;
	}

	data = new T[size];
	links = new int[size];

	for (int i = 0; i < size; i++)
	{
		links[i] = other.links[i];
		data[i] = other.data[i];
	}
	return *this;
}

template<class T>
inline void TArrayList<T>::InsFirst(T d)
{
	if (this->IsFull()) 
		throw logic_error("out_of_range");;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (links[i] == -2)
			break;
	}
	data[i] = d;
	links[i] = root;
	root = i;
	count++;
}

template<class T>
inline void TArrayList<T>::InsLast(T d)
{
	if (this->IsFull()) 
		throw logic_error("out_of_range");
	if (this->IsEmpty()) 
	{
		root = 0;
		data[0] = d;
		links[0] = -1;
	}
	else
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			if (links[i] == -2)
				break;
		}

		int end = root;
		while (links[end] != -1)
			end = links[end];

		data[i] = d;
		links[i] = -1;
		links[end] = i;
	}
	count++;
}

template<class T>
inline void TArrayList<T>::Ins(TArrayListIterator<T>& iter, T d)
{
	if (this->IsFull())
		throw logic_error("out_of_range");
	if (this->IsEmpty())
	{
		root = 0;
		data[0] = d;
		links[0] = -1;
	}
	else
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			if (links[i] == -2)
				break;
		}

		data[i] = d;
		int j = iter.GetIndex();
	
		if (iter.IsGoNext())
		{
			iter.GoNext();
			links[i] = iter.GetIndex();
		}
		else links[i] = -1;
		links[j] = i;
	}
	count++;
}

template<class T>
inline bool TArrayList<T>::IsFull()
{
	return count == size;
}

template<class T>
inline bool TArrayList<T>::IsEmpty()
{
	return count == 0;
}

template<class T>
inline void TArrayList<T>::DelFirst()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	int i = root;
	root = links[root];
	links[i] = -2;
	count--;
}

template<class T>
inline void TArrayList<T>::DelLast()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	
	if (links[root] == -1)
	{
		links[root] = -2;
		root = -1;
	}
	else
	{
		int pEnd = root;
		int end = links[root];

		while (links[end] != -1)
		{
			pEnd = end;
			end = links[end];
		}
		links[pEnd] = -1;
		links[end] = -2;
	}
	count--;
}

template<class T>
inline void TArrayList<T>::Del(TArrayListIterator<T>& iter)
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	if (links[root] == -1)
	{
		links[root] = -2;
		root = -1;
	}
	else
	{
		int j = iter.GetIndex();

		if (iter.IsGoNext())
		{
			iter.GoNext();
			links[j] = iter.GetIndex();
		}
		else links[j] = - 1;
	}
	count--;
}

template<class T>
inline int TArrayList<T>::GetCount()
{
	return count;
}

template<class T>
inline T TArrayList<T>::GetFirst()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	return data[root];
}

template<class T>
inline T TArrayList<T>::GetLast()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	
	int end = root;
	while (links[end] != -1)
		end = links[end];

	return data[end];
}

template<class T>
inline TArrayListIterator<T> TArrayList<T>::begin()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	return TArrayListIterator<T>(*this, root);
}

template<class T>
inline TArrayListIterator<T> TArrayList<T>::end()
{
	if (this->IsEmpty())
		throw logic_error("out_of_range");
	int end = root;
	while (links[end] != -1)
		end = links[end];
	return TArrayListIterator<T>(*this, end);
}


template<class T1>
inline ostream& operator<<(ostream& ostr, const TArrayList<T1>& A)
{
	int i = A.root;
	while (A.links[i] != -1)
	{
		ostr << A.data[i];
		i = A.links[i];
	}
	return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TArrayList<T1>& A)
{
	int count;
	istr >> count;
	for (int i = 0; i < count; i++)
	{
		T1 d;
		istr >> d;
		A.InsLast(d);
	}
	return istr;
}


