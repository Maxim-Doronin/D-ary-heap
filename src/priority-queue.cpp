#include "priority-queue.h"

PriorityQueue::PriorityQueue(int d)
{
	heap = new DAryHeap(d);
}

PriorityQueue::~PriorityQueue()
{
	delete heap;
}

void PriorityQueue::push(dataType key)
{
	heap->add(key);
}

dataType PriorityQueue::pop(int i)
{
	return heap->erase(i);
}

dataType PriorityQueue::popMin()
{
	return heap->erase(0);
}