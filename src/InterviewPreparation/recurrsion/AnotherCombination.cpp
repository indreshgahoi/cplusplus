/*
 * AnotherCombination.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/recurrsion/AnotherCombination.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 11, 2013
 *      Author: Indresh Gahoi
 */

/* Link :- http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
 *
 *  Question :-
 *
Print all possible combinations of r elements in a given array of size n


Given an array of size n, generate and print all possible combinations of r elements
in array. For example, if input array is {1, 2, 3, 4} and r is 2, then output should
be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include <time.h>
#include<algorithm>

using namespace std ;

template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
		out<<" "<<*it;

	}
	out<<"]"<<endl;
	return out;
}

void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	//	int arr[] = {1, 2, 3, 4, 5 ,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
	//				24,25,26,27,28,29,30};//31,32,33,34,35,36,37,38,39,40,41,42};
	int arr[] = {1, 2,1,3,1};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}

class Timer
{
public:
	Timer()
	{
		start = clock();
	}

	long long int elapsed()
	{
		long long int ela = clock() -start ;
		start = clock();
		cout<<"elapsed time = "<<  ela/CLOCKS_PER_SEC<<"\n";
		return ela/CLOCKS_PER_SEC;
	}
	void reset()
	{
		start = clock();
	}

private :
	clock_t start ;
};


class Solution
{

public:
	static int count  ;
	void combine(vector<int> &V ,int depth,vector<int> &path,int selected)
	{
		if(depth>=V.size() ||
				(V.size()-depth)< (selected-path.size())) return ; //  elapsed time 0  sec
		//if(depth>=V.size()) return ;  elapsed time 69  sec

		// not choose v[depth] element
		combine(V,depth+1,path,selected);

		path.push_back(V[depth]);//  choose v[depth] element
		if(path.size()==selected)
		{
			cout<<path ;
			count++;
		}
		combine(V,depth+1,path,selected);
		path.pop_back();

	}

};

int Solution::count = 0 ;
void test()
{
	vector<int> v ;
	getInput(v);
	Solution solve ;

	cout<<v;
	vector<int> path;
	sort(v.begin(),v.end());
	Timer clk;
	solve.combine(v,0,path,3);
	clk.elapsed();
	cout<<"\ncount= "<<Solution::count;

}


int main()
{
	test();
	return 0 ;
}
