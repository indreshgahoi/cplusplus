/*
 * PanCakeSort_test.cpp
 *
 *  Created on: Apr 8, 2013
 *      Author: root
 */

#include "PanCakeSort.h"
#include "PanCakeSort.cpp"
#include "constant.h"

void driver(){
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	PanCakeSort solver(arr,n);
	solver.sort();
	printArray(arr,n);

}
