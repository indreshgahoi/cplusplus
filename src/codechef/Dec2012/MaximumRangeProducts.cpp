/*
 * MaximumRangeProducts.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: indresh
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include <utility>
#include <cstdio>
using namespace std;
long long int m=1000000007;
pair<long long int,pair<long long int,long long int> > *t;
pair<long long int,pair<long long int,long long int> > combine(pair<long long int,pair<long long int,long long int> > p1,pair<long long int,pair<long long int,long long int> > p2)
{
	long long int min=p1.first,max=p1.second.first;
	//cout<<"combine "<<min<<" "<<max<<endl;
     if(min>p2.first)
    	 min=p2.first;
     if(max<p2.second.first)
    	max=p2.second.first;
    // cout<<"combine "<<min<<" "<<max<<endl;
  return make_pair(min,make_pair
		  (max,
				  (
						  ((((max-min)%m)*(((p1.second.second)%m)*((p2.second.second)%m))%m))%m)
		   ));
}
bool flags[100][100];
void build(long long int *a, int v,int tl,int tr){

	//base case

	if(tl==tr)
	{
		t[v]=pair<long long int,pair<long long int,long long int> >(a[tl],make_pair(a[tl],1l));
		cout<<"tl="<<tl<<" assign to t[v"<<v<<"] first="<<t[v].first<<" second="<<t[v].second.first<<" third="<<t[v].second.second<<endl;
	}
	else
	{

		int tm=(tl+tr)>>1;
		//if(!flags[tl][tm]){
		//	cout<<endl<<" calling interval tl="<<tl<<" tm="<<tm<<endl;
		build(a,v<<1,tl,tm);
		//flags[tl][tm]=true; }
		//if(!flags[tl][tm]){
			build(a,(v<<1)+1,tm+1,tr);
		//	cout<<endl<<" calling interval tm="<<tm<<" tr="<<tr<<endl;
			//	flags[tl][tm]=true; }
		//else if((tm+1)==tr){cout<<endl<<" calling interval tm="<<tm+1<<" tr="<<tr<<endl;
		//	 build(a,(v<<1)+1,tm+1,tr);}



		cout<<"going to combine v*2="<<(v<<1)<<" and v*2+1="<<((v<<1)+1)<<endl;
		cout<<"  v="<<(v<<1)<<" first="<<t[v<<1].first<<" second="<<t[v<<1].second.first<<" third="<<t[v<<1].second.second<<endl;
		cout<<"  v="<<((v<<1)+1)<<" first="<<t[(v<<1)+1].first<<" second="<<t[(v<<1)+1].second.first<<" third="<<t[(v<<1)+1].second.second<<endl;
		t[v]=combine(t[v<<1],t[(v<<1)+1]);
		cout<<" after combine v="<<v<<" first="<<t[v].first<<" secomd="<<t[v].second.first<<" third="<<t[v].second.second<<endl;
		//}
		//}
}

}

pair<long long int,pair<long long int,long long int> > query(long long int v,int tl,int tr,int l,int r){
	if(l==tl && r==tr)
		return t[v];

		int tm=(tl+tr)>>1;
		if(r<=tm)
		return query(v<<1,tl,tm,l,r);
		if(l>tm)
		return query((v<<1)+1,tm+1,tr,l,r);

		return combine(query(v<<1,tl,tm,l,tm),query((v<<1)+1,tm+1,tr,tm+1,r));
}

int main(){
	int T;
	cin>>T;
	t=new pair<long long int,pair<long long int,long long int> >[(T+1)<<2];
	long long int *p=new long long int[T];
	for(int i=0;i<T;i++)
	{
	 scanf("%lld",(p+i));
	}
	//for(int i=0;i<100;i++)
		// for(int j=0;j<100;j++)
			// flags[i][j]=false;
	build(p,1,0,T-1);
/*	for(int i=1;i<6;i++ )
		{
			cout<<t[i].first<<" "<<t[i].second<<endl;
		}
*/
	long long int max=1;
	long long int m=1000000007;
	for(int i=0;i<T;i++)
		for(int j=i+1;j<T;j++)
		{
		data p=query(1,0,T-1,i,j);

			max=(
					(max%m)*
					        (
							 (((p.second.first)%m)-(p.first)%m)
							 )
				 )%m;
		}

	printf("%lld %lld\n",t[1].second.second,max);
	return 0;
}
