/*
 * MajorityElement.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */

/*
 * http://users.eecs.northwestern.edu/~dda902/336/hw4-sol.pdf
 */
/*
 * Majority element Moore's algorithm there must be one element is greater then n/2
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;

int findCandidate(int A[],size_t size){
	int major_idx=0,count=1;
	for(int i=1;i<size;i++){
		if(A[major_idx]==A[i])
			count++;
		else
			count--;
		if(count==0)
		{
			major_idx=i;
			count=1;
		}
	}
	return A[major_idx];
}

int getFrequency(int A[],size_t size,int element){
	int frequency=0;
	for(int i=0;i<size;i++){
		if(element==A[i]) frequency++;
	}
	return frequency;
}
int getMajorityCandidate(int A[],size_t size){

	int candidate=findCandidate(A,size);
	int frequency=getFrequency(A,size,candidate);
	if(frequency>(size/2+1))
		return candidate;
	return -1;
}
/*
 * Analysis:-Time Complexity: O(n)
   Auxiliary Space : O(1)
 */
#define ARRAYSIZE(A) sizeof(A)/sizeof(int)
void driver(){
	int A[]={1,1,2,1,2,3,3,1,1,3,4,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,4,4,1,1,2,2,1,1,1,3,1,1,5,1,6,6,6,1,1,6,6};
    int size=ARRAYSIZE(A);
    printf("majority element=%d",getMajorityCandidate(A,size));
}

int main(){
	driver();
	return 0;
}
