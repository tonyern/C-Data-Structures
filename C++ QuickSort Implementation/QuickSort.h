/*
 * QuickSort.h
 *
 *  Created on: Jan 11, 2018
 *      Author: Tony
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort
{
public:
    void quickSort(int *array, int start, int end);
    int partition(int *array, int start, int end);
};

#endif /* QUICKSORT_H_ */
