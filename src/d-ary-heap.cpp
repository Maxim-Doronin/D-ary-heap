#include "d-ary-heap.h"

DAryHeap::DAryHeap(int d)
{
	this->d = d;
	size = 0;
	keys = new Data*[maxSize];
}

DAryHeap::~DAryHeap()
{
	delete [] keys;
}

void DAryHeap::add(Data *&key)
{
	if (isFull())
		throw "DAryHeap: No memory";
	keys[size] = key;
	size++;
	surfacing(size);
}

void DAryHeap::addSet(Data **key, int num)
{
	if (size + num >= maxSize)
		throw "DAryHeap: Too large set!";
	for (int i = size; i < size + num; i++)
	{
		keys[i] = key[i - size];
	}
	size += num;
	spudding();
}

Data* DAryHeap::erase()
{
	if (isEmpty())
		throw "DAryHeap: No data!";
	Data* key = keys[size - 1];
	size--;
	return key;
}

Data* DAryHeap::erase(int i)
{
	if (isEmpty())
		throw "DAryHeap: No data!";
	if ((i < 0)||(i >= size))
		throw "DAryHeap: Invalid index";

	Data* key = keys[i];
	transposition(i, size - 1);
	size--;
	immersion(i);
	return key;
}

void DAryHeap::transposition(int i, int j)
{
	if ((i < 0)||(j < 0)||(i >= size)||(j >= size))
		throw "DAryHeap: Invalid indexes";
	Data* tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void DAryHeap::surfacing(int i)
{
	if ((i < 0)||(i >= size))
		throw "DAryHeap: Invalid index";
	
	int p = (i - 1)/d;
	while (i > 0) {
		if (keys[p]->priorities < keys[i]->priorities)
			break;
		transposition(p,i);
		i = p;
		p = (i - 1)/d;
	}
}

void DAryHeap::immersion(int i)
{
	if ((i < 0)||(i > size))
		throw "DAryHeap: Invalid index";

	int c = minChild(i);
	while ((c != -1)&&(keys[c]->priorities < keys[i]->priorities)){
		transposition(i, c);
		i = c;
		c = minChild(i);
	}
}

void DAryHeap::spudding()
{
	for (int i = size - 1; i >= 0; i--)
		immersion(i);
}

int DAryHeap::isFull()
{
	return size >= maxSize;
}

int DAryHeap::isEmpty()
{
	return size == 0;
}

int DAryHeap::minChild(int i)
{
	int f = i*d + 1;
	if (f >= size) 
		return -1;

	int l = std::min(i*d+d, size-1);
	int c;

	Data* minKey = keys[f];
	c = f;
	for (int k = f+1; k <=l; k++){
		if (minKey->priorities > keys[k]->priorities){
			minKey = keys[k];
			c = k;
		}
	}
	return c;
}