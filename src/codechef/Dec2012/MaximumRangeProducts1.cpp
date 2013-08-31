/*
 * MaximumRangeProducts1.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: indresh
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<utility>
#define max(a,b)  a>b?a:b
#define min(a,b)  a<b?a:b
using namespace std;
long long int m=1000000007;
struct data{
	int minIdx;long long int minValue;
	int maxIdx;long long int maxValue;
}*t;
data make_data(long long int  value, int idx)
{   data d1;
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
	long long int l=x;
	cout<<"p="<<p<<" "<<" x="<<x<<endl;
  if(p==0)
	  return 0l;
	while(x!=0)
	{
		if(x&1)
			res=((res%m)*(p%m))%m;

		    x=x>>1;
			p=((p%m)*(p%m))%m;

	}
	cout<<"px="<<p<<"^"<<l<<" "<<res<<"  x="<<x<<endl;
	return res%m;
}

long long int maXRangeProduct(int l, int r,int tl,int tr,int v){

	cout<<" invoked for tl="<<tl<<" tr="<<tr<<endl;
	if(tl>tr)
		return 0;
	if(tl==tr)
		return 1l%m;
		data d1=query(v,l,r,tl,tr);
	int maxIdx=d1.maxIdx;
	int minIdx=d1.minIdx;
	if(maxIdx==minIdx)
		return 0l;
	cout<<"maxIdx="<<maxIdx<<" minIdx="<<minIdx<<endl;
	int max=max(maxIdx,minIdx);
	int min=min(maxIdx,minIdx);
	if((tl+1)==tr)
			return (d1.maxValue-d1.minValue)%m ;

    cout<<"min="<<min<<" max="<<max<<endl;
    long long int left=maXRangeProduct(l,r,tl,max-1,v)%m;
    if(left==0l)
    	return 0l;
    long long int right =maXRangeProduct(l,r,min+1,tr,v)%m;
    if(right==0l)
        	return 0l;
    long long int pow=getpow((d1.maxValue-d1.minValue+m)%m,(min-tl+1)*(tr-max+1))%m;
    if(pow==0l){
    	return 0l;
    }
    long long int result=(((left*right)%m)*pow)%m;
	return result;
}


int main(){
	int T;
	cin>>T;
	t=new data[(T+1)<<2];
	long long int *p=new long long int[T];
	for(int i=0;i<T;i++)
	{
	 scanf("%lld",(p+i));
	}

	build(p,1,0,T-1);
	//cout<<" build tree"<<endl;
	cout<<maXRangeProduct(0,T-1,0,T-1,1)%m<<endl;


	return 0;
}
