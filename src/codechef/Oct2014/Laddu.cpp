/*
 * Laddu.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include <bitset>
#include<algorithm>
using namespace std;

long long int MOD = 1000000009 ;

//long long int pow(long long int x, long long int n) {
//	if (n == 0)
//		return 1;
//	long long int t = pow(x, n / 2);
//	t = (t * t) % MOD;
//	if (n & 1)
//		return (t * x) % MOD;
//
//	return t;
//}
struct colorInfo {
	int idx;
	char color[2];
};

struct IndexSorter {

	int operator()(const colorInfo &cl1, const colorInfo &cl2) {
		return cl1.idx < cl2.idx;
	}
};

vector<colorInfo> colorList;
void solve() {
	int N, M;
	char ch[2];
	colorList.clear();
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		colorInfo in;
		scanf("%s%d", in.color, &in.idx);
		colorList.push_back(in);
	}
	sort(colorList.begin(), colorList.end(), IndexSorter());
	long long int way = 1;
	int preIdx = colorList[0].idx;
	char lastColor = colorList[0].color[0] ;
	for (int i = 1; i < M; ++i) {
		long long int currentWay = 1 ;
		if(lastColor != colorList[i].color[0]){
			currentWay = colorList[i].idx - preIdx ;
		    way = (way * currentWay) % MOD;
		}
		preIdx = colorList[i].idx;
		lastColor = colorList[i].color[0];
	}
	printf("%lld\n", way);
}

int main() {
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt","wt",stdout);
			int T;
			scanf("%d",&T);
			while (T--) {
				solve();
			}
			return 0;
		}

