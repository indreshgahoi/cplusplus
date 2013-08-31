/*
 * searchInRotatedArray.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>

using namespace std;

bool search(int A[], int n, int target) {

	int low=0,high=n;
	while(low<=high){
		int mid=(low+high)>>1;

		if(A[mid]==target)
			return mid;
		//In sorted sorted part
		if(A[low]==A[mid] &&(l+1)!=r){
			low++;
		}
		else if(A[low]<A[mid]){
			if(target>A[m] || target<A[low])
				low=mid+1;
			else
				high=mid-1;
		}
		else if(target<A[mid] || target>A[high]){
                 high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;

}


