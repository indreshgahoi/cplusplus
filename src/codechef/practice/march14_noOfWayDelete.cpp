/*
 * march14_noOfWayDelete.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codechef/practice/march14_noOfWayDelete.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 28, 2014
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
   for(int i=0;i<static_cast<int>(size-1);i++)
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

	vector<int> A ;
	int result ;
	void input()
	{
		int n,x ;
		cin>>n;
		for(int i=0;i<n ; i++)
			{
				cin>> x ;
				A.push_back(x);
			}

	}
    void reset()
    {
    	A.clear();
    }

    void solve()
	{
    	static const int MOD = 10e8+7 ;
    	int maxElement = A[0] ;
    	int maxCount = 1 ;
         for(size_t i = 1 ; i<A.size();++i)
         {
        	 if(maxElement==A[i]) maxCount++;
        	 if(A[i]>maxElement)
        	 {
        		 maxElement = A[i];
        		 maxCount = 1;
        	 }
         }
       result = 2 ;

       for(int i=1;i;maxCount>>=1)
       {
    	   result=(result*result)%MOD ;
    	   if(maxCount&1)
    		   result = (result<<1)%MOD ;
       }
       result = result -1 ;

	}

	void output()
	{
		cout<<result<<std::endl;
	}
   
};

/*
 input.txt 

*/
int main(){
	Solution solver ;

 int t ;
 cin>>t ;
 while(t--)
 {
	 solver.reset();
	 solver.input();
	 solver.solve();
	 solver.output();
 }
	return 0;
}
