#pragma once
#include "d-ary-heap.h"

class PriorityQueue : protected DAryHeap {
public:
	PriorityQueue(int d):DAryHeap(d){};
	virtual ~PriorityQueue(){};

	void push(dataType key);
	void pop(int i);
};