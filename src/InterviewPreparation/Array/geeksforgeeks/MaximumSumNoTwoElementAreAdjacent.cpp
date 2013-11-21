/*
 * MaximumSumNoTwoElementAreAdjacent.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */

#include "constant.h"

int findMaxSum(int A[],int n){
	int incl=A[0];
	int excl=0;
	for(int i=1;i<n;i++){
		int new_excl=(incl<excl)?excl:incl;
		incl=excl+A[i];
		excl=new_excl;
	}
	return (incl<excl)?excl:incl;
}

void driver(){
	int A[]={1,2,4,6,7,2,3,5,45,10};
	size_t size=ARRAYSIZE(A);
	printf("max Sum=%d",findMaxSum(A,size));
	printArray(A,size);
}
int main(){
	driver();
	return 0;
}


