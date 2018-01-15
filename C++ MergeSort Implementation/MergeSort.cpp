/*
 * MergeSort.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: Tony
 */

#include <iostream>
#include "MergeSort.h"
using namespace std;

void MergeSort::merge(int *array, int low, int high, int middle)
{
    // We have low to middle and middle+1 to high already sorted.
    int i = low;
    int j = middle + 1;
    int temp[high - low + 1];
    int k = 0;

    // Merge the two parts into temp[].
    while (i <= middle && j <= high)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        } else {

            temp[k] = array[j];
            k++;
            j++;
        }
    }

    // Insert all remaining values from i to middle into temp[].
    while (i <= middle)
    {
        temp[k] = array[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = array[j];
        k++;
        j++;
    }

    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        array[i] = temp[i - low];
    }

}

void MergeSort::sort(int *array, int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high) / 2;
        // Split the data into two half.
        sort(array, low, middle);
        sort(array, middle + 1, high);

        // Merge them to get sorted output.
        merge(array, low, high, middle);
    }
}
