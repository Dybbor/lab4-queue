#include "pch.h"
#include "..\Queue\Queue.h"

TEST(TQueue, queue_is_empty)
{
	TQueue<int> q;
	EXPECT_EQ(true, q.IsEmpty());
}
TEST(TQueue, queue_is_not_empty)
{
	TQueue<int> q;
	q.PushLast(5);
	std::cout << " SIZE  " << q.Count() << std::endl;
	EXPECT_EQ(false, q.IsEmpty());
}
TEST(TQueue, can_pop_in_queue)
{
	TQueue<int> q;
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	ASSERT_NO_THROW(q.PopFirst());
}
TEST(TQueue, cant_pop_in_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.PopFirst());
}
TEST(TQueue, who_is_first)
{
	TQueue<int> q;
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	EXPECT_EQ(0, q.WhoIsFirst());
	q.PopFirst();
	EXPECT_EQ(1, q.WhoIsFirst());
}
TEST(TQueue, throw_WhoIsFirst_if_queue_is_empty)
{
	TQueue<int> q;
	EXPECT_ANY_THROW(q.WhoIsFirst());
}
TEST(TQueue, who_is_last)
{
	TQueue<int> q;
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	EXPECT_EQ(2, q.WhoIsLast());

}