/*
Main.cpp
Executing the insertion sort algorithm. Best case with everything sorted is O(n). Worst case descending sorted is O(n^2).
Author: Tony Nguyen
Date Created: 3/4/2018
*/

#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{
	int j, temp;

	// i equals second number in the list and would loop all the way to end of list.
	for (int i = 1; i < size; i++)
	{
		// Make j equal to i.
		j = i;
		// While j is greater than 0 and left side number is greater than right side number.
		while (j > 0 && array[j - 1] > array[j])
		{
			// Size the lower number in temp.
			temp = array[j];
			// Now make the lower number equal the higher number.
			array[j] = array[j - 1];
			// Now make higher number equal to lower number.
			array[j - 1] = temp;
			// Decrease j.
			j--;
		}
	}
}

int main()
{
	const int size = 6;
	int testArray[size] = {7, 2, 5, 3, 4, 1};

	// Before sorting.
	for (int i = 0; i < size; i++)
	{
		cout << testArray[i] << " ";
	}
	cout << endl;

	// Sorting our array.
	insertionSort(testArray, size);

	// After sorting.
	for (int i = 0; i < size; i++)
	{
		cout << testArray[i] << " ";
	}
	cout << endl;

	return 0;
}