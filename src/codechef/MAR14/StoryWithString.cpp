/*
 * StoryWithString.cpp
 *
 *  Created on: Mar 10, 2014
 *      Author: indresh
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int> > dp(2, vector<int>(s2.size() + 1));
	int end = -1 ;
	int maxLen = -1 ;
	for(int i = 0 ; i <= s1.size() ;++i ){
     for(int j = 0 ; j <= s2.size() ; ++j){
    	 if(i==0 || j==0) dp[i&1][j] = 0 ;
    	 if(s1[i-1]==s2[j-1])
    	 {
    		 dp[i&1][j] = dp[1-(i&1)][j] + 1 ;
    		 if(dp[i][j]>maxLen){maxLen = dp[i][j] ;end = j-1 ; }
    		 else dp[i][j] = 0 ;
    	 }
     }
	}

}

