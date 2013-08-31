/*
 * InversionInArray.cpp
 *
 *  Created on: Mar 30, 2013
 *      Author: indresh
 */
#include<constant.h>

 // Count inversion In array
//
/*
 *  Definition:-Inversion Count for an array indicates –
 *   how far (or close) the array is from being sorted. If array is
 *   already sorted then inversion count is 0. If array is sorted in
 *   reverse order that inversion count is the maximum.
     Formally speaking, :-
     two elements a[i] and a[j] form an inversion
      if a[i] > a[j] and i < j
 */

// Method I'st TimeComplexity=O(n^2)
//

Integer countInversion(Integer A[], size_t size){
	Integer count=0;
    REP(i,size-1){
    	FOR(j,i+1,size)
    			if(A[i]>A[j]){
    				count++;
    			}
    }
    return count;
}

/*
 *  Inversion using Merge Sort
 *  TimeComplexity=O(n*log n)
 *  Divide conquer
 */
Integer _merge(Integer A[],Integer temp[],int l,int m,int r){
	Integer i=l,j=m+1,k=l,inv_count;
    while(i<=m && j<=r){
    	if(A[i]<=A[j]){
    		temp[k++]=A[i++];
    	}
    	else{

    		temp[k++]=A[j++];
    		inv_count+=(m-i+1);
    	}
    }
    while(i<=m)
    		A[k++]=A[i++];
    while(j<=r)
    	A[k++]=A[j++];
    return inv_count;
}

Integer _mergeSort(Integer A[],Integer temp[],Integer left,Integer right){
  Integer inv_count=0,mid;
  if(left<right){
	  mid=(left+right)>>1;
	  inv_count=_mergeSort(A,temp,left,mid);
	  inv_count+=_mergeSort(A,temp,mid+1,right);
      inv_count=+_merge(A,temp,left,mid,right);
  }
 return inv_count;
}
Integer countInversionByMerge(Integer A[],size_t size){

	Integer *temp=(Integer *)malloc(sizeof(Integer)*size);

	return _mergeSort(A,temp,0,size-1);

}

void driver(){
	Integer A[]={2,4,1,3,5};
	size_t size=ARRAYSIZE(A);
	printf("no of inversion=%d",countInversion(A,size));
	printf("\n no of inversion By merge=%d",countInversionByMerge(A,size));
}
