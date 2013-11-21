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
		if(A[low]==A[mid] &&(low+1)!=high){
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

class Solution
{
	bool search(int A[] , int n , int key)
	{
		int m , l , r ;
		l = 0 , r= n-1;
		while(l <= r)
		{
			if(l==r) return true ;

			m = l + (r-l)/2;
			if(A[m]==key)
				return  m ;
			if(A[l] < A[m]) // first half is sorted
			{
				if(key >= A[l] && key < A[m])
				{
					r = m-1;
				}
				else
				{
					l = m+1 ;
				}
			}
			else if(A[l] > A[m]) //second half is sorted
			{
				if(key<= A[r] && key > A[m])
				{
					l = m+1 ;
				}
				else
				{
					r= m-1 ;
				}
			}
			else // do linear search in Duplicate case
			{
				l++ ;
			}
		}
		return false ;
	}
};

