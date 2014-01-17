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
#define sl(s)  strlen(s)
typedef char* string;
typedef int I;

char str[1000005];
I pos[26]={0};
int main()
{
 I T,res[1000005],len,i;
 gi(T);
 I m=1000000007;
 while(T--)
 {
     res[0]=1;
     gs(str+1);
     len=sl(str+1);
     memset(pos,0,sizeof(pos));
      //pi(len)
      //printf("\n");
     FOR(i,1,len)
     {
    	 res[i]=(2*res[i-1])%m;

         if(pos[str[i]-'A'])
           res[i]=(res[i]-res[pos[str[i]-'A']-1]+m)%m;
         pos[str[i]-'A']=i;
         //printf("%d : s[%d]= %d res[ %d ] = %d\n",i,i,str[i]-'A',i,res[i]);
     }
     pi(res[len]%m);
 }
 return 0;
}



















