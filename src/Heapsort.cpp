#include "Heapsort.h"

DataInt::DataInt(int elem)
{
	this->priorities = float(elem);
}

void Heapsort::heapsort(int *&arr, int n, int d = 4)
{
	Data** data = new Data*[n];
	for (int i = 0; i < n; i++)
		data[i] = new DataInt(arr[i]);
	DAryHeap* heap = new DAryHeap(d);
	heap->addSet(data, n);

	for (int i = n-1; i >= 0; --i)
	{
		heap->transposition(0, i);
		arr[i] = (int)heap->erase()->priorities;
		heap->immersion(0);	
	}
	delete heap;
	for (int i = 0; i < n; i++)
		delete data[i];
	delete []data;
}