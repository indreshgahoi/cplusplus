#include<iostream>
#include<vector>
#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cmath>
#include<string>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
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
#define ps(s) puts(s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define mp(i,j)  make_pair(i,j);
#define pb(i)    push_back(i);
#define ROW  100
#define COL  100 
typedef long long int LL;
typedef int I;
 
int N0[ROW+1][COL+1],N1[ROW+1][COL+1];
void preprocess()
{
FOR(i,0,ROW)
 FOR(j,0,COL)
  {
   N0[i][j]=N1[i][j]=0;
  }
 N0[1][0]=1;  N1[1][0]=1;
 N0[2][0]=2;  N1[2][0]=N1[2][1]=1;

 
   FOR(i,3,ROW)
    {
	  N0[i][0]=N0[i-1][0]+N0[i-2][0];
	  N1[i][0]=N0[i-1][0];
	}
  FOR(row,3,ROW)
    FOR(col,1,COL)
     {
	   N0[row][col]=N0[row-1][col]+N1[row-1][col];
	   N1[row][col]=N0[row-1][col]+N1[row-1][col-1];
     }	 
  
}
int main()
{
  preprocess();
  I T,j,n,k;
  gi(T);
  while(T--)
  {
   scanf("%d%d%d",&j,&n,&k);
   printf("%d %d\n",j,(N0[n][k]+N1[n][k]));
  }
  return 0;
}





       