/*
 * EquilibriumIndexArray.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/EquilibriumIndexArray.cpp -o /usr/build/Main.o
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
	int arr[] = {-7, 1, 5, 2, -4, 3, 0} ;
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
 *  Link :- http://www.geeksforgeeks.org/equilibrium-index-of-an-array/
 *  Question -: Equilibrium index of an array is an index such that the sum of
 *  elements at lower indexes is equal to the sum of elements at higher indexes.
 *   For example, in an arrya A:
 *
 *
 */
/* Let Array A[1......n]
 * first calculate sum = sum of A[1]+......+A[n]
 * leftSum
 * for i to n
 *   sum = sum - A[i]
 *   if(sum==leftSum) result i ;
 *   leftSum = leftSum + A[i]
 */

void EquilibriumIndex(vector<int> &V)
{
	int total_sum = 0 ;
	int pre_fix_sum = 0 ;
  for(vector<int>::const_iterator it = V.begin() ; it != V.end() ;++it)
  {
	  total_sum+=*it ;
  }

  for(vector<int>::const_iterator it = V.begin() ; it != V.end() ;++it)
  {
  	  total_sum -= *it ;
  	  if(pre_fix_sum == total_sum)
  		  cout<<"\n index="<<it-V.begin()<<" value = "<<*it<<" left="<<pre_fix_sum<<" right="<<total_sum<<" \n";
  	  pre_fix_sum+=*it;
  }

}


void driver()
{
  vector<int> input ;

  getInput(input);
  cout<<input<<"\n";
  EquilibriumIndex(input);
}


int main(){
	driver();
	cout<<"\n";
	return 0;
}
