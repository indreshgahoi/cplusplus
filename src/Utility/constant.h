/*
 * constant.h
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
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
		_ela = 0 ;
		_start = clock();
	}

	long long int elapsed()
	{
		 _ela = clock() -_start ;
		_start = clock();
		cout<<"elapsed time = "<<  _ela/CLOCKS_PER_SEC;
		return _ela/CLOCKS_PER_SEC;
	}
	void start()
	{
		_start = clock();
	}
	void stop()
	{
		 _ela = clock() -_start ;
	}
	void reset()
	{
		_start = clock();
	}

private :
 clock_t _start ;
 long long int _ela ;
};


int main(){
	driver();
	cout<<"\n";
	return 0;
}
#endif /* CONSTANT_H_ */
