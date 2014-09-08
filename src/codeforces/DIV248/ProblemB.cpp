/*
 * ProblemB.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codeforces/DIV248/ProblemB.cpp -o /usr/build/Main.o
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


int main(){
	int n ;
	scanf("%d",&n);
	vector<long long> a1 , a2 ;
	long long val ;
	a1.push_back(0);

	for(int i = 0 ; i < n ; ++i){
		cin>> val ;
		a1.push_back(val);
	}
	a2 = a1 ;
	sort(a2.begin()+1,a2.end());
	for(int i = 1;i <= n ;++i){
		a1[i] = a1[i]+a1[i-1];
		a2[i] = a2[i]+a2[i-1];
	}

	int q ;
	scanf("%d",&q);
	long long res ;
	int type,l , r ;
	for(int i = 0 ; i < q ; ++i){
		scanf("%d%d%d",&type,&l,&r);
		switch(type){
		case 1 :
			res = a1[r]-a1[l-1];
			break ;
		case 2 :
			res = a2[r] - a2[l-1] ;
			break ;
		}
		cout<<res<<"\n";
	}
	return 0 ;
}
