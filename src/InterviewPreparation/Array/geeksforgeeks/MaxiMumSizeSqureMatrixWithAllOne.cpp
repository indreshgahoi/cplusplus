/*
 * MaxiMumSizeSqureMatrixWithAllOne.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/MaxiMumSizeSqureMatrixWithAllOne.cpp -o /usr/build/Main.o
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

/* Link :- http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
 *
 * Question :- Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

For example, consider the below binary matrix.


   0  1  1  0  1
   1  1  0  1  0
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0

The maximum square sub-matrix with all set bits is

    1  1  1
    1  1  1
    1  1  1

Algorithm:
Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an
 auxiliary size matrix S[][] in which each entry S[i][j] represents size of the
 square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost
 and bottommost entry in sub-matrix
 *
 *  Algorithm :-
 *  	Construct a sum matrix S[R][C] for the given M[R][C].
     a)	Copy first row and first columns as it is from M[][] to S[][]
     b)	For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print
   sub-matrix of M[][]
 *
 *
 *
 */


void FindMaxiMumSizeSqureMatrixContainsAll1(vector<vector<int> > &Mat)
{
	int m = Mat.size();
	int n = Mat[0].size();
	/*
	 *  Fill Base Case
	 *
	 */
	/*
	 *  Create S Matrix
	 *
	 *
	 */
	vector<vector<int> > S(Mat.size(),vector<int>(Mat[0].size(),0));
	for(int j = 0 ; j < n ; ++j)
	{
		S[0][j] = Mat[0][j];
	}

	for(int i = 0 ; i < m ; ++i)
	{
		S[i][0] = Mat[i][0];
	}

	for(int i = 1 ; i < m ; ++i)
	{
		for(int j = 1 ; j < n ; ++j)
		{
			if(Mat[i][j]==1)
			{
				S[i][j] = min(S[i-1][j-1],min(S[i][j-1],S[i-1][j]))+1;
			}
			else
			{
				S[i][j] = 0 ;
			}
		}
	}

	//cout<<S<<"\n\n";

	int maxSize = 0 ,end_i,end_j ;

	for(int i = 0 ; i < m ; ++i)
		for(int j = 0 ; j < n ;++j)
		{
			if(S[i][j] > maxSize)
			{
				maxSize = S[i][j] ;
				end_i = i ;
				end_j = j ;
			}
		}

	  cout<< maxSize <<" "<<end_i<<" "<<end_j<<"\n" ;
	for(int i = end_i ; i > end_i-maxSize ; --i )
	{
		for(int j = end_j ; j > end_j-maxSize ; --j)
		{
			cout<<" "<<Mat[i][j];
		}
		cout<<"\n";
	}
}

void driver()
{
	vector<vector<int> > Mat ;
	vector<int> row;
	int m , n ;
	cin >> m >> n;
	for(int i = 0 ; i < m ; ++i)
	{
		row.clear();
		for(int j = 0 ; j < n ; ++j)
		{
			int x ;
			cin>>x;
			row.push_back(x);
		}

		Mat.push_back(row);
	}

	cout<<Mat<<"\n";
	FindMaxiMumSizeSqureMatrixContainsAll1(Mat);
}
/* input.txt


6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0
 *
 *
 *
 */

int main(){
	driver();
	cout<<"\n";
	return 0;
}
