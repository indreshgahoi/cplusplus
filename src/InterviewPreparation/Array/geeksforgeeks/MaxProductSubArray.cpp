/*
 * MaxProductSubArray.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: root
 */


#include "constant.h"






int  maxProductSubArray(int A[],int n){

    int min_ending_here=1,max_ending_here=1,max_so_for=1;

    for(int i=0;i<n;i++){

        if(A[i]>0){
            // handle positive element
            max_ending_here=max_ending_here*A[i];
            min_ending_here=Min(min_ending_here*A[i],1);
        }
        else if(A[i]==0){
            max_ending_here=1;
            min_ending_here=1;
        }
        else{
            // handle negative element
            int temp=max_ending_here;
            max_ending_here=Max(max_ending_here,min_ending_here*A[i]);
            min_ending_here=temp*A[i];

        }
        if(max_so_for<max_ending_here){
            max_so_for=max_ending_here;
        }
    }
    return max_so_for;
}


void driver(){
    int A[]={-1, -3, -70, 0, 60};
    int n=ARRAYSIZE(A);
    cout<<"Max Product="<<maxProductSubArray(A,n)<<endl;
}






