/*
 * MajorityElementInSortedArray.cpp
 *
 *  Created on: Mar 30, 2013
 *      Author: indresh
 */

#include<constant.h>

int _binarySearch(int A[],int l,int r,int x){
	if(l<=r){
	int m=(l+r)>>1;

	if((0==m||A[m-1]<x)&& A[m]==x )
		return m;
	if(x>A[m])
		return _binarySearch(A,m+1,r,x);
	return _binarySearch(A,l,m-1,x);
	}
	return -1;
}



bool isMajority(int A[],size_t size,int x){
      int idx=_binarySearch(A,0,size-1,x);
      if(-1==idx)return false;

      if((idx+size/2)<=size-1 && A[idx+size/2]==x)
    	  return true;
      return false;
}

void driver(){
	Integer A[]={1, 2, 3, 3, 3, 3, 10};

	printf("isMajprity=%s",(isMajority(A,ARRAYSIZE(A),3))?"true":"false");
}

