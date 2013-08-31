/*
 * RotateArray.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;



void reverseArray(int A[],int start,int end){
	int temp;
	while(start<end){
      temp=A[start];
      A[start]=A[end];
      A[end]=temp;
      start++;
      end--;
	}

}

//This is reversal Algorithm to rotate Array
//Time Complexity :O(n)
void rotateArray(int A[],size_t size,int d){
	reverseArray(A,0,d-1);
	reverseArray(A,d,size-1);
	reverseArray(A,0,size-1);
}
void printArray(int A[],size_t size){
	printf("[");
	for(int i=0;i<size;i++)
		printf("%d ,",A[i]);
	printf(" ]\n");
}
 // one by one rotation
// Time Complexity=O(n*d)
// AuxilarySpace=O(1)
void leftRotateArray(int A[],size_t size){
	int temp=A[0],i=0;
	  for( i=0;i<size-1;i++)
		  A[i]=A[i+1];
	A[i]=temp;
}

void leftRotateArrayBydEelment(int A[],size_t size,int d){
	for(int i=0;i<d;i++)
		leftRotateArray(A,size);

}


//juggling algorithm
int gcd(int a,int b){
	return (b)?gcd(b,a%b):a;
}
void leftRotateArrayByjuggling(int A[],size_t size,int d){
	int noOfGroups=gcd(size,d);
	for(int i=0;i<noOfGroups;i++){
		int temp=A[i];
		int j=i,k;
		while(1){
			k=j+d;
			if(k>=size)
				k-=size;
			if(k==i)
				break;
			A[j]=A[k];
			j=k;
		}
		A[j]=temp;
	}

}

#define ARRAYSIZE(A) (sizeof(A)/sizeof(A[0]))
void driver(){
	int A[]={1,2,3,4,5,6,7,8,9,10,11,12};
	size_t size=ARRAYSIZE(A);
	printArray(A,size);
   // rotateArray(A,size,4);
	//leftRotateArrayBydEelment(A,size,4);
	leftRotateArrayByjuggling(A,size,4);
    printArray(A,size);
}
int main(){
	driver();
	return 0;
}


