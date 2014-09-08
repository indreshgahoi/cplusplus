#include <stdio.h>
#include <math.h>
#include <string.h>

char a[100001];
char isprim[100001];
int primes[10001];
int primcount = 0;
//int p[1000];
int i = 0, j = 0, x = 0, t = 0;

void all_prime(int l, int r) {

	primcount = 0;
	x =  sqrt(r) + 1;
	memset(a, 1, (x < sizeof(a)) ? x : sizeof(a));

	memset(isprim, 1, sizeof(isprim));

	a[0] = a[1] = 0;

	for (i = 2; i <= x; i++) {
		if (a[i]) {

			primes[primcount++] = i*i;
			for (j = 2*(i * i); j <= x; j += i) {

				a[j] = 0;
			}

		}
	}

	for (i = l; i <= r; i++)
		for (j = 0; j < primcount; j++)
			if (i > (primes[j]*primes[j]) && i % (primes[j]) == 0) {
				isprim[i - l] = 0;
				break;
			}
	int ret = 0 ;
	for (t = 0; t <= r - l; t++)
		if ((t + l >= 2) && (isprim[t]))
			ret++ ;
	printf("%d",ret);

}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		all_prime(n, m);
	}
	return (0);
}
