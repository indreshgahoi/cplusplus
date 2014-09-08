/*
 * Adobe_MakePath.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/HeakerEarth/Adobe_MakePath.cpp -o /usr/build/Main.o
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

int arr[100005];
int level[100005];
int parent = - 1 ;

int setLevel(int x) {
	if (x == 0){
		return  0 ;
	}
    if (level[x] != -1)
		return level[x];
	level[x] = setLevel(arr[x-1]) + 1;
	return level[x];
}

void solve() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	for (int i = 0; i <= n; ++i) {
		level[i] = -1;
	}

    long long int handShake = 0l ;
    long long int bumps = 0l ;
	for(int i = 1 ; i <= n ; ++i){
		if(level[i] == -1){
			setLevel(i) ;
		}
	}
	for( int i = 1 ; i <= n ; ++i){
		handShake += (level[i] -1);
	}


	 printf("%lld %lld\n",handShake,(((long long int)n)*(n-1)/2) - handShake);

}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
