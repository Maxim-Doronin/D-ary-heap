#pragma once
#include "d-ary-heap.h"

class PriorityQueue {
private:
	DAryHeap *heap;
public:
	PriorityQueue(int d);
	~PriorityQueue();

	void push(dataType key);
	dataType pop(int i);
	dataType popMin();
};