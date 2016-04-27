#include "gtest.h"
#include "Heapsort.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std; 

TEST(HEAPSORT, can_sort_empty_array)
{
	float* arr;
	ASSERT_NO_THROW(Heapsort::heapsort(arr, 0));
}

TEST(HEAPSORT, can_sort_random_array)
{
	float* arr = new float[1000];
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
		arr[i] = rand() % (100000 - 1) + 1;
	Heapsort::heapsort(arr, 1000);
	bool flag = true;
	for (int i = 1; i < 1000; i++) 
		if (arr[i] > arr[i-1])
			flag = false;
	ASSERT_TRUE(flag);
}

TEST(HEAPSORT, throws_when_n_is_negative) 
{
	float* arr = new float[5];
	ASSERT_ANY_THROW(Heapsort::heapsort(arr, -5));
}

TEST(HEAPSORT, can_sort_descending_sorted_array)
{
	float* arr = new float[1000];
	srand(time(NULL));
	for (int i = 1000; i >= 0; --i)
		arr[i] = 2*i;
	Heapsort::heapsort(arr, 1000);
	bool flag = true;
	for (int i = 1; i < 1000; i++) 
		if (arr[i] > arr[i-1])
			flag = false;
	ASSERT_TRUE(flag);
}

TEST(HEAPSORT, can_sort_ascending_sorted_array)
{
	float* arr = new float[1000];
	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
		arr[i] = 2*i;
	Heapsort::heapsort(arr, 1000);
	bool flag = true;
	for (int i = 1; i < 1000; i++) 
		if (arr[i] > arr[i-1])
			flag = false;
	ASSERT_TRUE(flag);
}