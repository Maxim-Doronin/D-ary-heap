#pragma once
#include "d-ary-heap.h"

class SharedSet {
private:
	int *parent;
	int *height;
	int n;
	bool validIndex(int i);
public:
	SharedSet(int n);
	~SharedSet();

	void singleton(int i);
	void association(int i, int j);
	int defineSet(int i);
};