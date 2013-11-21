/*
 * FindPivotElement.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binarySearch/FindPivotElement.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 5, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include <cstdio>


/*
 *  Find the pivot point, divide the array in two sub-arrays and call binary search.
The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array,
pivot element is the only only element for which next element to it is smaller than it.
Using above criteria and binary search methodology we can get pivot element in O(logn) time
 *
 */


int FindPivot(int arr[] ,int low , int high){
  int mid ;
   if(high < low ) return -1;
   if(high == low) return low ;

   mid = low + (high - low) / 2 ;

   if(mid < high && arr[mid] > arr[mid+1])
	  return mid ;
   if(low < mid && arr[mid-1] > arr[mid] )
	   return mid -1 ;

   if(arr[low] >= arr[mid])
	   return FindPivot(arr,low,mid-1);
   else
	   return FindPivot(arr,mid+1,high);
}


int BinarySearch(int arr[] , int low , int high , int key){

	if(high < low)
		return -1 ;
	int mid = low + (high - low ) / 2 ;

	if(key==arr[mid])
		 return mid ;
	if(key < arr[mid])
		return BinarySearch(arr,low,mid-1,key);
	else
		return BinarySearch(arr,mid+1,high,key);
}

int findElement(int arr[] , int size ,int key){

	int pivot = FindPivot(arr,0,size-1);
    printf("pivot = %d \n",pivot);
	if(pivot==-1){
		return BinarySearch(arr,0,size-1,key);
	}
	if(arr[pivot]==key)
		return pivot ;
	if(key < arr[0])
		return BinarySearch(arr,pivot+1,size-1,key);
	else
		return BinarySearch(arr,0,pivot-1,key) ;
}

void test_0_searchInrotated(){
	// Let us search 3 in below array
	   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	   int arr_size = sizeof(arr1)/sizeof(arr1[0]);
	   int no = 3;
	   printf("Index of the element is %d\n",  findElement(arr1, arr_size, no));

	    // Let us search 3 in below array
	   int arr2[] = {3, 4, 5, 1, 2};
	   arr_size = sizeof(arr2)/sizeof(arr2[0]);
	   printf("Index of the element is %d\n",  findElement(arr2, arr_size, no));

	   // Let us search for 4 in above array
	   no = 4;
	   printf("Index of the element is %d\n",  findElement(arr2, arr_size, no));

	   // Let us search 0 in below array
	   int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
	   no = 0;
	   arr_size = sizeof(arr3)/sizeof(arr3[0]);
	   printf("Index of the element is %d\n",  findElement(arr3, arr_size, no));

	   // Let us search 3 in below array
	   int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
	   no = 3;
	   arr_size = sizeof(arr4)/sizeof(arr4[0]);
	   printf("Index of the element is %d\n",  findElement(arr4, arr_size, no));

	   // Let us search 2 in above array
	   no = 2;
	   printf("Index of the element is %d\n",  findElement(arr4, arr_size, no));

	   // Let us search 3 in below array
	   int arr5[] = {1, 2, 3, 4};
	   no = 3;
	   arr_size = sizeof(arr5)/sizeof(arr5[0]);
	   printf("Index of the element is %d\n",  findElement(arr5, arr_size, no));



}

int main(){
	test_0_searchInrotated();
	return 0 ;
}
