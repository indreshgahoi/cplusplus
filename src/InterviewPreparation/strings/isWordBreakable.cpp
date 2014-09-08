/*
 * isWordBreakable.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std ;
class Solution {
public:

	bool wordBreak(string s, unordered_set<string> &dict) {
    	if(!s.size()) return true ;
    	for(size_t i = 1 ; i <= s.size() ; ++i){
    		if(dict.find(s.substr(0,i)) != dict.end() && wordBreak(s.substr(i,s.size()-1),dict)){
    			return true ;
    		}
    	}
    	return false ;
    }
};

class Solution2 {

public :
	bitset bset ;
	bitset isSolved ;
	bool wordBreakHelper(string &s,size_t start, unordered_set<string> &dict) {
	    	if(start==s.size()){
	    		return true ;
	    	}
	    	if(isSolved[start]){
	    		return bset[start];
	    	}
	    	for(size_t i = start+1 ; i <= s.size() ; ++i){
	    		if(dict.find(s.substr(start,i)) != dict.end() && wordBreakHelper(s,i,dict)){
	    			return true ;
	    		}
	    	}
	    	isSolved[start] = 1 ;
	    	return bset[start]=false ;

	}
	bool wordBreak(string s, unordered_set<string> &dict){
		bset = new bset(s.size()+1);

	}
};

int main(){
	Solution sol ;
	unordered_set<string> dict = {"leet","code"};
	string word = "leetcode";
	if(sol.wordBreak(word,dict)){
		printf("YES");
	}else {
		printf("NO");
	}
	return 0 ;
}


