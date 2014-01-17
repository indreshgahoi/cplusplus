/*
 * ArrayConvert.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/ArrayConvert.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 29, 2013
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


/*
 *
 *  Question :
 *  	Suppose we have an array a1, a2, ..., an, b1, b2, ..., bn. Implement an algorithm
         to change this array to a1, b1, a2, b2, ..., an, bn.
 *  p =1                  q= 8
 *     a1 a2 a3 a4 b1 b2 b3 b4
 *  step 1
 *    1  2  3  4     5  6  7  8         r 1+8 / 2 4
 *   (a1 a2 b1 b2) (a3 a4 b3 b4)       i = (1+4)/2 = 2  r+1 4+8/2 6
 *
 *
 */

void Rearrange(int A[] ,int p , int q)
{
	if( p != q)
	{

		int r = (p+q) / 2 ;
        int t = (r-p+1)/2 ;
		for(int i = 1; i <= t ; ++i)
		{

			swap(A[p+t+i-1],A[r+i]) ;
		}
		Rearrange(A,p,r);
		Rearrange(A,r+1,q);
	}
}




/*
 input.txt 

*/
int main(){
	int A[] = {1,2,3,4,5,6,7,8};
    printArray(A,8);
    Rearrange(A,0,7) ;
    printArray(A,8);

	cout<<"\n";
	return 0;
}
