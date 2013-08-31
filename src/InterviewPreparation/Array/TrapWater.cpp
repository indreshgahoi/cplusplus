/*
 * TrapWater.cpp
 *
 *  Created on: Apr 9, 2013
 *      Author: root
 */

#include "constant.h"
/*
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it is able to trap
 * after raining
 * For example,
 *   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6
 */

/*
 *  Solution:-
 *      O(n) solution. for each bar, find the max height bar on the left
 *      and right. then for this bar it can hold
 *       min(max_left, max_right) - height
 */

 int trap(int A[], int n) {

	 int water=0;
	 int maxIdx=0;
	 int h=0;
	 for(int i=1;i<n;i++){
		 if(A[maxIdx]<A[i])
			 maxIdx=i;
	 }
     h=0;
     for(int i=0;i<maxIdx;i++)
	   if(h>A[i])
		   water+=(h-A[i]);
	   else
		   h=A[i];
     h=0;
     for(int i=n-1;i>maxIdx;i--)
    	 if(h>A[i])
    		 water+=(h-A[i]);
    	 else
    		 h=A[i];

     return water;
  }
