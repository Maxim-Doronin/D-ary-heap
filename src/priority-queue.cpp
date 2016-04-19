#include "priority-queue.h"

PriorityQueue::PriorityQueue(int d)
{
	heap = new DAryHeap(d);
}

PriorityQueue::PriorityQueue(const PriorityQueue &queue)
{
	this->heap = new DAryHeap(*(queue.heap));
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

Data* PriorityQueue::pop()
{
	return heap->erase(0);
}

void PriorityQueue::refresh()
{
	heap->spudding();
}

int PriorityQueue::isFull()
{
	return heap->isFull();
}

int PriorityQueue::isEmpty()
{
	return heap->isEmpty();
}

