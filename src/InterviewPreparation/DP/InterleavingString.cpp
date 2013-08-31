/*
 * InterleavingString.cpp
 *
 *  Created on: Mar 13, 2013
 *      Author: indresh
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s1,s2,s3;
int    l1,l2,l3;
bool ***dp;
void solve(){

}

bool init(){
	//string s1,s2,s3;
	int    l1,l2,l3;
	//cin>>s1>>s2>>s3;

	s1="$"+s1;
	s2="$"+s2;
	s3="$"+s3;
	l1=s1.length();
	l2=s2.length();
	l3=s3.length();
	if((l1+l2-1)!=l3)return false;
	vector<vector<bool> > dp(2,vector<bool>(l2,false));

   for(int j=0;j<l3 && j<l2;j++)
	   dp[0][j]=dp[0][j]||(s3[j]==s2[j]);
	for(int i=1;i<l1;i++){
		int t=i%2;
       for(int j=0;j<l2;j++){
    	   dp[t][j]=false;
    	   if(j==0)
    		   dp[t][j]=dp[t][j]||(s1[i]==s3[0]);
		  if(s1[i]==s3[i+j]) dp[t][j]=dp[t][j]||dp[abs(t-1)][j];
		  if(s2[j]==s3[i+j]) dp[t][j]=dp[t][j]||dp[t][j-1];
		}
	}

	return dp[(l1-1)%2][l2-1.];
}
int main(){

	return 0;
}
