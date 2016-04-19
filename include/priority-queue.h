#pragma once
#include "d-ary-heap.h"

class PriorityQueue {
protected:
	DAryHeap *heap;
public:
	PriorityQueue(int d = 4);
	PriorityQueue(const PriorityQueue &queue);
	PriorityQueue(Data **keys, int num, int d = 4);
	~PriorityQueue();

	void push(Data *&key);
	Data* pop();
	void refresh();

	int isFull();
	int isEmpty();
};