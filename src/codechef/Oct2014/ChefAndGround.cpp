/*
 * ChefAndGround.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: indresh
 */

#include<cstdio>
#include<iostream>

using namespace std;

int arr[105];
int main() {
	int N, M, T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d%d", &N, &M);
		int max = -100000000;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		int res = 0;

		for (int i = 0; i < N; ++i) {
			res += (max - arr[i]);
		}
		if ( ((res-M) % N == 0)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

