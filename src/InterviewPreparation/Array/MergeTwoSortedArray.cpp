/*
 * MergeTwoSortedArray.cpp
 *
 *  Created on: Mar 20, 2013
 *      Author: indresh
 */
#include <iostream>
#include <string>
#include<vector>
using namespace std;
 void merge(int A[], int m, int B[], int n) {
  int total=m+n;
  m--;
  n--;
  while(m!=-1 && n!=-1){
	  total--;
	 if(A[m]>B[n]){
	  A[total]=A[m];
	  m--;
	 }
	 else{
		 A[total]=B[n];
		 n--;
	 }
}
 if(n!=-1 && m==-1){
	 while(n>=0){
		 total--;
		 A[total]=B[n];
		 n--;
	 }
 }

 }


