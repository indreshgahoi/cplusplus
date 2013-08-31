/*
 * ranges.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: indresh
 */




/*
* MaximumRangeProducts1.cpp
*
* Created on: Dec 8, 2012
* Author: indresh
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<utility>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
long long int m=1000000007;
struct data{
int minIdx;long long int minValue;
int maxIdx;long long int maxValue;
}*t;

data make_data(long long int value, int idx)
{ data d1;
d1.minValue=d1.maxValue=value;
d1.maxIdx=d1.minIdx=idx;
return d1;
}
data combine(data d1 ,data d2){
data res;
if(d1.maxValue>d2.maxValue)
{
res.maxValue=d1.maxValue;
res.maxIdx=d1.maxIdx;
}
else
{
res.maxValue=d2.maxValue;
res.maxIdx=d2.maxIdx;
}
if(d1.minValue<d2.minValue)
{
res.minValue=d1.minValue;
res.minIdx=d1.minIdx;
}
else
{
res.minValue=d2.minValue;
res.minIdx=d2.minIdx;
}
return res;
}
void build(long long int *a,int v,int tl,int tr){
if(tl==tr)
{
t[v]=make_data(a[tl],tl);
}
else{
int tm=(tl+tr)>>1;
build(a,v<<1,tl,tm);
build(a,(v<<1)+1,tm+1,tr);
t[v]=combine(t[v<<1],t[(v<<1)+1]);
}
}

data query(int v,int tl,int tr,int l ,int r){

if(tl==l && tr==r)
return t[v];


int tm=(tl+tr)>>1;
if(r<=tm)
return query(v<<1,tl,tm,l,r);
if(l>tm)
return query((v<<1)+1,tm+1,tr,l,r);
return combine(query(v<<1,tl,tm,l,tm
),query((v<<1)+1,tm+1,tr,tm+1,r));

}

inline long long getpow(long long int p,long long int x){
long long int res=1l;
//long long int l=x;
//cout<<"p="<<p<<" "<<" x="<<x<<endl;

while(x!=0)
{
if(x&1)
res=((res)*(p))%m;

x=x>>1;
p=((p)*(p))%m;

}
//cout<<"px="<<p<<"^"<<l<<" "<<res<<" x="<<x<<endl;
return res;
}

long long int inv(long long int x,long long int M) {
long long a = 1, b = x;
while (b != 1) {
long long int c = M / b;
a *= c; a %= M;
b *= c; b %= M;
if (b > M/2) { a = M - a; b = M - b; }
}
return a;
}

long long int maXRangeProduct(int l, int r,int tl,int tr,int v){

//cout<<" invoked for tl="<<tl<<" tr="<<tr<<endl;
if(tr<tl){
//cout<<" return for tl="<<tl<<" tr="<<tr<<"return with value= 0"<<endl;
 cout<<" Node [ "<<tl<<" : "<<tr<<" ]"<<endl;
 cout<<" result to up result="<<1l<<endl;
return 1l;
}
if(tl==tr){
 cout<<" Node [ "<<tl<<" : "<<tr<<" ]"<<endl;
 cout<<" result to up result="<<1l<<endl;
//cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<(1%m)<<endl;
return 1l;}
data d1=query(v,l,r,tl,tr);
int maxIdx=d1.maxIdx;
int minIdx=d1.minIdx;
//if(maxIdx==minIdx)
// return 0;
//cout<<"maxIdx="<<maxIdx<<" minIdx="<<minIdx<<endl;
int max=max(maxIdx,minIdx);
int min=min(maxIdx,minIdx);
if((tl+1)==tr){
//cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<(d1.maxValue-d1.minValue+m)%m<<endl;
cout<<" Node [ "<<tl<<" : "<<tr<<" ]"<<endl;
cout<<" result to up result="<<(d1.maxValue-d1.minValue+m)%m<<endl;
return (d1.maxValue-d1.minValue) ;
}

//cout<<"min="<<min<<" max="<<max<<endl;
long long int left=maXRangeProduct(l,r,tl,max-1,v)%m;
// if(left==0){
//cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<"0"<<endl;
// return 0;}
// long long int right =maXRangeProduct(l,r,min+1,tr,v)%m;
long long int right =maXRangeProduct(l,r,min+1,tr,v)%m;

// if(right==0){
//cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<"0"<<endl;
// return 0;}
/*
long long int brute=1l;
int i=min+1;
int j=max;
// int count=0;
// cout<<"Debug for for loop"<<endl;
// cout<<"tl="<<tl<<" tr="<<tr<<" max="<<max<<" min="<<min<<endl;
// cout<<"i="<<i<<"j="<<j<<endl;
for( ;i<max;i++){
for(j=max ;j<=tr;j++)
{
//count++;
data p=query(v,l,r,i,j);

brute=((brute)*(p.maxValue-p.minValue))%m;
//cout<<"brute="<<brute<<endl;
}
//cout<<"count="<<count<<endl;
}


cout<<"after loop count="<<count<<" brute"<<endl;
*/
long long int pow=(getpow((d1.maxValue-d1.minValue),(min-tl+1)*(tr-max+1)));


if(pow==0){
//cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<"0"<<endl;
return 0;
}
long long int extra=(maXRangeProduct(l,r,min+1,max-1,v));
extra=extra?extra:1l;

long long int result=(((((left*right)%m)*(pow))%m)*inv(extra,m))%m;


cout<<" Node [ "<<tl<<" : "<<tr<<" ]"<<endl;
cout<<"return value of left [ "<<tl<<" : "<<(max-1)<< "]: left="<<left<<endl;
cout<<"return value of right [ "<<(min+1)<<" : "<<tr<< "]: right="<<right<<endl;
cout<<"value of extra ["<<(min+1)<<":"<<(max-1)<<" ] : value=inv["<<extra<<"]= "<<endl;
cout<<"value of ("<<d1.maxValue<<" -"<<d1.minValue<<" ) ^"<<(min-tl+1)*(tr-max+1)<<" = "<<pow<<endl;
cout<<" result to up result="<<result<<endl;
// cout<<" invoked for tl="<<tl<<" tr="<<tr<<"return with value="<<result<<endl;


return result;
}


int main()
{
int T;
scanf("%d",&T);
t=new data[(T+1)<<2];
long long int *p=new long long int[T];
for(int i=0;i<T;i++)
{
scanf("%lld",p+i);
}

build(p,1,0,T-1);
//cout<<" build tree"<<endl;
printf("%lld",maXRangeProduct(0,T-1,0,T-1,1));;


return 0;
}
