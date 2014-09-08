/*
 * Adobe_Chal.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/HeakerEarth/Adobe_Chal.cpp -o /usr/build/Main.o
 *
 *  Created on: Apr 12, 2014
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






void solve(){

	int n , m ;
	scanf("%d%d",&n,&m);

	map<int,pair<int,int> > pos ;
	int x ;
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			scanf("%d",&x);
			pair<int,int> p(i,j) ;
			pos[x] =  p ;
		}
	}

	int Q ;
	scanf("%d",&Q);

	for(int i = 1 ; i <= Q ; ++i){
		scanf("%d",&x);
		map<int,pair<int,int> >::iterator it = pos.find(x) ;
		if(it != pos.end()){
			pair<int,int> p = it->second ;
			printf("%d %d\n",p.first,p.second) ;

		}else{
			printf("-1 -1\n");
		}
	}

}


int main(){
	solve();
	return 0 ;
}

