#include <algorithm>

#define maxSize 1000
typedef int dataType;

class DAryHeap{
protected:
	dataType *keys;
	int d;
	int size;
public:
	DAryHeap(int d);
	~DAryHeap();

	int add(dataType key);
	int erase();

	int transposition(int i, int j);
	int surfacing(int i);
	int immersion(int i);

private:
	int minChild(int i);
};

