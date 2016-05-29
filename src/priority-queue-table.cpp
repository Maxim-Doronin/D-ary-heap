#include "priority-queue.h"

PriorityQueueSortTable::PriorityQueueSortTable()
{
	table = new SortTable(500000);
}

PriorityQueueSortTable::PriorityQueueSortTable(int size)
{
	table = new SortTable(size);
}

PriorityQueueSortTable::~PriorityQueueSortTable()
{
	delete table;
}

void PriorityQueueSortTable::push(Data *&key)
{
	if (table->insert(key->priorities, key))
		throw "QueueSortTable: table is full!";
}

Data* PriorityQueueSortTable::pop()
{
	TabRecord* min = table->searchMin();
	table->pull(min->getKey());
}

int PriorityQueueSortTable::isFull()
{
	return table->isFull();
}

int PriorityQueueSortTable::isEmpty()
{
	return table->isEmpty();
}