/*
 * ChefLeftAndRight.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include <climits>

using namespace std;
long long int mod = 1000000007;

long long int pow(long long int x, long long int n) {
	if (n == 0)
		return 1;
	long long int t = pow(x, n / 2);
	if (n & 1) {
		return (((t * t) % mod) * x) % mod;
	}
	return (t * t) % mod;
}

int main() {
	//freopen("input.txt","rw",stdin);
	int T;
	scanf("%d", &T);
	char str[100005];
	long long int id;
	while (T--) {
		scanf("%s", str);
		id = 1;
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (str[i] == 'l') {
				id = (((2 * (id - 1)) % mod) + 1) % mod;
			} else {
				id = (((2 * (id - 1)) % mod) + 2) % mod;
			}
			//printf("id : %lld \n",id);
		}
		long long int f = 0.0;
		if (len & 1) {
			long long int r = (pow(4, len / 2) - 1) % mod;
			//printf("r : %lld \n", r);
			r = (r * pow(3, mod - 2)) % mod;
			//printf("r : %lld \n", r);
			r = (r * 2) % mod;
			r = (r + id) % mod ;
			r = (r * 2) % mod;

			printf("%lld\n", r);
		} else {
			long long int r = (pow(4, len / 2) - 1) % mod;
			//printf("r : %lld \n", r);
			r = (r * pow(3, mod - 2)) % mod;
			//printf("r : %lld \n", r);
			r = (r + id) % mod ;
			r = (((2 * r) % mod) - 1) % mod;
			printf("%lld\n", r);
		}

	}
	return 0;
}

