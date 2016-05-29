#include "table.h"
#include <algorithm>
#include <vector>

SortTable::SortTable(int size) : ScanTable(size)
{
}

TabRecord* SortTable::search(float key)
{
	int start = 0;
	int end = count - 1;
	int middle;
	while (start <= end) {
		middle = (start + end) / 2;
		if (records[middle]->getKey() == key) {
			currentPosition = middle;
			return records[middle];
		}
		else if (records[middle]->getKey() > key)
			end = middle;
		else
			start = middle;
	}
	return 0;
}

int SortTable::insert(float key, void* data)
{
	if (isFull()) 
		return -1;
	int start = 0;
	int end = count - 1;
	int middle;
	while (start <= end) {
		middle = (start + end) / 2;
		if (records[middle]->getKey() == key) {
			currentPosition = middle;
			break;
		}
		else if (records[middle]->getKey() > key){
			end = middle - 1;
			currentPosition = end;
		}
		else {
			start = middle + 1;
			currentPosition = start;
		}
	}
	for (int i = count; i > currentPosition; i--)
		records[i] = records[i-1];
	delete records[currentPosition];
	records[currentPosition] = new TabRecord(key, data);
	count++;
	return 0;
}

int SortTable::remove(float key)
{
	TabRecord* killed = pull(key);
	if (!killed)
		return -1;
	delete killed;
	return 0;
}

TabRecord* SortTable::pull(float key)
{
	TabRecord* result = search(key);
	if (!result)
		return 0;
	for (int i = currentPosition; i < count - 1; i++)
		records[i] = records[i+1];
	records[count-1] = 0;
	count--;
	return result;
}