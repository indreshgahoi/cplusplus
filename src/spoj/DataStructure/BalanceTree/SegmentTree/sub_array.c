#include<stdio.h>
#define MAXN 1000000

int a[MAXN];
int t[4*MAXN];
 int max(int a,int b)
{
    return a>=b? a:b;
}


void build (int v,int tl,int tr) {
	 if (tl == tr)
		 t[v] = a[tl];
	 else {
		 int tm = (tl + tr)>>1;
		 build(v<<1, tl, tm);
		 build((v<<1) + 1, tm + 1, tr);
		 t[v]=max(t[v<<1],t[(v<<1) +1]);
	 }
 }

int query (int v,int tl,int tr,int l,int r) {
	 if (l == tl && tr == r)
		 return t [v];
	 int tm = (tl + tr)>>1;
	 if (r <= tm)
		 return query (v<<1, tl, tm, l, r);
	 if (l> tm)
		 return query ((v<<1)+1,tm+1,tr,l,r);
	 return max(
		 query (v << 1, tl, tm, l, tm),
		 query ((v<<1) + 1, tm + 1, tr, tm + 1, r)
	 );
 }
 void solve(int N,int K)
 {
     int i,var;

     build(1,1,N);
     var=N-K+1;
     for(i=1;i<=var;i++)
     {
         printf("%d ",query(1,1,N,i,i+K-1));
     }
     printf("\n");

 }
 int main()
 {
    int N,K;
    int i;

    //scanf("&d",&T);

    //while(T--)
    //{
        scanf("%d",&N);

        for(i=1;i<=N;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&K);
        solve(N,K);
    //}

  return 0 ;
 }
