/*
 * KthSmallestElementInTwoSortedArray.cpp
 *
 *  Created on: Jan 30, 2013
 *      Author: indresh
 */

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// O(k) solution using two pointer
// it Only work well for small value of k

int KthSmallestElementInTwoSortedArray(vector<int> A, vector<int> B,int k){
	int res;
	int i=0,j=0,step=0;
	while(true){
		if(  i<A.size() && A[i]<B[j])
		{
			step++;
			i++;
		}
		else if( j<B.size() && A[i]>B[j] )
		{
			step++;
			j++;
		}
		else
		{
			if(i<A.size())
			i++;
			if(j<B.size())
			j++;
			step++;
		}
		if(step==(k-1))
		{
			res=A[i]<B[j]?A[i]:B[j];
		     break;
		}
	}
return res;
}
// O(lgm+lgn)
//solution
/*
 *  if Ai belongs to between Bj and Bj-1 means (Bj-1<Ai<Bj)
 *  then we can say that we have found i+j+1 smallest element
 *   so maintain the invariant such that
 *    i+j+1=k then Ai is the smallest element
 *
 *    i/j=m/n and i+j+1=k
 *    find out the value of i and j in term of m,and n
 */


int kthSmallestElementIntwosortedArray2(int A[],int m,int B[],int n,int k)
{
	int i=(int)(((double)(m))/(m+n)*(k-1));
	int j=(k-1)-i;

	int Ai=(i==m)?INT_MAX:A[i];
	int Bj=(j==n)?INT_MAX:B[j];
	int Ai_1=(i==0)?INT_MIN:A[i-1];
	int Bj_1=(j==0)?INT_MIN:B[j-1];
	if(Ai<Bj && Ai>Bj_1)
		return Ai;
	if(Bj>Ai && Bj>Ai_1)
		return Bj;
	if(Ai<Bj)
		return kthSmallestElementIntwosortedArray2(A+i+1,m-i-1,B,j,k-i-1);
	else
		return kthSmallestElementIntwosortedArray2(A,i,B+j+1,n-j-1,k-j-1);
}

