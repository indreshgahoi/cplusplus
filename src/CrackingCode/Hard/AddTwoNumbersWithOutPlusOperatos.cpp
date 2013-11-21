/*
 * AddTwoNumbersWithOutPlusOperatos.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/bitManiPulation/AddTwoNumbersWithOutPlusOperatos.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
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


/*  task sun = a + b
 *  think bit wise
 *  sum = a ^ b ;
 *  carry=  (a & b) << 1 ;
 *  now the problem reduce add sum and carry until carry becomes 0
 *  Algorith :-
 *
 *
 */

int sumBitWise(int a , int b)
{
	if(b==0)
		return a ;
	int sum = a ^ b ;
	int carry = (a & b) << 1 ;
	return sumBitWise(sum,carry) ;
}

void driver()
{
	cout<<"sum = 17 + 18 " <<sumBitWise(17,18)<<"\n";
	cout<<"sum = -17 + 18 " <<sumBitWise(-17,18)<<"\n";
	cout<<"sum = 17 + -18 " <<sumBitWise(17,-18)<<"\n";
	cout<<"sum = -17 + -18 " <<sumBitWise(-17,-18)<<"\n";
	cout<<"sum = 0 + 18 " <<sumBitWise(0,18)<<"\n";
	cout<<"sum = 17 + 0 " <<sumBitWise(17,0)<<"\n";
	cout<<"sum = 0 - 18 " <<sumBitWise(0,-18)<<"\n";
	cout<<"sum = -17 + 0 " <<sumBitWise(-17,0)<<"\n";
}

int main(){
	driver();
	cout<<"\n";
	return 0;
}
