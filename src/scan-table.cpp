#include "table.h"

ScanTable::ScanTable(int size) : Table(size)
{
	records = new TabRecord*[size];
	for (int i = 0; i < size; i++)
		records[i] = 0;
}

ScanTable::~ScanTable()
{
	for (int i = 0; i < count; i++)
		delete records[i];
	delete []records;
}

TabRecord* ScanTable::search(float key)
{
	for (int i = 0; i < count; i++)
		if (records[i]->getKey() == key){
			currentPosition = i;
			return records[i];
		}
	return 0;
}

int ScanTable::insert(float key, void* data)
{
	if (isFull()) 
		return -1;
	records[count++] = new TabRecord(key, data);
	return 0;
}

int ScanTable::remove(float key)
{
	TabRecord* killed = pull(key);
	if (!killed)
		return -1;
	delete killed;
	return 0;
}

TabRecord* ScanTable::pull(float key)
{
	if(!search(key)) 
		return 0;
	TabRecord* result =  records[currentPosition];
	records[currentPosition] = records[count - 1];
	count--;
	return result;
}

TabRecord* ScanTable::searchMin()
{
	if (isEmpty())
		return 0;
	TabRecord* min = records[0];
	for (int i = 0; i < count; i++)
		if (records[i]->getKey() < min->getKey())
			min = records[i];
	return min;
}

TabRecord* ScanTable::searchMax()
{
	if (isEmpty())
		return 0;
	TabRecord* max = records[0];
	for (int i = 0; i < count; i++)
		if (records[i]->getKey() > max->getKey())
			max = records[i];
	return max;
}

float ScanTable::getKey() const
{
	return records[currentPosition]->getKey();
}

void* ScanTable::getData() const
{
	return records[currentPosition]->getData();
}