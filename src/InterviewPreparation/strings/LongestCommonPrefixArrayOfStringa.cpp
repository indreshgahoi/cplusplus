/*
 * LongestCommonPrefixArrayOfStringa.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/LongestCommonPrefixArrayOfStringa.cpp -o /usr/build/Main.o
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
Link :-  http://tianrunhe.wordpress.com/tag/string/
Question :-
	Find the longest common prefix in an array of strings (Longest Common Prefix)

    Write a function to find the longest common prefix string amongst an array of
    strings.

Thoughts:
Apparently this can be done in O(n). We start with the first string as the longest
common prefix. We then go through every string in the array and compare the prefix
with them. Update (shorten) the prefix if needed.
  
  
*/

string LongestCommonPreFix(vector<string> &str)
{
	int size = str.size();
	string prefix = str[0];
	for(int i = 1 ; i < size() ; ++i)
	{
		int j = 0;
		for(j = 0 ; j < min(str[i].size(),prefix.size()) ; ++j)
			if(str[i][j]!=prefix[j])
				break ;
		prefix = str[i].substr(0,j);
	}
	return prefix ;
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
