#include <stdio.h>

static unsigned long long F[90], W[90], WC[90], P, Q;

unsigned long long fsum(int n, unsigned long long P) {
// fprintf(stderr, "%d %I64d\n", n, P);
if (!P) return 0;
if (P == 1) return 1;
// assert (P > 0 && P < F[n]);
if (P < F[n-1]) {
return fsum(n-1,P);
} else {
P -= F[n-1];
return W[n-1]+P+fsum(n-2,P);
}
}

int fn (int r, int n, unsigned long long P) {
if (r <= 0) return 0;
return P < F[n+1] ? fn(r-1,n-1,P) : 1+fn(r-2,n-2,P-F[n+1]);
}

int main () {
int n, i, r,t;
F[1] = W[1] = WC[1] = 1;
for (i = 2; i < 90; i++) {
F[i] = F[i-1] + F[i-2];
W[i] = F[i] + WC[i-2];
WC[i] = W[i] + WC[i-1];
}
scanf("%d",&t);
while(t--){
scanf("%llu",&P);
Q=0;
n = 1;
while (n * F[n] <= P) {
P -= n*F[n];
Q += W[n];
n++;
}
r = P % n;
P /= n;
Q += fsum(n,P);
//fprintf(stderr,"%d %d %I64d\n",r,n,P+F[n+1]);
Q += fn(r,n,P+F[n+1]);
printf("%llu\n",Q);
}
return 0;
}
