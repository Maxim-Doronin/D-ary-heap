#include "Heapsort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	if (argc != 4) 
		return 1;
	int n, minRange, maxRange;
	try {
		n = atoi(argv[1]);
		minRange = atoi(argv[2]);
		maxRange = atoi(argv[3]);
	}
	catch(...) {
		return -1;
	}

	float *arr = new float[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (maxRange - minRange) + minRange;
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ' ;
	cout << endl;

	Heapsort::heapsort(arr, n, 4);

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ' ;
	cout << endl;
	return 0;	
}