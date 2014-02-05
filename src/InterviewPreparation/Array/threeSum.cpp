/*
 * threeSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/Sort/threeSum.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 20, 2014
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
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        int targetSum = 0 ;
        int size = num.size() ;
        vector<vector<int> > res ;

        sort(num.begin(),num.end()) ;
        for(int i = 0 ; i<size-2 ;++i)
        {
        	int l = i+1 ;
        	int r= size-1 ;
            if(i>0 && num[i-1]==num[i]) continue ;
        	while(l<r)
        	{
        		int t = num[i]+num[l]+num[r] ;
               if(t==0)
               {
            	   vector<int> triplet ;
            	   triplet.push_back(num[i]) ;
            	   triplet.push_back(num[l]);
            	   triplet.push_back(num[r]) ;
            	   res.push_back(triplet) ;
            	  do
            	  {
            	   l++ ;
            	  }while(l<r && num[l-1]==num[l]) ;
            	  do
            	  {
            	   r-- ;
            	  }while(l<r && num[r]==num[r+1]) ;
               }
               else if(t < 0)
               {
            	   l++ ;
               }
               else
               {
            	   r-- ;
               }

        	}
        }
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
