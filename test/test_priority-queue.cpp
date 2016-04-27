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
	ASSERT_NO_THROW(PriorityQueueHeap *q = new PriorityQueueHeap());
}

TEST(PRIORITY_QUEUE, can_create_empty_queue_with_fixed_d)
{
	ASSERT_NO_THROW(PriorityQueueHeap *q = new PriorityQueueHeap(6));
}

TEST(PRIORITY_QUEUE, can_create_copied_queue)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	ASSERT_NO_THROW(PriorityQueueHeap *nq = new PriorityQueueHeap (*q));
}

TEST(PRIORITY_QUEUE, copied_queue_is_equal_to_sourse_one)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	PriorityQueueHeap *nq = new PriorityQueueHeap (*q);
	EXPECT_EQ(q->pop()->priorities, nq->pop()->priorities);
}

TEST(PRIORITY_QUEUE, copied_queue_has_its_own_memory)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	PriorityQueueHeap *nq = new PriorityQueueHeap (*q);
	nq->pop();
	EXPECT_NE(q->pop()->priorities, nq->pop()->priorities);
}

TEST(PRIORITY_QUEUE, can_create_queue_from_data_array)
{
	Data **data = createData();
	ASSERT_NO_THROW(PriorityQueueHeap *q = new PriorityQueueHeap(data, 10));
}

TEST(PRIORITY_QUEUE, can_push_new_element)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
	Data *key = new Data;
	key->priorities = 2;
	ASSERT_NO_THROW(q->push(key));
}

TEST(PRIORITY_QUEUE, can_pop_element)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	ASSERT_NO_THROW(q->pop());
}

TEST(PRIORITY_QUEUE, poped_element_is_equal_to_pushed_one)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
	Data *key = new Data;
	key->priorities = 2;
	q->push(key);
	Data *poped = q->pop();
	EXPECT_EQ(poped->priorities, key->priorities);
}

TEST(PRIORITY_QUEUE, queue_created_by_array_is_priority)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	EXPECT_EQ(q->pop()->priorities, 1);
}

TEST(PRIORITY_QUEUE, pushed_element_doesnt_crash_priority)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	Data *key = new Data;
	key->priorities = 1.5;
	q->push(key);
	q->pop();		//extract first element with priority = 1;
	EXPECT_EQ(q->pop()->priorities, 1.5);
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_empty)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
	ASSERT_TRUE(q->isEmpty());
}

TEST(PRIORITY_QUEUE, isEmpty_when_queue_is_not_empty)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
	Data* key = new Data();
	key->priorities = 1;
	q->push(key);
	ASSERT_FALSE(q->isEmpty());
}

TEST(PRIORITY_QUEUE, isEmpty_after_pop)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
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
	PriorityQueueHeap *q = new PriorityQueueHeap(data, maxSize);
	ASSERT_TRUE(q->isFull());
}

TEST(PRIORITY_QUEUE, isFull_when_queue_is_not_full)
{
	Data **data = createData();
	PriorityQueueHeap *q = new PriorityQueueHeap(data, 10);
	ASSERT_FALSE(q->isFull());
}

TEST(PRIORITY_QUEUE, throws_when_try_pop_from_empty_queue)
{
	PriorityQueueHeap *q = new PriorityQueueHeap();
	ASSERT_ANY_THROW(q->pop());
}

TEST(PRIORITY_QUEUE, throws_when_try_push_to_full_queue)
{
	Data **data = new Data*[maxSize];
	for (int i = 0; i < maxSize; i++){
		data[i] = new Data;
		data[i]->priorities = maxSize - i;
	}
	PriorityQueueHeap *q = new PriorityQueueHeap(data, maxSize);
	Data* key = new Data();
	key->priorities = 1;
	ASSERT_ANY_THROW(q->push(key));
}

