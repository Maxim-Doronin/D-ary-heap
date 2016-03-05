#pragma once
#include <iostream> 
#include <algorithm>
#include "graphs.h"

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};

class DataValues : public Data {
public:	
	DataValues(Edge *edge);
	Edge *edge;
};


class DAryHeap{
protected:
	Data **keys;
	int d;
	int size;			//current size of heap
public:
	DAryHeap(int d);
	~DAryHeap();

	void add(Data *&key);
	void addSet(Data **key, int num);
	Data* erase();
	Data* erase(int i);

	void transposition(int i, int j);
	void surfacing(int i);
	void immersion(int i);

	void spudding();

	int isFull();
	int isEmpty();

private:
	int minChild(int i);
};

