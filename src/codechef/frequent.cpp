#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 200001
#define INF  9999999

 pair <int,int> t [4 * MAXN];

 pair <int, int> combine (pair <int, int> a, pair <int, int> b) {
	 if (a. second> b. second)
		 return a.first;
	 if (b. second> a.second)
		 return b.first;
	 return make_pair (a. first, a. second + b. second);
 }

 void build (int a [], int v, int tl, int tr) {
	 if (tl == tr)
		 t [v] = make_pair (a [tl], 1);
	 else {
		 int tm = (tl + tr) / 2;
		 build (a, v * 2, tl, tm);
		 build (a, v * 2 + 1, tm + 1, tr);
		 t [v] = combine (t [v * 2], t [v * 2 + 1],v*2,v*2+1);
	 }
 }

 pair <int, int> get_max (int v, int tl, int tr, int l, int r) {
	 if (l> r)
		 return make_pair (- INF, 0);
	 if (l == tl && r == tr)
		 return t [v];
	 int tm = (tl + tr) / 2;
	 return combine (
		 get_max (v * 2, tl, tm, l, min (r, tm)),
		 get_max (v * 2 + 1, tm + 1, tr, max (l, tm + 1), r)
	 );
 }
int main()
{
    int a[MAXN] ,n,q,i,l,r;
    pair<int,int> res;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
         break;
        scanf("%d",&q);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        build(a,1,0,n-1);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&l,&r);
            res=get_max(1,0,n-1,l-1,r-1);
            printf("%d\n",res.second);
        }
    }
    return 0;
}
