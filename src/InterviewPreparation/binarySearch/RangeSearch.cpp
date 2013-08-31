/*
 * RangeSearch.cpp
 *
 *  Created on: Apr 11, 2013
 *      Author: root
 */

#include "constant.h"

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


