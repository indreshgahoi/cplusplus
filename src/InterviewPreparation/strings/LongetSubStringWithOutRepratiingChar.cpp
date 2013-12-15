/*
 * LongetSubStringWithOutRepratiingChar.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/LongetSubStringWithOutRepratiingChar.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 23, 2013
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
Link :- http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
Question :-

Given a string, find the length of the longest substring without repeating characters.
For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”,
with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are
two longest substrings shown in the below diagrams, with length 7.

 */

#define NO_OF_CHAR 256
#define DEBUG
class Solution
{
public :

	int LongestCommonSubString(string &str)
	{

		int size = str.size();
		int start = 0 , end = 0 ;
		int max_start=-1 ,max_end=-1 , max_len=-1 ;
		vector<int> map_char(NO_OF_CHAR,-1);

		while(end<size)
		{
			if(map_char[str[end]]!=-1 && start <map_char[str[end]]+1)
			{
				start= map_char[str[end]]+1 ;
			}

			if((end-start+1) >= max_len)
			{
				max_len = end-start+1 ;
				max_end = end ;
				max_start = start ;

			}
			map_char[str[end]]= end ;
			end++;
		}
		while(max_start <= max_end)
		{
			printf("%c",str[max_start++]);
		}
		cout<<"\n";

		return max_len ;
	}

};

void driver()
{
	Solution solver ;
	string str ;
	fstream fin("input.txt");
	while(fin>>str)
	{
		cout<<"Input ===> "<<str ;
		cout<<"\nOutput ===> ";
		int len = solver.LongestCommonSubString(str);
		printf("   length = %d \n",len);
	}
}
/*
 input.txt 
 ABDEFGABEF
 GEEKSFORGEEKS

 */
int main(){

	driver();
	cout<<"\n";
	return 0;
}
