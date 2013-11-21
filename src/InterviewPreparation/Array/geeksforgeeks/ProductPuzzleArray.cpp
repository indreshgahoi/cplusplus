/*
 * ProductPuzzleArray.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/ProductPuzzleArray.cpp -o /usr/build/Main.o
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

vector<int> productPuzzleArray(vector<int> &V)
{
   vector<int> result(V.size());

   int size = V.size();
   int leftSum = 1 , rightSum = 1 ;


   for(int i = 0 ; i < size ; ++i)
   {
	   result[i] = leftSum ;
	   leftSum *= V[i];
   }
   cout<<"\n"<<result;
   for(int i = size-1 ; i>= 0 ;--i)
   {
	   result[i] *=rightSum ;
	   rightSum *= V[i];
   }
   cout<<"\n"<<result<<"\n";
   return result ;
}

void driver()
{

	vector<int> input ;
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(7);
	input.push_back(5);
	cout<<input ;
	cout<<"\n Ans= "<<productPuzzleArray(input);
}

int main(){
	driver();
	cout<<"\n";
	return 0;
}
