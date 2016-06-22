/*
 * LittleElephantandAlcohol.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: indresh
 */
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;
#define MAX_INT 9999999
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define si(i)      int i; scanf("%d",&i);
#define gi(i)      scanf("%d",&i);
#define SET(x,a) memset(x,a,sizeof(x));
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF 100000000000000000LL
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define f first
#define s second
typedef long long LL;

int a[18];
int t[18];
int main() {
#ifndef ON_LINE_JUDGE
	// freopen("input.txt","rt",stdin);
	//  freopen("output.txt","wt",stdout);
#endif
	si(T)
	while (T--) {
		si(n)
		si(k)
		si(m)
		REP(i,n)
			gi(a[i])
		int miN = MAX_INT;
		FOR(i,0,(1<<n))
		{
			FOR(p,0,n)
				t[p] = a[p];

			int step = 0;
			for (int j = 0; j < n; j++)
				if ((i & (1 << j))) {
					t[j]++;
					step++;
				}
			for (int i = 0; i < n - k + 1; i++) {
				int maX = -1;
				for (int j = i; j < i + k; j++)
					maX = max(maX, t[j]);
				int cnt = 0;
				for (int j = i; j < i + k; j++)
					if (t[j] == maX)
						cnt++;
				if (cnt >= m) {
					step = MAX_INT;
					break;
				}
			}
			miN = min(miN, step);
		}
		(miN == MAX_INT) ? printf("-1\n") : printf("%d\n", miN);

	}
	return 0;
}

