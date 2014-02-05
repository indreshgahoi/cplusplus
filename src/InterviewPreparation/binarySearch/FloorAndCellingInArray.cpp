/*
 * FloorAndCellingInArray.cpp
 *
 *  Created on: Mar 31, 2013
 *      Author: indresh
 */
#include"constant.h"

/* Question:-Given a sorted array and a value x, the ceiling of x is the
 * smallest element in array greater than or equal to x, and the floor
 * is the greatest element smaller than or equal to x. Assume than the
 * array is sorted in non-decreasing order. Write efficient functions
 * to find floor and ceiling of x.
 *
 */
//for celling A[i]<x<A[i+1] solution is A[i+1]


int ceilingForSortedArray(int A[],size_t n,int x){
	int l=0,r=n-1,mid;

	while(l<=r){
		if(x<A[l])
			return A[l];
		if( x>A[r])
			return -1;
		mid=(l+r)>>1;
		if(x==A[mid]) return x;

		if(x<A[mid]){
			if((mid-1)>=l && x>A[mid-1])
				return A[mid];
			r=mid-1;
		}
		else{
			if((mid+1)<=r && x<=A[mid+1])
				return A[mid+1];
			l=mid+1;
		}
	}
	return -1;
}

void driver(){
	int A[]={1, 2, 8, 10, 10, 12, 19};
	printf("\n ceiling for an array=%d",ceilingForSortedArray(A,ARRAYSIZE(A),5));

}
