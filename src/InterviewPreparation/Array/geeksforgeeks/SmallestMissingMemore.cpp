/*
 * FindTheSmallestMissingMemore.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/FindTheSmallestMissingMemore.cpp -o /usr/build/Main.o
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
	int arr[] = {2};
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

/*
 *  Link :-http://www.geeksforgeeks.org/find-the-first-missing-number/
 * Question :-
Find the smallest missing number

Given a sorted array of n integers where each integer is in the range from 0 to m-1
 and m > n. Find the smallest number that is missing from the array.
 *
 *
 *
 */


int FindTheSmallestMissingNumber(vector<int> &v)
{
	/*
	 *  Case m = l+r/2   if(v[m] > m) then  v[l.....m] contain element contain numbers
	 *   greater in range l.......m
	 *
	 */

	int low = 0 ;
	int high = v.size();
	int mid ;

	while(low<=high)
	{

		if(v[low]>low) return low ;

		mid = low + (high-low)/2 ;
		if(v[mid] <= mid)
			low = mid+1 ;
		else
			high = mid-1 ;

	}
   return mid ;
}


void driver()
{
	vector<int> v ;
	getInput(v);
	cout<<"input "<< v ;
	cout<<"output "<<FindTheSmallestMissingNumber(v)<<"\n";
}

int main(){
	driver();
	cout<<"\n";
	return 0;
}
