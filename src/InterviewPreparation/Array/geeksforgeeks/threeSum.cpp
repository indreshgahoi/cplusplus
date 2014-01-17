/*
 * threeSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/threeSum.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 30, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
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
/*
Link :-  
Question :-
  
  
*/


// o(n^3) method

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;

    // Fix the first element as A[i]
    for (int i = 0; i < arr_size-2; i++)
    {
       // Fix the second element as A[j]
       for (int j = i+1; j < arr_size-1; j++)
       {
           // Now look for the third number
           for (int k = j+1; k < arr_size; k++)
           {
               if (A[i] + A[j] + A[k] == sum)
               {
                 printf("Triplet is %d, %d, %d", A[i], A[j], A[k]);
                 return true;
               }
           }
       }
    }

    // If we reach here, then no triplet was found
    return false;
}


struct triplet
{
	int first ;
	int second ;
	int third ;
};

typedef struct triplet Triplet ;
class Solution
{
	public :

	Triplet threeSum(int *numberList , int size , int targetSum)
	{
		struct triplet resultTriplet;
		resultTriplet.first = -1 ;
		resultTriplet.second = -1 ;
		resultTriplet.third = -1 ;
		std::sort(numberList , numberList + size) ; // nlogn

		for( int iter = 0 ; iter < size-2 ; ++iter) // n^2
		{
			int leftIndex = iter+1 ;
			int rightIndex = size-1 ;
			while( leftIndex < rightIndex )
			{

				if(numberList[leftIndex] + numberList[rightIndex] + numberList[iter]  == targetSum)
				{
					resultTriplet.first = iter ;
					resultTriplet.second = leftIndex ;
					resultTriplet.third = rightIndex ;
					return resultTriplet ;
				}

				else if( targetSum > numberList[leftIndex] + numberList[rightIndex] +numberList[iter])
					rightIndex-- ;
				else
					leftIndex++ ;
			}
		}
		return resultTriplet ;
	}


};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
