#include "table.h"

TabRecord::TabRecord(float key, void *&data)
{
	this->key = key;
	this->data = data;
}

float TabRecord::getKey() const 
{
	return this->key;
}

void* TabRecord::getData() const
{
	return this->data;
}

Table::Table(int size)
{
	this->size = size;
	this->count = 0;
	this->currentPosition = 0;
}

int Table::isEmpty() const
{
	return count == 0;
}

int Table::isFull() const
{
	return count >= size;
}

int Table::getDataCount() const
{
	return count;
}

int Table::reset() 
{
	currentPosition = 0;
	return isTableEnded();
}

int Table::getNext()
{
	if (!isTableEnded())
		currentPosition++;
	return isTableEnded();
}

int Table::isTableEnded()
{
	return count >= size;
}