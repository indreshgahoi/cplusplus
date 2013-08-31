#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n)   for(i=0;i<n;i++)
#define EVER          while(1)
#define true 1
#define false 0
#define  dbgi(x)  printf(#x" = %d\n",x);
#define  dbgll(x) printf(#x" = %ll\n",x);
#define gi(i)         scanf("%d",&i);
#define gll(i)        scanf("%lld",&i);
#define gd(i)         scanf("%f",&i);
#define gui(i)        scanf("%u",&i);
#define gull(i)       scanf("%ull",&i);
#define gs(s)         scanf("%s",s);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define nl printf("\n");
#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define min(a,b)    ((a)>(b)? (b):(a));
#define N 505
#define N1 10010
#define MAX 999999999
typedef int I;
typedef long long int LL;
int p[N],w[N],sol[N1];
int main()
{
    I T,e,f,n,i,j,q;
  gi(T)
   while(T--)
  {
      gdi(e,f)
      gi(n)
      FOR(i,1,n)
       gdi(p[i],w[i])
       f=f-e;
      sol[0]=0;
      FOR(i,1,f)
      {  q=MAX;
          FOR(j,1,n)
            if(i>=w[j])
             q=min(q,p[j]+sol[i-w[j]])
          sol[i]=q;
      }

      if(sol[f]!=MAX)
      printf("The minimum amount of money in the piggy-bank is %d.\n",sol[f]);
      else
      printf("This is impossible.\n");
  }
   return 0;
}


