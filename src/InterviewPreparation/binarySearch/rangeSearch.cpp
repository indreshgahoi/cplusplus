/*
 * rangeSearch.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binarySearch/rangeSearch.cpp -o /usr/build/Main.o
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


 0 1 2 3 4 5 6 7 8
 1 2 3 4 4 4 7 8 9   m = (0+9) / 2 = 4

 0 1 2 3 4    l = 0  r 4
 1 2 3 4 4       m = (0+4) / 2  = 2
       3 4      l= 3 r = 4
       4 4          4+3/2  3
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {

        int l , r ;
        int m ;
        vector<int> res ;
        l = 0 ;
        r = n-1 ;

        while( l < r)
        {
            m = l + (r-l)/2 ;

            if(A[m] < target)
            {
                r = m+1 ;
            }
            else
            {
                l = m ;
            }
        }
        res.push_back(l);

        return res ;
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
