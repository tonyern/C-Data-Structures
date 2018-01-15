/*
 * BubbleSort.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: Tony
 */

#include <iostream>
#include "BubbleSort.h"
using namespace std;

/**
 * Bubble sort algorithm.
 */
void BubbleSort::bubbleSort(int* array, int size)
{
    int k;
    int j;
    int temp;

    for (k = 1; k <= size - 1; k++)
    {
        for (j = 0; j <= size - k - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
