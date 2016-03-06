#pragma once
#include "d-ary-heap.h"

class PriorityQueue {
private:
	DAryHeap *heap;
public:
	PriorityQueue(int d = 4);
	PriorityQueue(Data **keys, int num, int d = 4);
	~PriorityQueue();

	void push(Data *&key);
	Data* pop(int i);
	Data* pop();

	int isFull();
	int isEmpty();
};