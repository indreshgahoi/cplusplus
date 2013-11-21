/*
 * TurnImage90Degree.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/TurnImage90Degree.cpp -o /usr/build/Main.o
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


vector<vector<int> >& rotate(vector< vector<int> > &mat)
{
	vector< vector<int> > *dest = new vector<vector<int> >(mat[0].size(),vector<int>(mat.size()));

	int m = mat.size();
	int n = mat[0].size();

	for(int i = 0 ; i < m ; ++i)
		for(int j = 0 ; j < n ; ++j){
			(*dest)[j][m-1-i] =mat[i][j] ;
		}
  return *dest;
}


void driver()
{
	int m, n ;
	vector<vector<int> > mat ;
	cin>>m>>n ;

	for( int i = 0 ; i < m ; ++i)
	{
		vector<int> col ;
		for(int j = 0 ; j < n ; ++j)
		{
			int x ;
			cin>> x ;
			col.push_back(x);
		}
		mat.push_back(col);
	}
	cout<<mat<<"\n";
  cout<<"\n\n\n"<<rotate(mat)<<"\n\n";
}


int main(){
	driver();
	cout<<"\n";
	return 0;
}
