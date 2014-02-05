/*
 * printAllPerMutationRepetition.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/printAllPerMutationRepetition.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 19, 2014
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
Link :-  http://www.geeksforgeeks.org/print-all-permutations-with-repetition-of-characters/
Question :-
Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order
Examples:

Input: AB
Ouput: All permutations of AB with repetition are:
      AA
      AB
      BA
      BB

Input: ABC
Output: All permutations of ABC with repetition are:
       AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC

For an input string of size n, there will be n^n permutations with repetition allowed. The idea is to fix the first character at first index and recursively call for other subsequent indexes. Once all permutations starting with the first character are printed, fix the second character at first index. Continue these steps till last character. Thanks to PsychoCoder for providing following C implementation.
  
  
*/
class Solution
{
	public :
   
	void printPremutation(string &str,vector<char> &path)
	{
		if(str.size()==path.size())
		{
			cout<<path ;
			return ;
		}
		for(int i = 0 ; i <str.size();++i)
		{
			path.push_back(str[i]) ;
			printPremutation(str,path);
			path.pop_back() ;
		}
	}

	void printPermutationWithRepetition(string &str)
	{
		vector<char> path ;
		std::sort(str.begin(),str.end()) ;
		printPremutation(str,path) ;
	}
};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
  string str ;
  while(fin>>str)
  {
	  solver.printPermutationWithRepetition(str) ;
  }
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
