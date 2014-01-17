/*
 * ArrayJIMax.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/ArrayJIMax.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 7, 2014
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
// O(n^2)
class Solution
{
	public :
	int maxIndexDiff(int arr[], int n)
	{
	    int maxDiff = -1;
	    int i, j;

	    for (i = 0; i < n; ++i)
	    {
	        for (j = n-1; j > i; --j)
	        {
	            if(arr[j] > arr[i] && maxDiff < (j - i))
	                maxDiff = j - i;
	        }
	    }

	    return maxDiff;
	}
   
};
// o(n)
class Solution1
{
	public :
	int maxIndexDiff(int arr[], int n)
	{
	    int maxDiff;
	    int i, j;

	    int *LMin = (int *)malloc(sizeof(int)*n);
	    int *RMax = (int *)malloc(sizeof(int)*n);

	   /* Construct LMin[] such that LMin[i] stores the minimum value
	       from (arr[0], arr[1], ... arr[i]) */
	    LMin[0] = arr[0];
	    for (i = 1; i < n; ++i)
	        LMin[i] = min(arr[i], LMin[i-1]);

	    /* Construct RMax[] such that RMax[j] stores the maximum value
	       from (arr[j], arr[j+1], ..arr[n-1]) */
	    RMax[n-1] = arr[n-1];
	    for (j = n-2; j >= 0; --j)
	        RMax[j] = max(arr[j], RMax[j+1]);

	    /* Traverse both arrays from left to right to find optimum j - i
	        This process is similar to merge() of MergeSort */
	    i = 0, j = 0, maxDiff = -1;
	    while (j < n && i < n)
	    {
	        if (LMin[i] < RMax[j])
	        {
	            maxDiff = max(maxDiff, j-i);
	            j = j + 1;
	        }
	        else
	            i = i+1;
	    }

	    return maxDiff;
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
