/*
 * XorTree.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codeforces/XorTree.cpp -o /usr/build/Main.o
 *
 *  Created on: May 24, 2014
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

struct Node{
 int id ;
 int val ;
 vector<int> children ;
};

vector<Node> * tree ;
vector<int> sol ;
int main(){

  int n ;

  cin >> n ;

  tree = new vector<Node>(n+1);
  sol.reserve(n+1);

  int u , v ;
  for(int i = 1 ; i < n ; i++){
	  cin >> u >> v ;
	  tree->at(u).children.push_back(v);
  }

  int val ;

  for(int i = 1; i < n+1 ; ++i){
	  cin >> val ;
	  tree->at(i).val = val ;
	  tree->at(i).id = i ;
  }

  for(int i = 1; i < n+1 ; ++i){
	  cin>>sol[i];
  }


}
