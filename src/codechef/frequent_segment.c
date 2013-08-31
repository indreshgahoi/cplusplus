#include<stdio.h>
#include<assert.h>
#define MAXN 100006

typedef int INT;
int n;


struct data {
           INT left_count,
	        right_count,
	        total_count;
      }t[262144];


 struct data combine (int a[], struct data l,INT ll,INT lr, struct data r,INT rl, INT rr) {
	 struct data res;
	 INT count=0;
	 if(a[lr]==a[rl])
	    count=l.right_count+r.left_count;

     if(l.total_count>=r.total_count)
     {

         res.total_count=l.total_count;
     }
     else
     {

         res.total_count=r.total_count;
     }
     if(count>res.total_count)
     {
         res.total_count=count;
     }
     if(a[ll]==a[rl])
     {
         res.left_count=l.left_count+r.left_count;
     }
     else
         res.left_count=l.left_count;
      if(a[rr]==a[lr])
      {
          res.right_count=r.right_count+l.right_count;
      }
      else
           res.right_count=r.right_count;

	 return res;
 }


 struct data make_data () {
	 struct data res;
     res.left_count = res.right_count = res.total_count=1;
	 return res;
 }


void build (int a[], INT v, INT tl, INT tr) {
	 if (tl == tr)
		 t[v] = make_data();
	 else {
		 int tm = (tl + tr)>> 1;
		 build(a, v <<1, tl, tm);
		 build(a, (v<< 1) + 1, tm + 1, tr);
		 t[v]=combine(a,t[v << 1],tl,tm,t[(v << 1) + 1],tm+1,tr);
	 }
 }

struct data query ( int a[],INT v,INT tl,INT tr,INT l,INT r) {
	 if (l == tl && tr == r)
		 return t [v];
	 int tm = (tl + tr) >> 1;
	 if (r <= tm)
		 return query (a,v << 1, tl, tm, l, r);
	 if (l> tm)
		 return query (a,(v << 1) + 1,tm + 1, tr, l, r);
	 return combine (a,
		 query (a,(v << 1), tl, tm, l, tm),tl,tm,
		 query (a,(v <<1) + 1, tm + 1, tr, tm + 1, r),tm+1,tr
                  );
 }

 int main()
 {
     INT a[MAXN],m,x1,x2,i;
     //memset(a,0,MAXN*sizeof(int));
      int tmp;
     struct data res;
       while(1){
         scanf("%d",&n);
         if(n==0)
             {
                 break;
             }
         scanf("%d",&m);
         for(i=0;i<n;i++)
            scanf("%d",&a[i]);
         build(a,1,0,n-1);
        // printf("%d",1000000000);
         for(i=1;i<=m;i++)
         {
             scanf("%d%d",&x1,&x2);
             /*if(x1>x2)
             {
                 tmp=x1;
                 x1=x2;
                 x2=tmp;
             }
             assert(x1<=x2);
             assert(x1<=n && x2<=n);*/
             res=query(a,1,0,n-1,x1-1,x2-1);
             printf("%d\n",res.total_count);
         }

       }

return 0 ;
 }

