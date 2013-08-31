/*
 * MinimumLengthUnSortedArray.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: root
 */

#include "constant.h"
void minimumLengthUnSortedArray(int A[],int n,int *s,int *e){
    *s=0;
    *e=n-1;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1])
        {
            *s=i;
            break;
        }
    }
    for(int i=n-1;i>0;i--){
        if(A[i-1]>A[i])
        {
            *e=i;
            break;
        }
    }
    if((*s)==(n-1) || (*s)>(*e)){
        *s=-1;
        *e=-1;
        printf("Array is already fully Sorted ");
    }
    // elements b/w s to e are candidates those are responsible for unsorted nature
    int max=-1,min=1e9;
    for(int i=(*s);i<=(*e);i++){
        if(max<A[i])
            max=A[i];
        if(min>A[i])
            min=A[i];
    }
    for(int i=0;i<(*s);i++){
        if(min<A[i]){
            *s=i;
            break;
        }
    }
    for(int i=n-1;i>(*e);i--){
        if(max>A[i]){
            *e=i;
            break;
        }
    }

}

void driver(){
    int A[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n=ARRAYSIZE(A);
    int s,e;
    minimumLengthUnSortedArray(A,n,&s,&e);
    printf("start=%d end=%d",s,e);
}







