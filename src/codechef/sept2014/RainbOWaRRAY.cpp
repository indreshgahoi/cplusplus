/*
 * RainbOWaRRAY.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>

using namespace std;

long long int mod = 1000000007;
long long int fac7[7];
long long int inv7[7];
long long int facK[7];
long long int pow(long long int x, long long int n) {
	if (n == 0)
		return 1l;
	long long int t = pow(x, n / 2);
	t = (t * t) % mod;
	if (n & 1)
		return (t * x) % mod;
	return t;
}

void preprocess() {
	long long int mul = 6;
	fac7[0] = 7;
	for (int i = 1; i < 7; ++i) {
		fac7[i] = fac7[i - 1] * mul;
		--mul;
	}
	inv7[0] = pow(1, mod - 2);
	inv7[1] = pow(1, mod - 2);
	inv7[2] = pow(2, mod - 2);
	inv7[3] = pow(6, mod - 2);
	inv7[4] = pow(24, mod - 2);
	inv7[5] = pow(120, mod - 2);
	inv7[6] = pow(720, mod - 2);
}

int main() {

	int N;
	scanf("%d", &N);
	preprocess();
	if (N < 13) {
		printf("0");
	} else {
		int K = N - 13;
		if (K & 1) {
			K = (K - 1) / 2;
		} else {
			K /= 2;
		}
		K = K-1 ;
		if(K >= 0){
			long long int mul = (long long int)K ;
			facK[0] = 1 ;

			for(int i = 1 ; i < 7 ; ++i){
                  facK[i] = (facK[i-1]  * mul) % mod ;
                  mul--;
			}
			long long int ans = 0;
			for (int i = 0; i < 7; ++i) {
				ans = (ans + (((facK[i] * inv7[i]) % mod) * fac7[i])%mod) % mod ;
			}
			printf("%lld",ans);
		}else {
			printf("1");
		}

	}
	return 0;
}

