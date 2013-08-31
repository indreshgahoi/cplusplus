#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include <cstdio>
#define N 100001
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
ll el[N];
ll sm[N],gl[N];
multiset<ll> mset;
int main(){

 int n;

 scanf("%d",&n);

 for(int i=0;i<n;i++)
{
	scanf("%ld",&el[i]);
}

sm[0]=0;
mset.insert(el[0]);
multiset<ll>::iterator it;
FOR(i,1,n)
{       mset.insert(el[i]);
	it =mset.lower_bound(el[i]);
	cout<<" i="<<i<<" val="<<(*it)<<endl;
	if(it!=mset.end()){
	  cout<<" i="<<i<<" val="<<(*it)<<endl;
		sm[i]=distance(mset.begin(),it);
	  
	}
	
	
	
}

mset.clear();
cd 
gl[n-1]=0;
mset.insert(el[n-1]);

for(int i=n-2;i>=0;i--){
	it=mset.upper_bound(el[i]);
	
	if(it!=mset.end())
	{       //cout<<"val="<<(*it)<<endl;
		gl[i]=distance(it,mset.end());
		//cout<<"distance="<<gl[i]<<" i="<<i;
	  
	}
	mset.insert(el[i]);
}

 ll count =0;
 map<long long,int> m;
 FOR(i,0,n){
	cout<<" "<<sm[i];
	m[el[i]]=-1;
}
cout<<" "<<endl;
FOR(i,0,n){
	cout<<" "<<gl[i];
}
 

FOR(i,0,n){
   
       if(m[el[i]]!=-1){
	 count-=((sm[m[el[i]]]) *gl[i]);
	 cout<<" subtract="<< ((sm[m[el[i]]]) *gl[i])<<" for i="<<i<<" eli ="<<el[i]<<endl;
	} 
	else {
	  count+=(sm[i]*gl[i]);
	  cout<<" add"<<" i="<<i<<" "<<(sm[i]*gl[i])<<endl;
	}
	//cout<<"count="<<count<<" for i="<<i<<endl;
	m[el[i]]=i;
}
cout<<count;
 return 0;
}
