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
#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));

#define N 1000005
typedef int I;
typedef long long int LL;

int main()
{
    LL T,a,b,n,m,s,t,i;
    gll(T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        a=a%m;
        b=b%m;
        s=(a+b)%m;
       /* if(n==0)
         printf("%lld\n",0);
        if(n==1)
          printf("%lld\n",a);
        if(n==2)
          printf("%lld\n",s);
        if(n>2){*/
        FOR(i,3,n)
        {
          t=a;
          a=b;
         // b=(t+a)%m;
         // s=(s+b)%m;
          b=(t+a)%m;
          s=(s+b)%m;
        }
          printf("%lld\n",s);//}

    }
    return 0;
}

