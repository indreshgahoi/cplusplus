/*
 * TeapSplit.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>
#include<cassert>
#include<stdlib.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	int A[1000001];
	int n;
	int a, c, b, d;
	while (T--) {
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

		for (int i = 0; i < 1000000; ++i)
			A[i] = 0;
		A[d] = 1;
		int maxIndex = 0 ;
		int pre = d;
		for (int i = 1; i < n; ++i) {
			int next = ((((long long) pre) * pre * a)
					+ (b * ((long long) pre)) + c) % 1000000;
			//assert(next<1000000 && next > 0);
			A[next]++;

			pre = next;
		}
		long long evenTerm, oddTerm;
		evenTerm = oddTerm = 0;
		bool turn = false;

		for (int i = 0; i < 1000000; ++i) {

			if (A[i] & 1) {
				if (turn) {
					evenTerm += i;
				} else {
					oddTerm += i;
				}
				turn = !turn;
			}
			long long val = ((long long) i) * (A[i] >> 1);
			evenTerm += val;
			oddTerm += val;

		}
		printf("%lld\n", abs(evenTerm - oddTerm));

	}
	//delete[] A;
	return 0;
}

