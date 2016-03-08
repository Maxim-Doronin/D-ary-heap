#include "separated-set.h"

SeparatedSet::SeparatedSet(int n)
{
	if (n < 0)
		throw "SeparatedSet: Invalid size!";
	parent = new int [n];
	for (int i = 0; i < n; i++)
		parent[i] = -1;
	height = new int [n];
	this->n = n;
}

SeparatedSet::~SeparatedSet()
{
	delete [] parent;
	delete [] height;
}

bool SeparatedSet::validIndex(int i)
{
	if ((i < 0) || (i >= n))
		return false;
	else
		return true;
}

void SeparatedSet::singleton(int i)
{
	if (!validIndex(i))
		throw "SeparatedSet: Invalid Index!";
	if (parent[i] != -1)
		return;
	parent[i] = i;
	height[i] = 0;
}

void SeparatedSet::association(int i, int j)
{
	if ((!validIndex(i)) || (!validIndex(j)))
		throw "SeparatedSet: Invalid Indexes!";
	if ((parent[i] == -1)||(parent[j] == -1))
		throw "SeparatedSet: Empty set!";
	if (parent[i] != i)
		i = defineSet(i);
	if (parent[j] != i)
		j = defineSet(j);
	if (height[i] > height[j])
		parent[j] = i;
	else if (height[i] < height[j])
		parent[i] = j;
	else {
		parent[j] = i;
		height[i]++;
	}
}

int SeparatedSet::defineSet(int i)
{
	if (!validIndex(i))
		throw "SeparatedSet: Invalid Index!";
	if (parent[i] == -1)
		return -1;
	while (parent[i] != i)
		i = parent[i];
	return i;
}

int SeparatedSet::getSetSize(int i)
{
	int count = 0;
	int local_parent = defineSet(i);
	for (int j = 0; j < n; j++)
		if (defineSet(j) == local_parent)
			count++;
	return count;
}
