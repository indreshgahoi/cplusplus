/*
 * RangeSearch.cpp
 *
 *  Created on: Apr 11, 2013
 *      Author: root
 */

#include "constant.h"
//
//  lower.c
//  practice_problem
//
//  Created by Indresh on 9/26/13.
//
//

#include <stdio.h>


#define __advanse(ptr,size,step)    (ptr=(char*)ptr+(size*step))

void* lower_bound(void *first ,size_t len, size_t elem_size, void *value, int (*cmp) (const void *,const void *)){
   
    size_t len1;
    void *m ;
    while(len!=0){
            len1=len>>1;
            m=first;
            __advanse(m,elem_size,len1);
            if(cmp(m,value)){
                m=(char*)m+elem_size;
                first=m;
                len-=len1+1;
            }
            else
                len = len1;
    }
    return first;
}

void* upper_bound(void *first, size_t len ,size_t elem_size , void *value ,int (*cmp) (const void * , const void *)){
   
    size_t len1 ;
    void *m ;
    
    while(len!=0){
        len1=len>>1;
         m=first;
        __advanse(m, elem_size, len1);
        if(cmp(value,m)){
            len=len1;
        }
        else{
            first=m=(char*)m+elem_size;
            len-=len1+1;
        }
        
    }
    return first;
}

int compare(const void *a , const void *b){
    return *((int *)a)<*((int *)b);
}

#define ARRAY_SIZE(A) (sizeof(A)/sizeof(A[0]))

void test_lower_bound(){
    int a[]={1,1,2,2,3,3,4,4,5,5,5,5,6,7,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,11,11,11,13,13,17};
    int i = 13;
   // int *b=(int *)lower_bound(a,ARRAY_SIZE(a),4,&i,&compare);
    int *b=(int *)upper_bound(a,ARRAY_SIZE(a),4,&i,&compare);
        printf("value :%d  \n",*(b));
}

 vector<int> searchRange(int A[], int n, int target) {
     vector<int> ans;
     int l=-1,r=-1;
	 int s=0,e=n-1;
	 int m=0;
	 while(s<e){
		 m=(s+e)>>1;
		 if(target>A[m])
			 s=m+1;
		 else
			 e=m;

	 }
	 if(A[s]==target)
		 l=e;
	 s=0,e=n-1;
	 while(s<e){
		 m=(s+e+1)>>1;
		 if(target<A[m])
			 e=m-1;
		 else
			 s=m;
	 }

	 if(A[s]==target)
		 r=s;



    ans.push_back(l);
    ans.push_back(r);
    return ans;
    }


