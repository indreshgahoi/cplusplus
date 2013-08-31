/*
 * ArraypairSunX.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

//Method one
void exchange(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int A[],int s,int e){
	int pivot=A[e];
	int j=s-1,i=s;
	for(i=s;i<e;i++){
		if(A[i]<=pivot){
			j++;
          exchange(&A[j],&A[i]);

		}
	}
	exchange(&A[j+1],&A[i]);
	return j+1;
}


void quickSort(int A[],int s,int e){
  if(s<e){
     int p=partition(A,s,e);
     quickSort(A,s,p-1);
     quickSort(A,p+1,e);
  }

}

bool arrayHasPairHaveSumUpToX(int A[],size_t arr_size,int sum){
	quickSort(A,0,arr_size-1);
	int l=0,r=arr_size-1;
	while(l<r){
		if((A[l]+A[r])==sum){
			return true;
		}
		if(sum>(A[l]+A[r])){
			l++;
		}
		else
			r--;
	}
	return false;
}
/*
 * Time Complexity: Depends on what sorting algorithm we use.
 *  If we use Merge Sort or Heap Sort then (-)(nlogn) in worst case.
 *   If we use Quick Sort then O(n^2) in worst case.
    Auxiliary Space : Again, depends on sorting algorithm. For example auxiliary space is O(n) for merge sort
    and O(1) for Heap Sort.
 */
void printArray(int A[],size_t size){
	printf("[ ");
	for(int i=0;i<size;i++){
		printf(" %d,",A[i]);
	}
	printf("]\n");
}


// Method 2
//  use of Map
#define RANGE 10000
bool arryHasSumUpToXByBinaryHasMap(int A[],size_t size,int sum){
	bool binaryMap[RANGE]={false};
    printArray(A,8);
	for(int i=0;i<size;i++){
		int temp=sum-A[i];
		if(temp>=0 && binaryMap[temp]){
			printf("\nPairs are=%d and %d\n",A[i],temp);
			return true;
		}
		binaryMap[A[i]]=true;
	}
	return false;
}
/*
 *  handle case when there are negative numbers
 *  we can solve it by make all positive by adding absolute value of
 *  smallest negative number
 *
 */
 bool arrayHasSumUpToXbyUsingHasMapHavingNegativeNumber(int A[],size_t size,int sum){

	 int min=A[0];
	 int val=A[0];
	 for(int i=1;i<size;i++){
		 if(min>A[i])
			 min=A[i];
	 }
	 if(min<0){
		 if(sum<min)
			 val=-sum;
		 else
			 val=-min;
	 }
	 else val=0;

	 for(int i=0;i<size;i++) A[i]+=val;
	 sum+=(val<<1);

	 return arryHasSumUpToXByBinaryHasMap(A,size,sum);
 }
/*
 * Analysis:-Time Complexity: O(n)
   Auxiliary Space: O(R) where R is range of integers.
 */




void driver(){
	int A[]={1,7,4,2,3,9,10,5};
	 printArray(A,8);
	 printf("%d",arrayHasPairHaveSumUpToX(A,8,10));
	 printArray(A,8);
	 printf("\n%d",arryHasSumUpToXByBinaryHasMap(A,8,10));
	 A[1]=-7;A[4]=-3;
     printf("\n%d",arrayHasSumUpToXbyUsingHasMapHavingNegativeNumber(A,8,-10));
}





int main(){
	driver();
	return 0;
}



