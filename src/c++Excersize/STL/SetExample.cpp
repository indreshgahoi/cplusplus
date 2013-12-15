/*
 * SetExample.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/c++Excersize/STL/SetExample.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 24, 2013
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


struct info
{
	int x ;
	int frequency ;
    int operator < (const info &y) const
    {
    	return x<y.x ;
    }
};

class Solution
{
	public :

	void setExample1()
	{
		set<info> myset;
		info i ;
		i.x = 3 ;
		i.frequency = 4 ;
		myset.insert(i);
	}
   
};
void driver()
{
 // fstream fin("input.txt");
  Solution solver ;
  solver.setExample1();
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
