/*
 * LongestCommonSubString.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/spoj/DynamicProgramming/LongestCommonSubString.cpp -o /usr/build/Main.o
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
Link :-  
Question :-

First find the longest common suffix for all pairs of prefixes of the strings. The longest common suffix is


Longest Common Substring

 First Find Out Longest Common Suffixes of string

maintain Longest common Suffixes


 */
class Solution
{
public :

	int  LongestCommonSubString(string &s1 , string &s2)
	{
		int l1 = s1.size() ;
		int l2 = s2.size() ;
		int result = 0 ;

		vector<vector<int> > dp(l1+1,vector<int>(l2+1,0)) ;
		for(int i = 0 ; i<=l1 ;++i)
			for(int j = 0 ; j <=l2 ; j++)
			{
				if(i==0 || j==0) dp[i][j] = 0 ;
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j] = 1+dp[i-1][j-1] ;
					result = max(result,dp[i][j]);
				}
				else dp[i][j] = 0 ;
			}
		return result ;
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
