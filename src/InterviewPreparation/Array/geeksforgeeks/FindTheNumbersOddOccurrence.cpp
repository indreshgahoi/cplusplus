/*
 * FindTheNumbersOddOccurrence.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */


/*
 *
Find the Number Occurring Odd Number of Times
June 22, 2009

Given an array of positive integers. All numbers occur even number of
times except one number which occurs odd number of times.
 Find the number in O(n) time & constant space
*/
#include<iostream>
#include <cstdio>
int getOddOccurrence(int A[],size_t size){
	int oddOccurrence=A[0];
	for(int i=1;i<size;i++){
		oddOccurrence^=A[i];
	}
	return oddOccurrence;
}
//Time Complexity: O(n)
#define ARRAYSIZE(A) (sizeof(A))/(sizeof(A[0]))

void driver(){
 int A[]={1,1,2,2,3,5,6,8,6,5,3};
 printf("number is equal=%d",getOddOccurrence(A,ARRAYSIZE(A)));
}

int main(){
	driver();
	return 0;
}
