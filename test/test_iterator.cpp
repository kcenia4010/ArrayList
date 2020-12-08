#include <../gtest/gtest.h>
#include <../list_lib/ArrayList.h>
#include <../list_lib/ArrayListIterator.h>

TEST(array_list_iterator, is_go_next)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> i = A.begin();

	EXPECT_TRUE(i.IsGoNext());
}

TEST(array_list_iterator, get_data)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> i = A.end();
	EXPECT_EQ(2, i.GetData());

	TArrayListIterator<int> j = A.begin();
	EXPECT_EQ(0, j.GetData());
}

TEST(array_list_iterator, go_next)
{
	TArrayList<int> A(4);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> i = A.begin();
	int k = 0;
	while (i.IsGoNext())
	{
		k++;
		ASSERT_NO_THROW(i.GoNext());
	}
	EXPECT_EQ(k, 3);
}

TEST(array_list_iterator, use_operator_comparison_1)
{
	TArrayList<int> A(4);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> iter(A, 1);
	TArrayListIterator<int> i = A.begin();
	int k = 0;
	while (i.IsGoNext())
	{
		if (i == iter)
			break;
		k++;
		i.GoNext();
	}
	EXPECT_EQ(k, 1);
}

TEST(array_list_iterator, use_operator_comparison_2)
{
	TArrayList<int> A(4);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> iter(A, 1);
	TArrayListIterator<int> i = A.begin();
	
	int k = 0;
	while (i.IsGoNext())
	{
		if (i != iter)
			k++;
		i.GoNext();
	}
	EXPECT_EQ(k, 2);
}

