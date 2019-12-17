#include"../Project15/queue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, can_not_create_queue_with_negativ_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}
TEST(TQueue, can_create_copy_queue)
{
	TQueue<int> q1(3);
	for (int i = 0; i < q1.GetMaxSize(); i++)
		q1.Push(i);
	TQueue<int> q(q1);

	for(int i=0;i<q.GetMaxSize();i++)
	{
		EXPECT_EQ(i, q.Pop());
	}
}
TEST(TQueue, can_put_el)
{
	TQueue<int> q(3);
	int el = 3;
	ASSERT_NO_THROW(q.Push(el));
}
TEST(TQueue, can_get_elem)
{
	TQueue<int> q(3);
	int el = 3;
	ASSERT_NO_THROW(q.Push(el));
	EXPECT_EQ(3, q.Pop());
}
TEST(TQueue, can_not_get_elem)
{
	TQueue<int> q(3);
	ASSERT_ANY_THROW(q.Pop());
}
TEST(TQueue, can_not_put_elem)
{
	TQueue<int> q(3);
	int el = 3;
	for (int i = 0; i < q.GetMaxSize(); i++)
		q.Push(el);
	ASSERT_ANY_THROW(q.Push(el));
}
TEST(TQueue, expect_eq)
{
	TQueue<int> q(3);
	for (int i = 0; i < q.GetMaxSize(); i++)
		q.Push(i);
	TQueue<int>q2;
	ASSERT_NO_THROW(q2 = q);
	EXPECT_EQ(3, q2.GetMaxSize());
	for (int i = 0; i < q.GetMaxSize(); i++)
		EXPECT_EQ(i, q2.Pop());
}
TEST(TQueue, assert_true_is_empty)
{
	TQueue<int> q(3);
	EXPECT_EQ(1, q.IsEmpty());
}
TEST(TQueue, assert_false_is_empty)
{
	TQueue<int> q(3);
	int el = 3;
	q.Push(el);
	EXPECT_EQ(0, q.IsEmpty());
}
TEST(TQueue, assert_true_is_full)
{
	TQueue<int> q(3);
	for (int i = 0; i < q.GetMaxSize(); i++)
		q.Push(i);
	EXPECT_EQ(1, q.IsFull());
}
TEST(TQueue, assert_false_is_full)
{
	TQueue<int> q(3);
	for (int i = 0; i < q.GetMaxSize()-1; i++)
		q.Push(i);
	EXPECT_EQ(0, q.IsFull());
}
TEST(TQueue, can_get_first_elem)
{
	TQueue<int> q(3);
	for (int i = 0; i < q.GetMaxSize(); i++)
		q.Push(i);
	EXPECT_EQ(0, q.Front());
}
TEST(TQueue, can_get_last_elem)
{
	TQueue<int> q(3);
	for (int i = 0; i < q.GetMaxSize(); i++)
		q.Push(i);
	EXPECT_EQ(2, q.Back());
}
TEST(TQueue, can_not_get_first_elem)
{
	TQueue<int> q(3);
	ASSERT_ANY_THROW(q.Front());
}
TEST(TQueue, can_not_get_last_elem)
{
	TQueue<int> q(3);
	ASSERT_ANY_THROW( q.Back());
}