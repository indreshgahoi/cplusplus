/*
 * StringGeneration.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/recurrsion/StringGeneration.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 27, 2013
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
class Timer
{
public:
	Timer()
	{
		_ela = 0 ;
		_start = clock();
	}

	long long int elapsed()
	{
		 _ela = clock() -_start ;
		_start = clock();
		cout<<"elapsed time = "<<  _ela/CLOCKS_PER_SEC;
		return _ela/CLOCKS_PER_SEC;
	}
	void start()
	{
		_start = clock();
	}
	void stop()
	{
		 _ela = clock() -_start ;
	}
	void reset()
	{
		_start = clock();
	}

private :
 clock_t _start ;
 long long int _ela ;
};
class Solution
{
	public :
   
	 void string_generate_function(vector<char> &list, vector<char> &path ,int n)
	 {
        if(path.size()==n)
        {
        	cout<<path ;
        	return ;
        }

        for(int i = 0 ; i < list.size() ; i++)
        {
             path.push_back(list[i]) ;
              string_generate_function(list,path,n) ;
             path.pop_back() ;
        }
	 }

};
void driver()
{
  fstream fin("input.txt");	
  vector<char> input ;
  input.push_back('a') ; input.push_back('b') ;input.push_back('c') ;input.push_back('d') ;
  input.push_back('e') ;input.push_back('f') ;input.push_back('g') ;input.push_back('h') ;
  input.push_back('i') ;input.push_back('j') ; //input.push_back('k') ;input.push_back('l') ;
//  input.push_back('m') ;input.push_back('n') ;input.push_back('o') ;input.push_back('p') ;input.push_back('q') ;
//  input.push_back('r') ;input.push_back('s') ;input.push_back('t') ;input.push_back('u') ;
//  input.push_back('v') ;input.push_back('w') ;input.push_back('x') ;input.push_back('y') ;
//  input.push_back('z') ;
  Solution solver ;
  vector<char> path ;
  int n = 7 ;
  Timer t  ;
  t.start() ;
  solver.string_generate_function(input,path,n) ;
  t.elapsed() ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
