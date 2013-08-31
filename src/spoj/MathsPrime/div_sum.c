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
#define pll(i) printf("%lld\n",i);
#define pd(i)  printf("%f\n",i);
#define sl(s)  strlen(s)
#define pnl   printf("\n");
typedef int I;
typedef char * string;
typedef long long int LL;

int main()
{
    LL T,sum,root,num,i;
    gll(T);
    while (T--)
    {
       sum=1;
       gll(num);
       root=(LL)sqrt(num +.0);
       FOR(i,2,root){
        if(num%i==0)
         sum+=i+(num/i);

        //pll(num);
       // pll(i);
       // pll(num/i);}
       }
       if(root*root==num)
         sum-=root;
       //pnl
       pll(sum);
       //pnl
    }
  return 0;
}
