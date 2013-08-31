/*
 * PizzaDelivery.cpp
 *
 *  Created on: Dec 3, 2012
 *      Author: indresh
 */

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<set>
#include<cmath>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n)   for(i=0;i<n;i++)
#define EVER          while(1)
#define  dbgi(x)  printf(#x" = %d\n",x);
#define  dbgll(x) printf(#x" = %ll\n",x);
#define gi(i)         scanf("%d",&i);
#define gll(i)        scanf("%lld",&i);
#define gd(i)         scanf("%f",&i);
#define gui(i)        scanf("%u",&i);
#define gull(i)       scanf("%ull",&i);
#define gs(s)         scanf("%s",s);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define sl(s)  strlen(s)
#define nl   puts("");
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define f first
#define s second
#define x   f
#define y   s.f
#define z   s.s
#define N 1000000
#define pb push_back
#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))

using namespace std;

typedef long long int LL;
typedef int I;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> VI;
typedef pair< int,pair< int,int > > tri;

int Min[300000];
int memo[300000];
int o[500],p[500];
/int n;
void setmemo(int m){

	int target=m<<1;
	for(int i=0;i<=target;i++)
		 memo[i]=0;

	for(long int i=0;i<=target;i++)
				 Min[i]=9999999;
	Min[0]=0;

	for(int k=1;k<=target;k++){
				 for(int j=0;j<n;j++)
				 		 {
				 			 if(p[j]<=k && Min[k-p[j]]+1<Min[k])
				 				 Min[k]=Min[k-p[j]]+1;
				 		 }
				 memo[target]=Min[target];
			 }

	}


/*int main()
{
	I T;
	gi(T)
	while (T--)
	{

	 gi(n)
	 int i=0;
	  FOR(i,0,n-1)
	   gi(o[i])
	 FOR(i,0,n-1)
	  gi(p[i])
     int max=-1;
	  FOR(i,0,n-1)
	  	 if(o[i]>max)
	  		 max=o[i];
	 long int steps=0;
	 long int target;
	 setmemo(max);
	 for(int i=0;i<n;i++)
	 {
		 target=o[i]<<1;
         steps+=Min[target];
	 }
	 printf("%ld\n",steps);
	}
	return 0;
}*/


