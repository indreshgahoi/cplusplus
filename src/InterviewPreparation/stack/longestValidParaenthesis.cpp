/*
 * longestValidParaenthesis.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/stack/longestValidParaenthesis.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

typedef int Integer ;

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
Link :-  http://discuss.leetcode.com/questions/212/longest-valid-parentheses
Question :-
	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
  
  
*/

int longestValidParentheses(string str)
{
	int size = str.size();
	int maximum=-10e9 ,last;
	stack<char> st ;
	for(int i = 0 ; i < size() ;++i)
	{
		if(str[i]=='(')
		{
			st.push(i);
		}
		else
		{
			if(st.empty())
			{
				last = i ;
			}
			else
			{	// ( pop corresponding char
				st.pop();
				if(st.empty())
				{
					maximum = max(maximum,i-last);
				}
				else
				{
					maximum = max(maximum,i-st.top());
				}
			}
		}
	}
	return maximum ;
}




void driver()
{
 
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
