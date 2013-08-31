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

char s1[6101],s2[6101];
int X[6101],Y[6101],*p,*q,*r,len;

void reverse()
{
    //int len=s.length();
int    i=1,t=len;

    while(t>=1)
    {
        s2[i]=s1[t];
          i++;t--;
    }
    s2[i]='\0';
}

int main()
{
    I T,i,j;
    gi(T)
    while(T--)
    {
      scanf("%s",s1+1);
        len=strlen(s1+1);
        reverse();
        FOR(i,0,len)
          X[i]=Y[i]=0;
          p=X;
          q=Y;
        FOR(i,1,len){
         FOR(j,1,len)
         {
           if(s1[i]==s2[j])
                p[j]=q[j-1]+1;
           else
            p[j]=max(p[j-1],q[j]);
         }
         r=p;
         p=q;
         q=r;
        }


         printf("%d\n",(len-max(p[len],q[len])));
    }

 return 0;
}



