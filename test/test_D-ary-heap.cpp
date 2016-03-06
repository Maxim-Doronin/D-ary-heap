#include "gtest.h"
#include "d-ary-heap.h"

DAryHeap* createHeap()
{
	DAryHeap *heap = new DAryHeap(4);
	Data *key0 = new Data;
	Data *key1 = new Data;
	Data *key2 = new Data;
	Data *key3 = new Data;
	Data *key4 = new Data;
	Data *key5 = new Data;
	key0->priorities = 10;
	key1->priorities = 20;
	key2->priorities = 30;
	key3->priorities = 40;
	key4->priorities = 50;
	key5->priorities = 60;
	heap->add(key0);
	heap->add(key1);
	heap->add(key2);
	heap->add(key3);
	heap->add(key4);
	heap->add(key5);
	return heap;
}

TEST(D_ARY_HEAP, can_create_empty_heap)
{
	ASSERT_NO_THROW(DAryHeap *heap = new DAryHeap(4));
}

TEST(D_ARY_HEAP, throws_when_d_is_negative)
{
	ASSERT_ANY_THROW(DAryHeap *heap = new DAryHeap(-1));
}

TEST(D_ARY_HEAP, can_add_element)
{
	Data* data = new Data();
	data->priorities = 10;
	DAryHeap *heap = new DAryHeap(4);
	ASSERT_NO_THROW(heap->add(data));
}

TEST(D_ARY_HEAP, throws_when_try_add_element_to_full_heap)
{
	DAryHeap *heap = new DAryHeap(4);
	for (int i = 0; i < 1000; i++){
		Data* data = new Data();
		data->priorities = 10;
		heap->add(data);
	}
	Data* data = new Data();
	data->priorities = 10;

	ASSERT_ANY_THROW(heap->add(data));
}

TEST(D_ARY_HEAP, can_add_set_to_heap)
{
	Data** data = new Data*[10];
	for (int i = 0; i < 10; i++){
		data[i] = new Data;
		data[i]->priorities = i;
	}
	DAryHeap *heap = new DAryHeap(4);
	ASSERT_NO_THROW(heap->addSet(data, 10));
}

TEST(D_ARY_HEAP, throws_when_try_add_too_large_set)
{
	Data** data = new Data*[1005];
	for (int i = 0; i < 1005; i++){
		data[i] = new Data;
		data[i]->priorities = i;
	}
	DAryHeap *heap = new DAryHeap(4);
	ASSERT_ANY_THROW(heap->addSet(data, 1005));
}

TEST(D_ARY_HEAP, can_erase_element_from_heap)
{	
	DAryHeap *heap = createHeap();
	ASSERT_NO_THROW(heap->erase());
}

TEST(D_ARY_HEAP, erased_element_is_equal_to_added_one)
{
	DAryHeap *heap = createHeap();
	Data *erased = heap->erase();
	EXPECT_EQ(60, erased->priorities);
}

TEST(D_ARY_HEAP, throws_when_try_erase_from_empty_heap)
{
	DAryHeap *heap = new DAryHeap(4);
	ASSERT_ANY_THROW(heap->erase());
}

TEST(D_ARY_HEAP, can_erase_i_element)
{
	DAryHeap *heap = createHeap();
	Data *erased = heap->erase(1);
	EXPECT_EQ(20, erased->priorities);
}

TEST(D_ARY_HEAP, can_erase_last_element)
{
	DAryHeap *heap = createHeap();
	ASSERT_NO_THROW(heap->erase(5));
}

TEST(D_ARY_HEAP, throws_when_try_erase_large_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->erase(50));
}

TEST(D_ARY_HEAP, throws_when_try_erase_negative_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->erase(-5));
}

TEST(D_ARY_HEAP, can_transp_elements)
{
	DAryHeap *heap = createHeap();
	ASSERT_NO_THROW(heap->transposition(1,3));	
}

TEST(D_ARY_HEAP, throws_when_transp_invalid_idx)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->transposition(-1, 10));
}

TEST(D_ARY_HEAP, transposition_is_correct)
{
	DAryHeap *heap = createHeap();
	heap->transposition(1,4);
	Data* key1 = heap->erase(1);
	Data* key4 = heap->erase(4);
	EXPECT_EQ(key1->priorities, 50);
	EXPECT_EQ(key4->priorities, 20);
}

TEST(D_ARY_HEAP, can_surfacing)
{
	DAryHeap *heap = createHeap();
	ASSERT_NO_THROW(heap->surfacing(3));
}

TEST(D_ARY_HEAP, surfacing_min_element)
{
	DAryHeap *heap = createHeap();
	heap->surfacing(5);
	EXPECT_EQ(heap->erase(0)->priorities, 10);
}

TEST(D_ARY_HEAP, throws_when_surfacing_large_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->surfacing(10));
}

TEST(D_ARY_HEAP, throws_when_surfacing_negative_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->surfacing(-10));
}

TEST(D_ARY_HEAP, can_immersion)
{
	DAryHeap *heap = createHeap();
	heap->transposition(1, 5);
	ASSERT_NO_THROW(heap->immersion(1));
}

TEST(D_ARY_HEAP, immersion_is_correct)
{
	DAryHeap *heap = createHeap();
	heap->transposition(1, 5);
	heap->immersion(1);
	EXPECT_EQ(heap->erase(5)->priorities, 60);
}

TEST(D_ARY_HEAP, throws_when_immersion_large_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->immersion(10));
}

TEST(D_ARY_HEAP, throws_when_immersion_negative_i)
{
	DAryHeap *heap = createHeap();
	ASSERT_ANY_THROW(heap->immersion(-10));
}

TEST(D_ARY_HEAP, isFull_when_heap_is_full)
{
	DAryHeap *heap = new DAryHeap(4);
	for (int i = 0; i < 1000; i++){
		Data* data = new Data();
		data->priorities = 10;
		heap->add(data);
	}
	ASSERT_TRUE(heap->isFull());
}

TEST(D_ARY_HEAP, isFull_when_heap_is_not_full)
{
	DAryHeap *heap = createHeap();
	ASSERT_FALSE(heap->isFull());
}

TEST(D_ARY_HEAP, isEmpty_when_heap_is_empty)
{
	DAryHeap *heap = new DAryHeap(4);
	ASSERT_TRUE(heap->isEmpty());
}

TEST(D_ARY_HEAP, isEmpty_after_erasing)
{
	DAryHeap *heap = new DAryHeap(4);
	Data* key = new Data;
	key->priorities = 10;
	heap->add(key);
	heap->erase();
	ASSERT_TRUE(heap->isEmpty());
}

TEST(D_ARY_HEAP, isEmpty_when_heap_is_not_empty)
{
	DAryHeap *heap = createHeap();
	ASSERT_FALSE(heap->isEmpty());
}