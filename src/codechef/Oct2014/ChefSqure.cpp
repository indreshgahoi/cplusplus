/*
 * ChefSqure.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include <bitset>
#include<algorithm>
#include<math.h>

using namespace std;

int x[2001];
int y[2001];

void solve() {
	set<pair<int, int> > pointsSet;

	int n;
	scanf("%d", &n);
	if (n < 3) {
		printf("%d\n", 4 - n);
		return;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		pointsSet.insert(make_pair(x[i], y[i]));
	}
	double xc, yc, xd, yd, x3, y3, x4, y4;
	int match = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {

			xc = (x[i] + x[j]) / 2.0, yc = (y[i] + y[j]) / 2.0;
			xd = (x[i] - x[j]) / 2.0, yd = (y[i] - y[j]) / 2.0;
			x3 = xc - yd, y3 = yc + xd;
			x4 = xc + yd, y4 = yc - xd;
			int c = 0;
			if (floor(x3) == x3 && floor(y3) == y3) {
				if (pointsSet.find(make_pair(int(x3), int(y3)))
						!= pointsSet.end()) {
					c++;
				}
			}
			if (floor(x4) == x4 && floor(y4) == y4) {
				if (pointsSet.find(make_pair(int(x4), int(y4))) != pointsSet.end()) {
					c++;
				}
			}

			match = max(c, match);
			if (match == 2)
				break;
		}
		if (match == 2)
			break;
	}
	printf("%d\n", 2 - match);

}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt","wt",stdout);
	solve();
	return 0;
}
