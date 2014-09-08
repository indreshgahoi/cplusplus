/*
 * LittleXor.cpp
 *
 *  Created on: Dec 6, 2012
 *      Author: indresh
 */
#include<iostream>
#include <cstdio>
using namespace std;

long long int maxSubArraySum(long long int a[], int N) {
	long long int max_sum = 0;
	for (int i = 0; i < N; i++) {

		for (int j = i; j < N; j++) {
			long long int temp = 0;
			for (int k = i; k < j + 1; k++) {
				temp ^= a[k];
			}
			if (temp > max_sum) {
				max_sum = temp;

			}

		}

	}
	return max_sum;
}

int main() {
	int T;
	cin >> T;
	long long int a[T];
	for (int i = 0; i < T; i++)
		cin >> a[i];
	cout << maxSubArraySum(a, T);

	return 0;
}

