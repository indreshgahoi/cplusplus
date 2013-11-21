/*
 * SegrateEvenOdd.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/SegrateEvenOdd.cpp -o /usr/build/Main.o
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
	int arr[] = {1,2,7,9,10,12,3,4,3,17,8,6,13};
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
 * Link :-
 * Question :-
 *
 *
 *
 */



void SegRateEvenOdd(vector<int> &V)
{
	int l = 0 ;
	int r = 0;

	/*
	 *  Invariant
	 *  l point to next position where Even Number Come
	 */

	while(r < V.size())
	{
		if(V[r] & 1)
		{
			swap(V[l],V[r]);
		    l++ ;
		}
		r++ ;
	}
}


void SegrateEvenOddV2(vector<int> &V)
{
	int l = 0 ;
	int r = V.size()-1 ;

	while(l<r)
	{

	   while(V[l]%2==0 && l < r) l++;
	   while(V[r]%2==1 && l < r) r-- ;

	   if(l < r)
	   {
		   swap(V[l],V[r]);
		   l++;
		   r-- ;
	   }
	}
}
/*
 *  Maintain Loop Invariant
 *
 *  Let Array A[1....A.length]
 *  divide Array in Three Part
 *
 *  A[1....l-1] contain 0
 *  A[r+1.....A.length] 1
 *  A[l....r] Unknown
 *
 *
 */
void Segrate0and1(vector<int> &V)
{
	int l = 0 ;
	int r = V.size()-1 ;

	while(l < r)
	{
		while(V[l]==0 && l<r) l++;
		while(V[r]==1 && l < r ) r-- ;
		if(l<r)
		{
			swap(V[l],V[r]);
			l++;
			r--;
		}
	}
}
void driver()
{
	vector<int> input ;

	getInput(input);
	cout<<input<<" \n";
	SegRateEvenOdd(input);
	cout<<input<<" \n";
}
int main(){
	driver();
	cout<<"\n";
	return 0;
}
