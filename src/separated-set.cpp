#include "separated-set.h"

SharedSet::SharedSet(int n)
{
	parent = new int [n];
	for (int i = 0; i < n; i++)
		parent[i] = -1;
	height = new int [n];
	this->n = n;
}

SharedSet::~SharedSet()
{
	delete [] parent;
	delete [] height;
}

bool SharedSet::validIndex(int i)
{
	if ((i < 0) || (i >= n))
		return false;
	else
		return true;
}

void SharedSet::singleton(int i)
{
	if (!validIndex(i))
		throw "SharedSet: Invalid Index!";
	if (parent[i] != -1)
		return;
	parent[i] = i;
	height[i] = 0;
}

void SharedSet::association(int i, int j)
{
	if ((!validIndex(i)) || (!validIndex(j)))
		throw "SharedSet: Invalid Indexes!";
	if ((parent[i] == -1)||(parent[j] == -1))
		throw "SharedSet: Empty set!";
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

int SharedSet::defineSet(int i)
{
	if (!validIndex(i))
		throw "SharedSet: Invalid Index!";
	if (parent[i] == -1)
		return -1;
	while (parent[i] != i)
		i = parent[i];
	return i;
}

int SharedSet::getSetSize(int i)
{
	int count = 0;
	int local_parent = defineSet(i);
	for (int i = 0; i < n; i++)
		if (parent[i] = local_parent)
			count++;
	return count;
}
