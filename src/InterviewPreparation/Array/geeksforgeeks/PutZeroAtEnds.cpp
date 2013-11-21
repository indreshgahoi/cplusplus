/*
 * PutZeroAtEnds.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/PutZeroAtEnds.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 10, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<vector>

using namespace std ;


#define ARRAYSIZE(A)   ( sizeof(A)/sizeof(A[0]) )


/* Question :-
 * 			Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
 * 			For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to
 * 			{1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same. Expected time
 * 			complexity is O(n) and extra space is O(1)
 *
 */

void PutsZeroAtEnd(int *A , int size)
{
	int count = 0 ;
	int iter = 0 ;

	for(;iter < size;++iter)
	{
		if(A[iter]!= 0)count++;
		else
			break ;
	}
	for(;iter < size ; ++iter)
		if(A[iter]!= 0) A[count++]=A[iter];

	while(count < size )A[count++]=0;

}

void printArray(int A[],int size){
	printf("values= [");
	for(int i=0;i<size-1;i++)
		printf("%d ,",A[i]);
	printf("%d]\n",A[size-1]);
}

int main(){
	int a[] ={1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	int size = ARRAYSIZE(a);
	printArray(a,size);
	PutsZeroAtEnd(a,size);
	printArray(a,size);
}
