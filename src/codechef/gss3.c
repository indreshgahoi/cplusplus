#include<stdio.h>
#define MAXN 1000000

long int max(long int  a,long int b)
{
    return a>=b? a:b;
}
struct data {
	 long int sum, pref, suff, ans;
 }t[4*MAXN];
 struct data combine (struct data l, struct data r) {
	 struct data res;
	 res.sum = l.sum + r.sum;

	 res.pref = max (l.pref, l.sum + r.pref);
	 res.suff = max (r.suff, r.sum + l.suff);
	 res.ans = max(max(l. ans, r. ans),l.suff+r.pref);
	 return res;
 }

 struct data make_data (long int val) {
	 struct data res;
	 res.sum = val;
	 res.pref = res.suff = res.ans = val;
	 return res;
 }

void build (long int a[], long int v, long int tl, long int tr) {
	 if (tl == tr)
		 t[v] = make_data(a[tl]);
	 else {
		 int tm = (tl + tr)>> 1;
		 build(a, v <<1, tl, tm);
		 build(a, (v<< 1) + 1, tm + 1, tr);
		 t[v]=combine(t[v << 1],t[(v << 1) + 1]);
	 }
 }

struct data query (long int v,long  int tl,long int tr,long int l,long int r) {
	 if (l == tl && tr == r)
		 return t [v];
	 int tm = (tl + tr) >> 1;
	 if (r <= tm)
		 return query (v << 1, tl, tm, l, r);
	 if (l> tm)
		 return query ((v << 1) + 1,tm + 1, tr, l, r);
	 return combine (
		 query ((v << 1), tl, tm, l, tm),
		 query ((v <<1) + 1, tm + 1, tr, tm + 1, r)
	 );
 }


 void update (long int v,long  int tl,long  int tr,long  int pos,long int new_val) {
	 if (tl == tr)
		 t [v] = make_data (new_val);
	 else {
		 int tm = (tl + tr) >> 1;
		 if (pos <= tm)
			 update (v << 1, tl, tm, pos, new_val);
		 else
			 update ((v <<1) + 1, tm + 1, tr, pos, new_val);
		 t [v] = combine (t [v << 1], t [(v << 1) + 1]);
	 }
 }
 int main()
 {
     long int a[MAXN],n,m,x1,x2,i;
     int ch;
     struct data res;

         scanf("%ld",&n);
         for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
         build(a,1,0,n-1);
         scanf("%ld",&m);
        // printf("%d",1000000000);
         for(i=1;i<=m;i++)
         {
             scanf("%d%ld%ld",&ch,&x1,&x2);
             if(ch==0)
             {
                 update(1,0,n-1,x1-1,x2);
             }
             else if(ch==1){res=query(1,0,n-1,x1-1,x2-1);
             printf("%ld\n",res.ans);}
         }



  return 0 ;
 }
