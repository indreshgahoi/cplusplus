/*
 * FixedPointInArray.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binarySearch/FixedPointInArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 21, 2014
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

// we can perform Linear Search
class Solution
{
	public :

	int FixedPoint(vector<int> &list)
	{
		int resIdx = -1 ;

		for(int i = 0 ; i<list.size();++i)
		{
			if(list[i]==i)
			{
				resIdx= i;
				break ;
			}
		}
		return resIdx;
	}
   
};


// using BinarySearch

class Solution1
{
public:

	int BinarySearchUtil(vector<int> &list,int low,int high)
	{
		if(low<=high)
		{
			int mid = low +(high-low)/2 ;
			if(list[mid]==mid) return mid ;
			if(mid>list[mid])
				return BinarySearchUtil(list,mid+1,high);
			return BinarySearchUtil(list,low,mid-1);
		}
		return -1 ;
	}

	int FixedPoint(vector<int> &list)
	{
      return BinarySearchUtil(list,0,list.size()-1);
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
