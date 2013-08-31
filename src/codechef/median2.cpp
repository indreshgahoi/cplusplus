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

int A[31],B[31];
int m,ct=0;

int main()
{
   #ifndef ON_LINE_JUDGE
   //  freopen("input.txt","rt",stdin);
   //  freopen("output.txt","wt",stdout);
   #endif
  I T,i,n;
  gi(T)
  while(T--)
  {
      gi(n)

      FOR(i,1,n)
        scanf("%d",A+i);

      FOR(i,0,n)
         B[i]=0;

      m=1<<31;
      FOR(i,1,n)
         if(m<A[i])
            m=A[i];

      FOR(i,1,n)
        if(A[i]==m)
             B[i]=B[i-1]+1;
        else
             B[i]=B[i-1];

            int steps=0;
            int size=0,size1=0,l1=0,r1=0,l2=0,r2=0;
           // FOR(i,1,n)
             //     printf("%d ",A[i]);
           // printf("\n");

            while(B[n]!=n){

            size1=size=0;l1=0;r1=0,l2=0,r2=0;

            for(int l=1;l<=n;l++)
            {
                for(int r=l;r<=n;r++)
                {
                 if(((B[r]-B[l-1])>=((r-l+2)>>1)) && (size<=(r-l+1)))
                 {
                     l1=l;r1=r;
                     size1=(r-l+1);
                 }

                     if(((B[r]-B[l-1])>=((r-l+2)>>1)) && (size<(r-l+1)))
                 {
                     l2=l;r2=r;
                     //size1=(r-l+1);
                 }
                 size=size1;


                }
            }
            // size1=size;
             int A1[31];

             FOR(i,1,n)
                  A1[i]=A[i];

             FOR(i,l1,r1)
                A1[i]=m;

             FOR(i,1,n)
             if(A1[i]==m)
               B[i]=B[i-1]+1;
             else
               B[i]=B[i-1];

                int size3=0;

            for(int l=1;l<=n;l++)
            {
                for(int r=l;r<=n;r++)
                {
                 if(((B[r]-B[l-1])>=((r-l+2)>>1)) && (size3 <(r-l+1)))
                 {
                    // l1=l;r1=r;
                     size3=(r-l+1);
                 }

                }
            }

            FOR(i,1,n)
                  A1[i]=A[i];

            FOR(i,l2,r2)
               A1[i]=m;

            FOR(i,1,n)
             if(A1[i]==m)
               B[i]=B[i-1]+1;
             else
               B[i]=B[i-1];

                int size4=0;

            for(int l=1;l<=n;l++)
            {
                for(int r=l;r<=n;r++)
                {
                 if(((B[r]-B[l-1])>=((r-l+2)>>1)) && (size4 <(r-l+1)))
                 {
                    // l1=l;r1=r;
                     size4=(r-l+1);
                 }

                }
            }

            if(size4>=size3)
            l1=l2,r1=r2;




            FOR(i,l1,r1)
                  A[i]=m;

            FOR(i,1,n)
             if(A[i]==m)
               B[i]=B[i-1]+1;
             else
               B[i]=B[i-1];

          //  FOR(i,1,n)
          //       printf("%d ",A[i]);
          //  printf("\n");


               steps++;
      }
            printf("%d\n",steps);



       }
       return 0;
}
