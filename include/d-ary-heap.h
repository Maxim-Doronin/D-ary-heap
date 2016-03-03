#pragma once
#include <iostream> 
#include <algorithm>

#define maxSize 1000
typedef int dataType;

class Data {
public:
	float priorities;
};

class DataValues : public Data {

};



class DAryHeap{
protected:
	dataType *keys;
	int d;
	int size;
public:
	DAryHeap(int d);
	~DAryHeap();

	void add(dataType key);
	dataType erase();
	dataType erase(int i);

	void transposition(int i, int j);
	void surfacing(int i);
	void immersion(int i);

	void spudding();

private:
	int minChild(int i);
};

