/*
 * DishOwner.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10002
int S[MAX];
int P[MAX];
int MS[MAX];
int rank[MAX];

int find_owner(int x) {
	if( x != P[x] )
		P[x] = find_owner(P[x]);
	return P[x];
}

void match(int x, int y) {
	int ox = find_owner(x);
	int oy = find_owner(y);
	if (ox == oy) {
		puts("Invalid query!");
		return;
	}
	if (S[MS[oy]] == S[MS[ox]])
		return;
	if (rank[ox] < rank[oy]) {
		P[ox] = oy;
		if (S[MS[oy]] < S[MS[ox]]) {
			MS[oy] = MS[ox];
		}
	} else  {
		P[oy] = ox;
		if (S[MS[oy]] > S[MS[ox]]) {
			MS[ox] = MS[oy];
		}
		if(rank[ox]==rank[oy]){
			rank[ox] = rank[ox] + 1;
		}
	}


}
int main() {
	int T, N, Q, t, x, y;

	scanf("%d",&T);
	while (T--) {
		scanf("%d",&N);
		N++;
		for (int i = 1; i < N; ++i) {
			scanf("%d",&S[i]);
			P[i] = i;
			MS[i] = i;
			rank[i] = 0;
		}
		scanf("%d",&Q);
		for (int i = 0; i < Q; ++i) {
			scanf("%d",&t);
			if (t==0) {
				scanf("%d%d",&x,&y);
				match(x, y);
			} else {
				scanf("%d",&x);
				printf("%d\n",MS[find_owner(x)]);
			}
		}

	}
	return 0;
}

