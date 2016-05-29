#include "table.h"

ScanTable::ScanTable(int size) : Table(size)
{
	records = new TabRecord*[size];
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