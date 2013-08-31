/*
 * PanCakeSort.h
 *
 *  Created on: Apr 8, 2013
 *      Author: root
 */

#ifndef PANCAKESORT_H_
#define PANCAKESORT_H_

class PanCakeSort {
	int *a;
	int size;
	int maxIndex(int end);
	void filpArray(int end);

public:
	PanCakeSort(int A[],int size);
	void sort();
	void insertionSort();
	virtual ~PanCakeSort();
};

#endif /* PANCAKESORT_H_ */
