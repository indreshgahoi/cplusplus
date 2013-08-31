#include<stdio.h>
/*long long int joseph (int n, int k)
 {
 long long i = 1,j,r;
        long long int a = 0, s;
        while (i <= n) {
            j = k / i;
            r = k % i;
            if (j == 0) {
                a += r * (n - i + 1);
                i = n + 1;
            } else {
               s = r / j;
                if (s + 1 > n - i + 1) {
                    s = n - i;
                }
                a += (r + r - s * j) * (s + 1) / 2;
                i += s + 1;
            }
        }
   return a;
   }*/
   long long int joseph ( int n, int k ) {
	long long int res = 0 ,i;
	for ( i = 1 ; i <= n ; ++ i )
		res = ( res + k ) % i ;
	return res + 1 ;
}

int main()
{
    int n,m;

  while(1)
    {

        scanf("%d%d",&n,&m);
        if(n==0 && m==0)
          break;

        printf("%d %d %lld\n",n,m,joseph(n,m));
    }
  return 0;
}
