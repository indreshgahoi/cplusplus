/*
 * subset.cpp
 *
 *  Created on: Mar 17, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> > res;
void subsetsWithDupHelper(vector<int> &S,int start,vector<int> path) {
  res.push_back(path);
   for(int i=start;i<S.size();i++){
	   if(i!=start && S[i]==S[i-1]) continue;
	   path.push_back(s[i]);
	   subsetsWithDupHelper(S,i+1,path);
	   path.pop_back();
   }

}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
 res.clear();
 sort(S.begin(),S.end());
 subsetsWithDupHelper(S,0,vector<int>());
 return res;
}

int main(){
	return 0;
}
