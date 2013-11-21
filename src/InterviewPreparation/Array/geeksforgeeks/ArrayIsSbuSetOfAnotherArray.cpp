/*
 * FindArrayIsSbuSetOfAnotherArray.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/FindArrayIsSbuSetOfAnotherArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 16, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

typedef int Integer ;

void driver();



void printArray(int A[],size_t size){
	printf("values= [");
	for(int i=0;i<size-1;i++)
		printf("%d ,",A[i]);
	printf("%d]\n",A[size-1]);
}

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
	int arr[] = {-1,-1,-1,1,1};
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
		cout<<"elapsed time = "<<  ela/CLOCKS_PER_SEC;
		return ela/CLOCKS_PER_SEC;
	}
	void reset()
	{
		start = clock();
	}

private :
	clock_t start ;
};

/* Link :-http://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
 *
 * Question :-
 *
Find whether an array is subset of another array | Added Method 3
June 9, 2011

Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order.

Examples:
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[]
 *
 *
 *
 */

/* To Attack The Problem
 *  use Technique Sorting And Merging
 *  first sort the Array A[1....A.lenghth]  B[1....B.lenght]
 *
 *
 *
 */

bool isSubSetOfArray(vector<int> &A , vector<int> &B)
{
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int i = 0 , j = 0;

	while(i < A.size() && j < B.size())
	{
		if(A[i]<B[j])
			i++ ;
		else if(A[i] > B[j])
		{
			j++ ;
		}
		else
		{
			i++;
			j++ ;
		}

	}

	if(j<B.size())
		return false ;
	return true ;
}



void driver()
{
	vector<int> A ;
	vector<int> B ;
	A.push_back(1); A.push_back(8);A.push_back(7);A.push_back(6);A.push_back(3);A.push_back(4);
	B.push_back(4); B.push_back(7);B.push_back(7); B.push_back(9);
   if(isSubSetOfArray(A,B))
   {
	   cout<<"YES\n";
   }
   else
   {
	   cout <<"NO" ;
   }
}


int main(){
	driver();
	cout<<"\n";
	return 0;
}
