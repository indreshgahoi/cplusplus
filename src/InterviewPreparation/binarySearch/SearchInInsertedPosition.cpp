/*
 * SearchInInsertedPosition.cpp
 *
 *  Created on: Apr 11, 2013
 *      Author: root
 */


int searchInsert(int A[], int n, int target) {

        int s=0,e=n-1;
        int m=0;
        while(s<=e){
        	int m=(s+e)>>1;
            if(A[m]==target)
            	return m;
            if(target<A[m])
            	e=m-1;
            else
            	s=m+1;

        }

        return s;
    }

