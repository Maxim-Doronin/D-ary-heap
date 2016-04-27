#include "Heapsort.h"

DataInt::DataInt(int elem)
{
	this->priorities = float(elem);
}

void Heapsort::heapsort(float *&arr, int n, int d)
{
	if (n == 0)
		return;
	if (n < 0)
		throw "Heapsort: invalid n!";
	Data** data = new Data*[n];
	for (int i = 0; i < n; i++) {
		data[i] = new Data;
		data[i]->priorities = arr[i];
	}
	DAryHeap* heap = new DAryHeap(d);
	heap->addSet(data, n);

	for (int i = n-1; i > 0; --i)
	{
		heap->transposition(0, i);
		arr[i] = heap->erase()->priorities;
		heap->immersion(0);	
	}
	arr[0] = heap->erase()->priorities;
	delete heap;
	for (int i = 0; i < n; i++)
		delete data[i];
	delete []data;
}