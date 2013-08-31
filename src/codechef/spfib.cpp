#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define N 100
typedef long long LL;
typedef unsigned long long ULL;

LL fib[N], cf[N], comb[N][N];
const int nfib = 83;
void precompute()
{
fib[0] = fib[1] = 1;
for(int i = 2; i <= nfib; i++)
fib[i] = fib[i-1] + fib[i-2];
for(int i = 0; i <= nfib; i++) {
for(int j = 1; j < i; j++)
comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
comb[i][0] = comb[i][i] = 1;
}
for(int i = 0; i < nfib; i++) {
cf[i] = 0;
for(int j = 0; j <= i-j+1; j++)
cf[i] += j*comb[i-j+1][j];
}
}

LL fib_count(LL n)
{
int k = 0;
LL n0 = n;
while(k + 3 <= nfib && (k-1) * fib[k+2] + (2*fib[k+2] - fib[k+3] + 2) <= n)
++k;
n -= (k-2) * fib[k+1] + (2*fib[k+1] - fib[k+2] + 2);
++k;
LL m = fib[k]+n/k, r = n%k; // fib[k]...fib[k]+(n/k)-1, fib[k]+(n/k) (1..r)
//printf("%I64d: m%I64d r%I64d\n", n0, m, r);
LL c = 0, cc = 0;
for(int i = k; i > 0; i--) {
if(m >= fib[i]) {
c += cf[i-1] + fib[i] * cc;
if(i >= k+1-r) ++c;
//printf("%I64d %2d: cf%I64d pre%I64d cc%I64d c%I64d\n", n0, i, cf[i-1], fib[i]-1, cc, c);
cc++;
m -= fib[i];
}
}
return c;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in", "r", stdin);
freopen("out", "w", stdout);
#endif
int t;
LL n;
precompute();
scanf("%d", &t);
while(t--) {
#ifndef ONLINE_JUDGE
scanf("%I64d", &n);
printf("%I64d\n", fib_count(n));
#else
scanf("%lld", &n);
printf("%lld\n", fib_count(n));
#endif
}
