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

int cube_free[N];
int cube[101]={0,0,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,
4096,4913,5832,6859,8000,9261,10648,12167,13824,15625,17576,19683,21952,24389,
27000,29791,32768,35937,39304,42875,46656,50653,54872,59319,64000,68921,74088,
79507,85184,91125,97336,103823,110592,117649,125000,132651,140608,148877,157464,
166375,175616,185193,195112,205379,216000,226981,238328,250047,262144,274625,
287496,300763,314432,328509,343000,357911,373248,389017,405224,421875,438976,
456533,474552,493039,512000,531441,551368,571787,592704,614125,636056,658503,
681472,704969,729000,753571,778688,804357,830584,857375,884736,912673,
941192,970299,1000000};

void preprocess()
{   int ct=0,i,c,j;

   FOR(i,1,N)
       cube_free[i]=1;

    for(i=2;i<=100;i++)
    {   c=cube[i];
        for(j=c;j<=1000000;j+=c)
          cube_free[j]=0;
    }

    for(i=1;i<=1000000;i++)
    {
        if(cube_free[i]==0){ct++;continue;}
        cube_free[i]=i-ct;
    }//pi(ct);
}

int main()
{
    I T,n,i;
    preprocess();
   gi(T);
    FOR(i,1,T)
    {
        scanf("%d",&n);
       (cube_free[n])?  printf("Case %d: %d\n",i,cube_free[n])
                      : printf("Case %d: Not Cube Free\n",i);

    }
return 0;
}
