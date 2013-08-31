/*
 * Granmaa.cpp

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


char s1[1005],s2[1005];
int i,j;
int buff1[26],buff2[26];
/*int main(int argc, char **argv) {

	int T;
    gi(T)
    while(T--)
    {
        gs(s1) gs(s2)
         REP(i,26)
           buff1[i]=0,buff2[i]=0;
          i=0;
         while(*(s1+i)!='\0')
                 buff1[*(s1+i++)-'a']++;
         i=0;
         while(*(s2+i)!='\0')
                 buff2[*(s2+i++)-'a']++;

          int k=0,j=0;
           FOR(i,0,25)
          {

              if((buff1[i]==0 && buff2[i]!=0) || (buff2[i]==0&& buff1[i]!=0)){
               k=1;
               break;
              }
              else if(buff1[i]==buff2[i])
            	      j++;
              else k=0;
          }

  if(k==1 ||(j==i))
	  printf("YES\n");
  else
	  printf("NO\n");
    }
    return 0;
}*/






