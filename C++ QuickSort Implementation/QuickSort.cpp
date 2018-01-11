/*
 * QuickSort.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: Tony
 */

#include <iostream>
#include "QuickSort.h"
using namespace std;

/**
 * This method uses recursion and calls to partition to sort the list.
 */
void QuickSort::quickSort(int *array, int start, int end)
{
    // Base case for recursion. If end equals to or is less than start then break recursion.
    if (start < end)
    {
        // Calling partition to sort list.
        int pIndex = partition(array, start, end);
        // Sort the numbers to the left of pivot which is less than pivot.
        quickSort(array, start, pIndex - 1);
        // Sort the numbers to the right of pivot which is greater than pivot.
        quickSort(array, pIndex + 1, end);
    }
}

/**
 * This method sorts through array given with the start and end index.
 * This sorts using a pivot and all values less than pivot will move to the left.
 * After all values less than pivot moves to the left then swap the current partition with pivot and return.
 */
int QuickSort::partition(int *array, int start, int end)
{
    // Pivot is always the last element in the list.
    int pivot = array[end];
    // Start partition index as start initially.
    int partitionIndex = start;

    for (int i = start; i < end; i++)
    {
        // If element is less or equal to pivot then go in here.
        if (array[i] <= pivot)
        {
            // Swap if element is less than pivot.
            swap(array[i], array[partitionIndex]);
            // Move on to the next index to test.
            partitionIndex++;
        }
    }
    // After all values less than pivot are to the left then swap the current partition index with the pivot at the end.
    swap(array[partitionIndex], array[end]);
    // Return partition index.
    return partitionIndex;
}
