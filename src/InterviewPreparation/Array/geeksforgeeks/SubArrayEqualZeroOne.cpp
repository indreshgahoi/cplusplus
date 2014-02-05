/*
 * SubArrayEqualZeroOne.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/SubArrayEqualZeroOne.cpp -o /usr/build/Main.o
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
class Solution
{

int findSubArray(int arr[], int n)
{
    int maxsize = -1, startindex;  // variables to store result values

    // Create an auxiliary array sunmleft[]. sumleft[i] will be sum of array
    // elements from arr[0] to arr[i]
    int sumleft[n];
    int min, max; // For min and max values in sumleft[]
    int i;

    // Fill sumleft array and get min and max values in it.
    // Consider 0 values in arr[] as -1
    sumleft[0] = ((arr[0] == 0)? -1: 1);
    min = arr[0]; max = arr[0];
    for (i=1; i<n; i++)
    {
        sumleft[i] = sumleft[i-1] + ((arr[i] == 0)? -1: 1);
        if (sumleft[i] < min)
            min = sumleft[i];
        if (sumleft[i] > max)
            max = sumleft[i];
    }

    // Now calculate the max value of j - i such that sumleft[i] = sumleft[j].
    // The idea is to create a hash table to store indexes of all visited values.
    // If you see a value again, that it is a case of sumleft[i] = sumleft[j]. Check
    // if this j-i is more than maxsize.
    // The optimum size of hash will be max-min+1 as these many different values
    // of sumleft[i] are possible. Since we use optimum size, we need to shift
    // all values in sumleft[] by min before using them as an index in hash[].
    int hash[max-min+1];

    // Initialize hash table
    for (i=0; i<max-min+1; i++)
        hash[i] = -1;

    for (i=0; i<n; i++)
    {
        // Case 1: when the subarray starts from index 0
        if (sumleft[i] == 0)
        {
           maxsize = i+1;
           startindex = 0;
        }

        // Case 2: fill hash table value. If already filled, then use it
        if (hash[sumleft[i]-min] == -1)
            hash[sumleft[i]-min] = i;
        else
        {
            if ( (i - hash[sumleft[i]-min]) > maxsize )
            {
                maxsize = i - hash[sumleft[i]-min];
                startindex = hash[sumleft[i]-min] + 1;
            }
        }
    }
    if ( maxsize == -1 )
        printf("No such subarray");
    else
        printf("%d to %d", startindex, startindex+maxsize-1);

    return maxsize;
}

};

// o(n^2) solution
class Solution1
{
	public :

	int largestSubArrySum(int A[],int n)
	{
	 int maxSize = 0 , startIdx = -1 ;
	 int count = 0 ;
	 for(int i = 0 ; i<n-1;++i)
	 {
		 count = A[i]==0 ? 1 : -1 ;
		 for(int j=i+1 ;j<n;++j)
		 {
			 A[i]==0 ? count+=1 :count-=1;

			 if(count==0 && maxSize < (j-i+1))
			 {
				 maxSize = j-i+1 ;
				 startIdx = i ;
			 }
		 }
	 }
	 return maxSize ;
	}
   
};

class Solution2
{
public :
	int largestmaxSubArrayWithSum(int A[],int n)
	{
		int maxSize = 0 ;
		int startIdx = -1;
		int preFixSum[n] ;
		preFixSum[0] = A[0]==0 ? 1 :-1;
		int max = A[0],min = A[0] ;
		for(int i = 1 ; i<n;++i)
		{
			preFixSum[i]=preFixSum[i-1] +(A[i]==0)?1:-1 ;
	        if(max<preFixSum[i])
	        {
	        	max=preFixSum[i];
	        }
	        if(min>preFixSum[i])
	        {
	        	min = preFixSum[i] ;
	        }
		}

		int sumHash[max-min+1] ;

		for(int i=0 ;i<max-min+1;++i)
		{
			sumHash[i] = -1 ;
		}

		for(int i = 0 ; i<n ; ++i)
		{
			if(preFixSum[i]==0 )
			{
				maxSize = i+1 ;
				startIdx = 0 ;
			}
			if(sumHash[preFixSum[i]-min]==-1)
			{
				sumHash[preFixSum[i]-min] = i ;
			}
			else
			{
				if(i-sumHash[preFixSum[i]-min]>maxSize)
				{
					maxSize = i-sumHash[preFixSum[i]-min] ;
					startIdx= i+1 ;
				}
			}
		}
		return maxSize ;
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
