/*
 * MergeSort.h
 *
 *  Created on: Jan 10, 2018
 *      Author: Tony
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

class MergeSort
{
public:
    void merge(int *array, int low, int high, int middle);
    void sort(int *array, int low, int high);
};

#endif /* MERGESORT_H_ */
