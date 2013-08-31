#include <assert.h>
#include <stdio.h>

static long long int F[90], W[90], WC[90], P, Q;

long long fsum(int n, long long P) {
//  fprintf(stderr, "%d %I64d\n", n, P);
  if (!P) return 0;
  if (P == 1) return 1;
  assert (P > 0 && P < F[n]);
  if (P < F[n-1]) {
    return fsum(n-1,P);
  } else {
    P -= F[n-1];
    return W[n-1]+P+fsum(n-2,P);
  }
}

int fn (int r, int n, long long P) {
  if (r <= 0) return 0;

 /* if(P< F[n+1])
  {
     // printf("r-1=%d n-1=%d  P=%d\n",r,n,P);
      return fn(r-1,n-1,P);
  }
  else
  {
      //printf("r-2=%d n-2=%d  P-F[n+1]=%d\n",r,n,P-F[n+1]);
      return 1+fn(r-2,n-2,P-F[n+1]);
  }*/
  return P < F[n+1] ?  fn(r-1,n-1,P): 1+fn(r-2,n-2,P-F[n+1]);
}

int main () {
  int n, i, r;
  //freopen ("fibonacci.in", "rt", stdin);
 // freopen ("fibonacci.out", "wt", stdout);
  F[1] = W[1] = WC[1] = 1;
  for (i = 2; i < 90; i++) {
    F[i] = F[i-1] + F[i-2];
    W[i] = F[i] + WC[i-2];
    WC[i] = W[i] + WC[i-1];
  }


  //assert(scanf("%I64d",&P) == 1);
  scanf("%lld",&P);
  n = 1;
  Q=0;
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
  printf("%lld\n",Q);

  return 0;
};
