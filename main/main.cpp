#include <iostream>
#include <../list_lib/ArrayList.h>
#include <../list_lib/ArrayListIterator.h>
using namespace std;
int main()
{
	TArrayList<int> A(4);
	A.InsFirst(1);
	A.InsLast(2);
	A.InsLast(3);

	TArrayListIterator<int> iter(A, 1);
	A.Ins(iter, -2);

	TArrayListIterator<int> i = A.begin();
	while (i.IsGoNext())
	{
		cout << i.GetData();
		i.GoNext();
	}
	return 0;
}
