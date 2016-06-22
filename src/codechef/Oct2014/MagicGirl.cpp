/*
 * MagicGirl.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int R, G, B, M, Rmax, Gmax, Bmax;

int main() {
	//freopen("input.txt","rt",stdin);
		//freopen("output.txt","wt",stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &R, &G, &B, &M);
		Rmax = Gmax = Bmax = 0;
		int x;
		for (int i = 0; i < R; ++i) {
			scanf("%d", &x);
			Rmax = max(Rmax, x);
		}
		for (int i = 0; i < G; ++i) {
			scanf("%d", &x);
			Gmax = max(Gmax, x);
		}
		for (int i = 0; i < B; ++i) {
			scanf("%d", &x);
			Bmax = max(Bmax, x);
		}
		int currMax ;
		while(M--){
			currMax = max(Rmax,max(Gmax,Bmax));
			if(currMax==Rmax){
				Rmax=Rmax/2 ;
			}else if(currMax==Gmax){
				Gmax=Gmax/2 ;
			}else {
				Bmax=Bmax/2 ;
			}
		}
		printf("%d\n",max(Rmax,max(Gmax,Bmax)));
	}
	return 0;
}

