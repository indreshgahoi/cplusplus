#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector <int> p(1000001,1);
void preprocess()
{
   p[0]=p[1]=0;
   int k=1000000/2;
   for(int i=2;i<=k;i++)
     if(p[i]==1){
         for(int j=1;j*i<=1000000;j++){
           p[j*i]++;
           }
     }
}
struct data {
           int ct[11];
      }t[4*1000001];


struct data combine (struct data l,struct data r) {
	 struct data res;
	  res.ct[0]=0;
	 for(int i=1;i<=10;i++)
       res.ct[i]=l.ct[i]+r.ct[i];
	 	 return res;
 }



struct data make_data (int n) {
	 struct data res;
	 res.ct[0]=res.ct[1]=res.ct[2]=res.ct[3]=res.ct[4]=res.ct[5]=res.ct[6]=res.ct[7]=res.ct[8]=res.ct[9]=res.ct[10]=0;
     if(p[n]==1 ||p[n]==2)
       res.ct[1]=1;
     else
     if(p[n]<=11)
        res.ct[p[n]-1]=1;

	 return res;
 }
void build (int v, int tl, int tr) {
	 if (tl == tr)
		 t[v] = make_data(tl);
	 else {
		 int tm = (tl + tr)>> 1;
		 build( v <<1, tl, tm);
		 build((v<< 1) + 1, tm + 1, tr);
		 t[v]=combine(t[v << 1],t[(v << 1) + 1]);
	 }
 }

 struct data query (int v,int tl,int tr,int l,int r) {
	 if (l == tl && tr == r)
		 return t[v];
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
int main()
{
    int f,b,k,t,result;
    struct data res;
     //puts("hello");
    preprocess();
    build(1,1,1000000);

   // puts("hello");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&f,&b,&k);
        res=query(1,1,1000000,f,b);
    printf("%d\n",res.ct[k]);
    }
    return 0;
}
