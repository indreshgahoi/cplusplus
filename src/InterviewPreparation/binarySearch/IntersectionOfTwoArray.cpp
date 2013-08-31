/*
 * IntersectionOfTwoArray.cpp
 *
 *  Created on: Jan 30, 2013
 *      Author: indresh
 */

/*
 *  There are two sorted  array of size m and n
 *  O(m+n) solution
 *  O(m*lg(n)) solution prefer when m<< n such that m=1 n=one billion
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//O(m+n) solution
vector<int> findIntersection(vector<int> A,vector<int> B){
	int i=0,j=0;
	vector<int> res;
	while(i<A.size() && j<B.size()){
	  if(A[i]<B[j])
		  i++;
	  else if(A[i]>B[j])
		     j++;
	  else
	  {
		  res.push_back(A[i]);
		  i++;j++;
	  }
	}
	return res;
}
//O(m*log(n))
vector<int> findIntersection2(vector<int> A,vector<int> B){
	vector<int> res;
    if(A.size()>B.size())
    	swap(A,B);
    for(vector<int>::iterator it=A.begin() ;it!=A.end();i++)
    	if(binary_search(B.begin(),B.end(),*it))
    		res.push_back(*it);
	return res;
}

