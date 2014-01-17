/*
 * BalanceLeftRightSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/BalanceLeftRightSum.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 18, 2013
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

	int getRightSum(int index,int leftSum , const vector<int> &V,int &K)
	{
		if(index>=V.size()) return 0 ;
		int rightSum =  getRightSum(index+1,leftSum+V[index],V,K) ;
		if(leftSum==rightSum)
		{
			K = index ;
		}
		return rightSum + V[index] ;
	}


	int partition(const vector<int> &V)
	{
        int result = -1 ;
        getRightSum(0,0,V,result) ;
        return result ;
	}
   
};
void driver()
{
  fstream fin("input.txt");	
  vector<int> input;
  int x;
  while(fin>> x)
  {
	  input.push_back(x);
  }
  cout<<input ;
  Solution solver ;
  int result = solver.partition(input) ;
  debug(result) ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
