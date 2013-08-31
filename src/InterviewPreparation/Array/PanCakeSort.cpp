/*
 * PanCakeSort.cpp
 *
 *  Created on: Apr 8, 2013
 *      Author: root
 */

#include "PanCakeSort.h"
#include<constant.h>
PanCakeSort::PanCakeSort(int A[],int size) {

 this->a=A;
 this->size=size;
}

PanCakeSort::~PanCakeSort() {

}


void PanCakeSort::sort(){

   for(int i=size;i>0;i--){
	   int midx=maxIndex(i);

	   if(midx!=(i-1)){
	     filpArray(midx);
	     filpArray(i-1);
	   }

   }
}


int PanCakeSort::maxIndex(int end){
	 int mIdx=0;
	for(int i=1;i<end;i++){
		if(a[i]>a[mIdx]){
			mIdx=i;
		}
	}

	return mIdx;
}

void PanCakeSort::filpArray(int end){
	int i=0;
    while(i<end){
    	int temp=a[i];
    	a[i]=a[end];
    	a[end]=temp;
    	i++;end--;
    }

}
