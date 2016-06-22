/*
 * FunWithRotation.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int arr[100005];
int main() {

	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", arr + i);
	}
	int off = 0;
	int x;
	char str[2];
	for (int i = 0; i < M; ++i) {
		scanf("%s", str);
		scanf("%d", &x);
		if (str[0] == 'C') {
			off = (off + x) % N;
		} else if (str[0] == 'A') {
			off = (off - x + N) % N;
		} else {
			printf("%d\n", arr[(off + x - 1) % N]);
		}
		//printf("off : %d \n",off);
	}
	return 0;
}

