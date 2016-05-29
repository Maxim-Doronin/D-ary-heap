#include "table.h"
#include <iostream>
using namespace std;
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
			end = middle - 1;
		else
			start = middle + 1;
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
			currentPosition = middle;
		}
		else {
			start = middle + 1;
			currentPosition = start;
		}
	}
	for (int i = count; i > currentPosition; i--)
		records[i] = records[i-1];
	records[currentPosition] = new TabRecord(key, data);
	count++;
	for (int i = 0; i < count; i++)
		cout << records[i]->getKey() << ' ';
	cout << endl;
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

TabRecord* SortTable::searchMin()
{
	if (isEmpty())
		return 0;
	return records[0];
}

TabRecord* SortTable::searchMax()
{
	if (isEmpty())
		return 0;
	return records[count - 1];
}