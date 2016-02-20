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

int DAryHeap::add(dataType key)
{
	if (size >= maxSize)
		return 0;
	keys[size] = key;
	size++;
	return 1;
}

int DAryHeap::erase()
{
	if (!size)
		return 0;
	size--;
	return 1;
}

int DAryHeap::transposition(int i, int j)
{
	if ((i < 0)||(j < 0)||(i >= size)||(j >= size))
		return 0;
	dataType tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
	return 1;
}

int DAryHeap::surfacing(int i)
{
	if ((i < 0)||(i >= size))
		return 0;
	
	int p = (i - 1)/d;
	while (i > 0) {
		if (keys[p] < keys[i])
			break;
		this->transposition(p,i);
		i = p;
		p = (i - 1)/d;
	}
	return 1;
}

int DAryHeap::immersion(int i)
{
	if ((i < 0)||(i >= size))
		return 0;

	int c = minChild(i);
	while ((c != -1)&&(keys[c] < keys[i])){
		transposition(i, c);
		i = c;
		c = minChild(i);
	}
	return 1;	
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