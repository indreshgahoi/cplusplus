/*
 * ArrayOfProductsOfAllOtherNumber.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/ArrayOfProductsOfAllOtherNumber.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 26, 2013
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
Link :-  http://tianrunhe.wordpress.com/category/other-interview-questions/
Question :-
Array of products of all other numbers
>>>>
Given an array A of size N, return another resulting array B of the same size N, where B[i] is the products of all numbers in A except for A[i].
EXAMPLE:
INPUT: A = [1,2,3,4]
OUTPUT: B = [24, 12, 8, 6]
  
  
*/
class Solution
{
	public :

	vector<int>& getProductOfNumbers(vector<int> &V)
	{
		size_t n = V.size() ;
		vector<int> &result = *new vector<int>(n) ;
		result[0] = 1 ;

		for(size_t it = 1 ; it < V.size() ; ++it)
		{
		   result[it] = result[it-1] * V[it-1]  ;
		}
		int temp = 1 ;
		for(int it = V.size()-1 ; it>=0 ; --it)
		{
			result[it] = temp * result[it] ;
			temp = temp*V[it] ;
		}
		return result ;
	}
   
};
void driver()
{
  fstream fin("input.txt");
  vector<int> input ;
  int x ;
  while( fin>>x)
  {
	  input.push_back(x);
  }
  Solution solver ;
  cout<<" "<< input ;
  input = solver.getProductOfNumbers(input) ;
  cout<<" "<< input ;
}
/*
 input.txt 
 1 2 3 4 5 6
*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
