#include "d-ary-heap.h"

DAryHeap::DAryHeap(int d)
{
	this->d = d;
	size = 0;
	keys = new dataType[maxSize];
}

DAryHeap::~DAryHeap()
{
	delete [] keys;
}

void DAryHeap::add(dataType key)
{
	if (size >= maxSize)
		throw "No memory";
	keys[size] = key;
	size++;
	surfacing(size);
}

dataType DAryHeap::erase()
{
	if (!size)
		throw "Invalid index";
	dataType key = keys[size - 1];
	size--;
	return key;
}

dataType DAryHeap::erase(int i)
{
	if (!size)
		throw "No data";
	if ((i < 0)||(i >= size))
		throw "Invalid index";

	dataType key = keys[i];
	transposition(i, size - 1);
	size--;
	immersion(i);
	return key;
}

void DAryHeap::transposition(int i, int j)
{
	if ((i < 0)||(j < 0)||(i >= size)||(j >= size))
		throw "Invalid indexes";
	dataType tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void DAryHeap::surfacing(int i)
{
	if ((i < 0)||(i >= size))
		throw "Invalid index";
	
	int p = (i - 1)/d;
	while (i > 0) {
		if (keys[p] < keys[i])
			break;
		transposition(p,i);
		i = p;
		p = (i - 1)/d;
	}
}

void DAryHeap::immersion(int i)
{
	if ((i < 0)||(i >= size))
		throw "Invalid index";

	int c = minChild(i);
	while ((c != -1)&&(keys[c] < keys[i])){
		transposition(i, c);
		i = c;
		c = minChild(i);
	}
}

int DAryHeap::spudding()
{
	for (int i = size - 1; i >= 0; i--)
		immersion(i);
}

int DAryHeap::minChild(int i)
{
	int f = i*d + 1;
	if (f >= size) 
		return -1;

	int l = std::min(i*d+d, size-1);
	int c;

	dataType minKey = keys[f];
	for (int k = f+1; k <=l; k++){
		if (minKey > keys[k]){
			minKey = keys[k];
			c = k;
		}
	}
	return c;
}