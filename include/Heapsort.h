#pragma once
#include "d-ary-heap.h"

class DataInt : public Data {
public:	
	DataInt(int elem);
};

class Heapsort {
public:
	static void heapsort(int *&arr, int n, int d);
};