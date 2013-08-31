/*
 * MaximumRepeatingElement.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: root
 */

#include "constant.h"

/* Question:-
 * Given an array of size n, the array contains numbers in range from 0
 *  to k-1 where k is a positive integer and k <= n. Find the maximum
 *  repeating number in this array. For example, let k be 10 the given
 *  array be arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, the
 *   maximum repeating number would be 2. Expected time complexity is
 *    O(n) and extra space allowed is O(1). Modifications to array are
 *    allowed.
 *
 */



int maximumRepeatingElement(int A[],size_t n,int k ){



  for(int i=0;i<n;i++){
	A[A[i]%k]+=k;
  }
  int max_index=0;
  for(int i=1;i<k+1;i++){
	  if(A[max_index]<A[i]){
		  max_index=i;
	  }
  }
  //to set back array in normal position
  for(int i=0;i<n;i++){
	  A[i]=A[i]%k;
  }
  return max_index;
}


void driver(){
	int A[]={5,5,5,1,9,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,7,5,5,5,5,5,5,5,7,9,7,7,7,7,7,7,7,7,7,7,7,7,9,9,3,4,4,4,4,4,1,1,7,1,1,1,1,1,1,7,7,7,8,9,3,3,3,3,3,5,5,5,3,2,2,2,2,2,2,2,22,2,2,1,1,1,5,5,5,5,5,5,5,5,5,5,6,7,8,9,1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1};
	size_t n=ARRAYSIZE(A);
	printf("max repeating element=%d",maximumRepeatingElement(A,n,22));

}

