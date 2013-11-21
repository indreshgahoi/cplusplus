/*
 * FindMissingNumber.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

/*
 * Question:-
 * You are given a list of n-1 integers and these integers are in the
 * range of 1 to n. There are no duplicates in list. One of the integers
 *  is missing in the list. Write an efficient code to find the missing
 *  integer
 */
//method first
int findMissingNumber(int A[],size_t size){
	int total=((size+1)*(size+2))>>1;//sum of number in range from 1 to n
	for(int i=0;i<size;i++)
		total-=A[i];
 return total;
}
/*
 * In this method sum of the numbers can go beyond allowed integer
 */
//method second
/*
 *  1.first we calculate xor of number in range fron 1 to n say x1
 *  2. then we calculate xor of given n-1 number say x2
 *  3. missing number=x1^x2
 */

 int findMissingNumberM2(int A[],size_t size){

	 int x1=0;
	 for(int i=1;i<size+2;i++)
		 x1^=i;
	 int x2=0;
	 for(int i=0;i<size;i++)
		 x2^=A[i];
	 int res=x1^x2;
	 return res;
 }

#define ARRAYSIZE(P) (sizeof(P)/sizeof(P[0]))
void driver(){
	int A[]={1,4,5,6,8,2,3,9,10};
	printf("%dMethod 1=\n",findMissingNumber(A,ARRAYSIZE(A)));
	printf("\n Method 2=%d\n",findMissingNumberM2(A,ARRAYSIZE(A)));
}

int main(){
	driver();
 return 0;
}



