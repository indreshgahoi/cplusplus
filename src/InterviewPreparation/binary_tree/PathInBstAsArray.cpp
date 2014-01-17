/*
 * PathInBstAsArray.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/PathInBstAsArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 25, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include <limits.h>
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
   
	size_t find_next_root_index(const vector<int> &V ,size_t start,int miN,int maX)
	{
		size_t result =  V.size() ;

		if(start < V.size())
		{
			for(size_t it = start ; it < V.size() ; ++it)
			{
				if(V[it] > miN && V[it] < maX)
				{
					result = it ;
					break ;
				}
			}
		}
		return result ;
	}


	void print_path(const vector<int> &V , int dest)
	{
		int miN = INT_MIN  ;
		int maX = INT_MAX  ;
		size_t root = 0 ;
		size_t curr = root ;
		vector<char> path ;
		while(root < V.size())
		{
			if(V[root] < dest)
			{
				path.push_back('R') ;
				miN = V[root] ;
				curr = find_next_root_index(V,root+1,miN,maX);
			}
			else if(V[root] > dest)
			{
				path.push_back('L') ;
				maX = V[root] ;
				curr = find_next_root_index(V,root+1,miN,maX);
			}
			else
			{
				cout<<"\n "<<path;
				return ;
			}
			if(curr==V.size())
			{
				break ;
			}
			else
			{
				printf("%d ",V[root]) ;
				root = curr ;
			}

		}
		cout<<" \n There in NO Path" ;
	}


};
void driver()
{
  fstream fin("input.txt");	
  vector<int> input ;
  int x ;
  while(fin>>x)
  {
	  input.push_back(x) ;

  }
  int dest = input.back();
  input.pop_back();
  Solution solver ;
  solver.print_path(input,dest) ;
}
/*
 input.txt 
 2 7 1 10 4 5 3 12 1
 2 6  4 7 1 10 3 12  12
 2 7 4 10 5 3 6 6
 10 14 7 6 15 13 8 3 3
 2 10 8 9 15 5 6 11  3 4  6

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
