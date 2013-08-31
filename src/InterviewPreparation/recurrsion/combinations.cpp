/*
 * combinations.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
using namespace std;
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
*/
vector<vector<int> > res;
int size,depth;
void combineHelper(int n,vector<int> &path){
    if(n>depth) return;
    if(path.size()>=k) return;
   combineHelper(n+1,path);
   path.push_back(n);
   if(path.size()==size){
   	   res.push_back(path);
      }
   combineHelper(n+1,path);
   path.pop_back();
}


vector<vector<int> > combine(int n, int k) {
        res.clear();
        size=k;
        depth=n;
        vector<int> path;
        combineHelper(1,path);
       return res;
    }
int main(){
	return 0;
}



