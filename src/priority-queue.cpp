#include "priority-queue.h"

PriorityQueue::PriorityQueue(int d)
{
	heap = new DAryHeap(d);
}

PriorityQueue::PriorityQueue(Data **keys, int num, int d)
{
	heap = new DAryHeap(d);
	heap->addSet(keys, num);
}

PriorityQueue::~PriorityQueue()
{
	delete heap;
}

void PriorityQueue::push(Data *&key)
{
	heap->add(key);
}

Data* PriorityQueue::pop(int i)
{
	return heap->erase(i);
}

Data* PriorityQueue::popMin()
{
	return heap->erase(0);
}

int PriorityQueue::isFull()
{
	return heap->isFull();
}

int PriorityQueue::isEmpty()
{
	return heap->isEmpty();
}

