/*
 * FindDuplicatesInArray.cpp
 *
 *  Created on: Mar 30, 2013
 *      Author: indresh
 */

/*
 * Question:-
 *  Given an array of n elements which contains elements from 0 to n-1,
 *   with any of these numbers appearing any number of times.
 *    Find these repeating numbers in O(n) and using only constant memory
 *    space.
  For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6},
  the answer should be 1, 3 and 6.
  This problem is an extended version of following problem
 */
#include "constant.h"
#include<set>
vector<int> findDuplicates(int A[],size_t n){
	vector<int> duplicates;
	REP(i,n){
		if(A[abs(A[i])]>0)
			A[abs(A[i])]=-A[abs(A[i])];
		else
			duplicates.push_back(abs(A[i]));
	}
	return duplicates;
}

void driver(){
	Integer A[]={1,2,3,4,2,2,2,4};
	cout<<"duplicates are"<<findDuplicates(A,ARRAYSIZE(A))<<endl;
}
