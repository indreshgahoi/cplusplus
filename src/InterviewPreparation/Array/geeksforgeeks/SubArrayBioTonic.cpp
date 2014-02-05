/*
 * SubArrayBioTonic.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/SubArrayBioTonic.cpp -o /usr/build/Main.o
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
	public :
   
};

int bitonic(int arr[], int n)
{
    int i;
    int *inc = new int[n];
    int *dec = new int[n];
    int max;
    inc[0] = 1; // The length of increasing sequence ending at first index is 1
    dec[n-1] = 1; // The length of increasing sequence starting at first index is 1

    // Step 1) Construct increasing sequence array
    for(i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
            inc[i] = inc[i-1] + 1;
        else
            inc[i] = 1;
    }

    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    {
        if (arr[i] > arr[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }

    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
        {
            max = inc[i] + dec[i] - 1;
        }
    }

    // free dynamically allocated memory
    delete [] inc;
    delete [] dec;

    return max;
}

class Solution1
{

public :
	int maxLengthBioTanicSubArray(vector<int> &numList)
	{
		int size= numList.size();
		vector<int> incSeq(size,1);
		vector<int> decSeq(size,1);

		for(int i = 1; i<size;++i)
		{
			if(numList[i-1]<numList[i])
				incSeq[i]=incSeq[i-1]+1 ;
		}
		for(int i=size-2;i>=0;--i)
		{
			if(numList[i]>numList[i+1])
				decSeq[i]=decSeq[i+1]+1;
		}
		int maxLen = incSeq[0]+decSeq[0]-1;

		for(int i = 1 ;i<size;++i)
		{
			if((incSeq[i]+decSeq[i]-1)>maxLen)
			{
				maxLen = incSeq[i]+decSeq[i]-1 ;
			}
		}
		return maxLen ;
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
