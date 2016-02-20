#include "priority-queue.h"

void PriorityQueue::push(dataType key)
{
	if (!add(key))
		return;
	surfacing(size - 1);
}

void PriorityQueue::pop(int i)
{
	if (!transposition(i, size - 1))
		return;
	if (!erase())
		return;
	immersion(i);
}