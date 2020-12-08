#include <../gtest/gtest.h>
#include <../list_lib/ArrayList.h>
#include <../list_lib/ArrayListIterator.h>

TEST(array_list, can_create_array_list)
{
	ASSERT_NO_THROW(TArrayList<int> A(3));
}

TEST(array_list, can_get_count)
{
	TArrayList<int> A(3);
	EXPECT_EQ(0, A.GetCount());
}

TEST(array_list, can_ins_first)
{
	TArrayList<int> A(3);
	ASSERT_NO_THROW(A.InsFirst(1));
	ASSERT_NO_THROW(A.InsFirst(2));

	EXPECT_EQ(2, A.GetFirst());
	EXPECT_EQ(1, A.GetLast());
}

TEST(array_list, can_ins_last)
{
	TArrayList<int> A(3);
	ASSERT_NO_THROW(A.InsLast(1));
	ASSERT_NO_THROW(A.InsLast(2));

	EXPECT_EQ(1, A.GetFirst());
	EXPECT_EQ(2, A.GetLast());
}

TEST(array_list, can_copy_array_list)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayList<int> B(A);
	EXPECT_EQ(0, B.GetFirst());
	EXPECT_EQ(2, B.GetLast());
}

TEST(array_list, can_delete_first)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_NO_THROW(A.DelFirst());
	EXPECT_EQ(2, A.GetCount());
	EXPECT_EQ(1, A.GetFirst());
	EXPECT_EQ(2, A.GetLast());
}

TEST(array_list, can_delete_last)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_NO_THROW(A.DelLast());
	EXPECT_EQ(2, A.GetCount());
	EXPECT_EQ(0, A.GetFirst());
	EXPECT_EQ(1, A.GetLast());
}

TEST(array_list, use_operator_equal)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayList<int> B = A;
	EXPECT_EQ(A.GetCount(), B.GetCount());
	EXPECT_EQ(A.GetFirst(), B.GetFirst());
	EXPECT_EQ(A.GetLast(), B.GetLast());
	B.DelLast();
	A.DelLast();
	EXPECT_EQ(A.GetLast(), B.GetLast());
}

TEST(array_list, can_not_add_in_full_list)
{
	TArrayList<int> A(3);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	ASSERT_ANY_THROW(A.InsFirst(2));
	ASSERT_ANY_THROW(A.InsLast(2));
}

TEST(array_list, can_not_del_from_empty_list)
{
	TArrayList<int> A(3);

	ASSERT_ANY_THROW(A.DelFirst());
	ASSERT_ANY_THROW(A.DelLast());
}

TEST(array_list, ins_with_iterator)
{
	TArrayList<int> A(4);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);

	TArrayListIterator<int> iter(A, 1);
	A.Ins(iter, -2);

	EXPECT_EQ(4, A.GetCount());
	EXPECT_EQ(0, A.GetFirst());
	EXPECT_EQ(2, A.GetLast());
	A.DelFirst();
	A.DelLast();
	EXPECT_EQ(1, A.GetFirst());
	EXPECT_EQ(-2, A.GetLast());
}

TEST(array_list, del_with_iterator)
{
	TArrayList<int> A(4);
	A.InsLast(2);
	A.InsFirst(1);
	A.InsFirst(0);
	A.InsLast(3);
	
	TArrayListIterator<int> iter(A, 1);
	A.Del(iter);

	EXPECT_EQ(3, A.GetCount());
	EXPECT_EQ(0, A.GetFirst());
	EXPECT_EQ(3, A.GetLast());
	A.DelFirst();
	EXPECT_EQ(1, A.GetFirst());
}

TEST(array_list, use_prime_numbers)
{
	TArrayList<int> A(6);
	A.InsLast(2);
	A.InsLast(1);
	A.InsLast(6);
	A.InsLast(3);
	A.InsLast(4);
	A.InsLast(-4);

	TArrayList<int> B = A.prime_numbers(7);

	EXPECT_EQ(3, B.GetCount());
	EXPECT_EQ(2, B.GetFirst());
	B.DelFirst();
	EXPECT_EQ(1, B.GetFirst());
	B.DelFirst();
	EXPECT_EQ(3, B.GetFirst());
}

TEST(array_list, use_reverse)
{
	TArrayList<int> A(6);
	A.InsLast(1);
	A.InsLast(2);
	A.InsLast(3);

	A.reverse();
	EXPECT_EQ(3, A.GetFirst());
	A.DelFirst();
	EXPECT_EQ(2, A.GetFirst());
	A.DelFirst();
	EXPECT_EQ(1, A.GetFirst());
}