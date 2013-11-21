/*
 * MiniMumDistanceBetweenTwoNumbers.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/MiniMumDistanceBetweenTwoNumbers.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 15, 2013
 *      Author: Indresh Gahoi
 */



/*
 *  Question :-
 *
Find the minimum distance between two numbers
June 24, 2011

Given an unsorted array arr[] and two numbers x and y, find the minimum distance
between x and y in arr[]. The array might also contain duplicates.
You may assume that both x and y are different and present in arr[].
 *
 *
 */


#ifndef CONSTANT_H_
#define CONSTANT_H_
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

int MinMumDistance(vector<int> V, int x , int y)
{
	int size = V.size() ;

  int i , pre ;
  for( i = 0 ; i < size ; ++i)
  {
	  if(V[i]==x || V[i]==y)
	  {
		  pre = i ;
		  break ;
	  }
  }
  int minDist = 10e9 ;
  for( ; i < size() ; ++i)
  {
	  if((V[i]==x || V[i]==y))
	  {
		 if( V[i] != V[pre] && (i-pre)<minDist)
			  minDist = i-pre ;
		  pre = i ;
	  }
  }

 return minDist ;
}



int main(){
	driver();
	cout<<"\n";
	return 0;
}
