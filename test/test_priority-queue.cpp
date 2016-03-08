#include "gtest.h"
#include "priority-queue.h"

Data** createData()
{
	Data **data = new Data*[10];
	for (int i = 0; i < 10; i++){
		data[i] = new Data;
		data[i]->priorities = 10 - i;
	}
	return data;
}

TEST(PRIORITY_QUEUE, can_create_empty_queue)
{
	ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue());
}

TEST(PRIORITY_QUEUE, can_create_empty_queue_with_fixed_d)
{
	ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue(6));
}

TEST(PRIORITY_QUEUE, can_create_copied_queue)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	ASSERT_NO_THROW(PriorityQueue *nq = new PriorityQueue (*q));
}

TEST(PRIORITY_QUEUE, copied_queue_is_equal_to_sourse_one)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	PriorityQueue *nq = new PriorityQueue (*q);
	EXPECT_EQ(q->pop()->priorities, nq->pop()->priorities);
}

TEST(PRIORITY_QUEUE, copied_queue_has_its_own_memory)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	PriorityQueue *nq = new PriorityQueue (*q);
	nq->pop();
	EXPECT_NE(q->pop()->priorities, nq->pop()->priorities);
}

TEST(PRIORITY_QUEUE, can_create_queue_from_data_array)
{
	Data **data = createData();
	ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue(data, 10));
}

TEST(PRIORITY_QUEUE, can_push_new_element)
{
	PriorityQueue *q = new PriorityQueue();
	Data *key = new Data;
	key->priorities = 2;
	ASSERT_NO_THROW(q->push(key));
}

TEST(PRIORITY_QUEUE, can_pop_element)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	ASSERT_NO_THROW(q->pop());
}

TEST(PRIORITY_QUEUE, poped_element_is_equal_to_pushed_one)
{
	PriorityQueue *q = new PriorityQueue();
	Data *key = new Data;
	key->priorities = 2;
	q->push(key);
	Data *poped = q->pop();
	EXPECT_EQ(poped->priorities, key->priorities);
}

TEST(PRIORITY_QUEUE, queue_created_by_array_is_priority)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	EXPECT_EQ(q->pop()->priorities, 1);
}

TEST(PRIORITY_QUEUE, pushed_element_doesnt_crash_priority)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	Data *key = new Data;
	key->priorities = 1.5;
	q->push(key);
	q->pop();		//extract first element with priority = 1;
	EXPECT_EQ(q->pop()->priorities, 1.5);
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_empty)
{
	PriorityQueue *q = new PriorityQueue();
	ASSERT_TRUE(q->isEmpty());
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_not_empty)
{
	PriorityQueue *q = new PriorityQueue();
	Data* key = new Data();
	key->priorities = 1;
	q->push(key);
	ASSERT_FALSE(q->isEmpty());
}

TEST(PRIORITY_QUEUE, isEmpty_after_pop)
{
	PriorityQueue *q = new PriorityQueue();
	Data* key = new Data();
	key->priorities = 1;
	q->push(key);
	q->pop();
	ASSERT_TRUE(q->isEmpty());
}

TEST(PRIORITY_QUEUE, isFull_when_queue_is_full)
{
	Data **data = new Data*[maxSize];
	for (int i = 0; i < maxSize; i++){
		data[i] = new Data;
		data[i]->priorities = maxSize - i;
	}
	PriorityQueue *q = new PriorityQueue(data, maxSize);
	ASSERT_TRUE(q->isFull());
}

TEST(PRIORITY_QUEUE, isFull_when_queue_is_not_full)
{
	Data **data = createData();
	PriorityQueue *q = new PriorityQueue(data, 10);
	ASSERT_FALSE(q->isFull());
}

TEST(PRIORITY_QUEUE, throws_when_try_pop_from_empty_queue)
{
	PriorityQueue *q = new PriorityQueue();
	ASSERT_ANY_THROW(q->pop());
}

TEST(PRIORITY_QUEUE, throws_when_try_push_to_full_queue)
{
	Data **data = new Data*[maxSize];
	for (int i = 0; i < maxSize; i++){
		data[i] = new Data;
		data[i]->priorities = maxSize - i;
	}
	PriorityQueue *q = new PriorityQueue(data, maxSize);
	Data* key = new Data();
	key->priorities = 1;
	ASSERT_ANY_THROW(q->push(key));
}

