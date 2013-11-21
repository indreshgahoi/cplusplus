/*
 * MaxiSumWindowSubString.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/MaxiSumWindowSubString.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
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
Link :-  http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
Question :- Finding the Minimum Window in S which Contains All Elements from T
  Given a set T of characters and a string S, find the minimum window in S which will contain all the characters in T in complexity O(n).

eg,
S = “ADOBECODEBANC”
T = “ABC”

Minimum window is “BANC”
  
*/

#define NO_OF_CHAR 256

int minimumWindowSize(string &s , string &t ,int &l ,int &r)
{
	int targetMap[NO_OF_CHAR] ={0} ;
	int currentWindowMap[NO_OF_CHAR] = {0} ;
	for(int i = 0 ; i < t.size() ; ++i)
	{
		targetMap[t[i]]++;
	}
    l=r=-1 ;
	int min_size = INT_MAX ;
	int start = 0 , end=0 ;
    int foundNoOfChar = 0 ;

  for(start = 0 , end = 0 ; end < s.size(); end++)
	{
		// current char is not candidate the continue
		if(targetMap[s[end]]==0)
		   continue ;

		currentWindowMap[s[end]]++;
		if(currentWindowMap[s[end]] <= targetMap[s[end]])
		{
			foundNoOfChar++;
		}

		if(t.size()==foundNoOfChar)
		{
			// minimize the size of window

			while(targetMap[s[start]]==0 || currentWindowMap[s[start]]>targetMap[s[start]])
			{
				if(currentWindowMap[s[start]]> targetMap[s[start]])
				{
					currentWindowMap[s[start]]-- ;

				}

				start++ ;
			}

			if((end-start+1) < min_size)
			{
				min_size = end-start+1 ;
				l=start ;
				r=end ;
			}
		}

	}
 return min_size ;
}


void driver()
{
  string s,t ;
  int min ;
  int c = 0 ;
  fstream fin("input.txt");
   fin>>s;
   fin>>t;

  int l,r ;
  min = minimumWindowSize(s,t,l,r);
  cout<<"abs= "<<min<<"\n";
  if(l!=-1 && r!=-1)
  {
	  for(int i=l ; i <= r ; ++i)
	  {
		  cout<<s[i];
	  }
	  cout<<"\n";
  }
}
/*
 input.txt 

ADOBECODEBANC
ABC

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
