/*
 * minimum_scalar_product.cpp
 *
 *  Created on: Aug 12, 2013
 *      Author: Indresh Gahoi
 */
/* Problem:
 * Problem

You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar product of these vectors
is a single number, calculated as x1y1+x2y2+...+xnyn.Suppose you are allowed to
permute the coordinates of each vector as you wish. Choose two permutations such that the scalar product of your two new vectors is the smallest possible,
and output that minimum scalar product.

Input
The first line of the input file contains integer number T - the number of test cases. For each test case, the first line contains integer number n. The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively.
Output
For each test case, output a line
Case #X: Y
where X is the test case number, starting from 1, and Y is the minimum scalar product of all permutations of the two given vectors.
Limits

Small dataset

T = 1000
1 ≤ n ≤ 8
-1000 ≤ xi, yi ≤ 1000

Large dataset

T = 10
100 ≤ n ≤ 800
-100000 ≤ xi, yi ≤ 100000
 *
 */

#include<iostream>
#include<vector>
#include <cstdio>
#define trv(a,b) for(size_t iter=(a);iter<(b);++iter)
//#define nextInt() ({ \int __t;scanf("%d",&__t);	\__t;})

inline int nextInt(){
	int t;
	std::cin>>t;
	return t;
}
using namespace std;

vector<int> v1;
vector<int> v2;
int n;
long long res;
void solve(int test){
	v1.clear();
	v2.clear();
	res=0;
	cin>>n;
	trv(0,n) v1.push_back(nextInt());
	trv(0,n) v2.push_back(nextInt());
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end(),greater<int>());
	trv(0,n) res+=(long long)(v1[iter])*v2[iter];
	cout<<"Case #"<<test<<":"<<res<<"\n";
}

int main(){
int t;
  cin>>t;
  trv(0,t)
	  solve(iter+1);
}

