//
//  MaxiMumLengthBitonicSequence.h
//  practice
//
//  Created by Chiranjit on 4/5/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//
#include "constant.h"

// Method TimeComplexity=O(n) Space Complexity=O(n)
int maxiMumLengthBitonicSequenceI(int A[],int n){
    int *left=new int[n];
    int *right =new int[n];
    left[0]=1;
    for(int i=1;i<n;i++){
        if(A[i-1]<=A[i])
            left[i]=left[i-1]+1;
        else
            left[i]=1;
        
    }
    right[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(A[i]>=A[i+1])
            right[i]=right[i+1]+1;
        else
            right[i]=1;
    }
    int maxLen=0;
    for(int i=0;i<n;i++){
        int diff=(left[i]+right[i]-1);
        if(diff>maxLen)
            maxLen=diff;
    }
    return maxLen;
}

//Time Complexity=O(n) Space Complexity=O(1)
int maxiMumLengthBitonicSequenceII(int A[],int n){
    int maxLen=0;
    
    for(int i=0;i<n;i++){
        
    }
    
    return maxLen;
}


void driver(){
    int A[]={2,2,2,2,2,2,2,2,1};
    int n=ARRAYSIZE(A);
    int len=maxiMumLengthBitonicSequenceI(A,n);
    printf("maximum length=%d",len);
}














