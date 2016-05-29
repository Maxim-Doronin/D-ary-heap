#pragma once
#include "d-ary-heap.h"

class DataInt : public Data {
public:	
	DataInt(int elem);
};

class Heapsort {
public:
	static void heapsort(float *&arr, int n, int d = 4);
};