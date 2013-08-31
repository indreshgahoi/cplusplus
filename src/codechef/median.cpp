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

int A[31],B[31],max,start,end,count=0;
int main()
{
  I T,i,n;
  gi(T)
  while(T--)
  {   gi(n)
      FOR(i,1,n)
        scanf("%d",A+i);
        FOR(i,0,n)
         B[i]=0;
        max=-1;
        FOR(i,1,n)
         if(max<A[i])
            max=A[i];
     //   count=0;start=0;end=0;
      //  int max_c=0,length=0,l=0,r=0,j=0,k=1,interval,op=0,cur_l=0,cur_r=0,cur_int=0;
        FOR(i,1,n)
         if(max==A[i])
           count++;
        if(count==n)
         printf("0\n");
        else if(!(n & 1) && count >=((n>>1))
              printf("1\n");
        else if((n & 1) && count >((n>>1))
                   printf("1\n");
        else
        {
            FOR(i,1,n)
             if(A[i]==max)
               B[i]=B[i-1]+1;
             else
               B[i]=B[i-1];
            int steps=0;
            int size=0,l1=0,r1=0;
            while(B[n]==n){
            for(int l=1;l<=n;l++)
            {
                for(int r=l;r<=n;r++)
                {
                 if((B[l-1]-B[r])>=((r-l+2)>>1) && size > (r-l+1))
                 {
                     l1=l;r1=r;
                     size=(r-l+1);
                 }
                }
            }

            FOR(i,l1,r1)
                  A[i]=max;

            FOR(i,1,n)
             if(A[i]==max)
               B[i]=B[i-1]+1;
             else
               B[i]=B[i-1];

               steps++;

            }

            /* while(j==0){
             FOR(i,1,n)
              if(A[i]==max)
              {
                if(k)
                {
                  k=0;l=i;
                }
                max_c++;r=i;
                if((max_c<<1)>=length)
                length++;
                else
                {
                  max_c=1;length=1;l=i;
                }
              }
              else
              {
                length++;
              }
              interval=r-i+1;
              for(i=l;i<=r;i++)
              {
                  A[i]=max;
                  op++;
                  }
              for(i=0,count=0;i<n;i++)
              if(A[i]==max)count++;
              if(count==n)j=1;
            }*/

           //printf("%d\n",op);
        }
       }
       return 0;
}
