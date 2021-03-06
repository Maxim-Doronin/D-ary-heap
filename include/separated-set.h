#pragma once

class SeparatedSet {
private:
	int *parent;
	int *height;
	int n;
	bool validIndex(int i);
public:
	SeparatedSet(int n);
	~SeparatedSet();

	void singleton(int i);
	void association(int i, int j);
	int defineSet(int i);
	int getSetSize(int i);
};