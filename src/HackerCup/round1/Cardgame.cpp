/*
 * Cardgame.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: indresh
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>

#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

#define MAX_INT 9999999

#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define dbgi(x)    printf(#x" = %d\n",x);
#define dbgll(x)   printf(#x" = %ll\n",x);
#define dbgd(x)    printf(#x" = %f\n",x);
#define nl         printf("\n");

#define gi(v)      scanf("%d",&v);
#define si(v)       int v; gi(v);
#define gll(v)     scanf("%lld",&v);
#define sll(v)     long long v;gll(v)
#define gd(v)      scanf("%f",&v);
#define sd(v)      ld v;gd(v)
#define sui(v)     scanf("%u",&v);
#define sull(v)    scanf("%ull",&v);

#define gs(s)      scanf("%s",s);
#define ps(s)      puts(s);
#define pi(i)      printf("%d\n",i);
#define pll(i)     printf("%ll\n",i);
#define pd(i)      printf("%f\n",i);

#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define mp     make_pair
#define pb     push_back
#define EPS 1e-6
#define sqr(a) ((a)*(a))
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long LL;
typedef vector<long long > vll;
typedef pair<int, int > pii;
typedef vector< pii > vpii;

int GCD(int a,int b){
	int r;
	if(a<0) a=-a;
	if(b<0) b=-b;
	while(a){r=b; b=a; a=r%a;}
	return b;
}
LL inv[1010000];
LL fact[1010000], factinv[1010000];


LL comb(int a, int b)
{
	assert(a <= 1000000);
	if(a<b)
		return 0;
	return (((fact[a] * factinv[b])%mod) * factinv[a-b])%mod;
}
void preprocess(){
	inv[1] = 1;
	FOR(i,2,1010000) inv[i] = ((mod- mod/i) * inv[mod%i])%mod;
	fact[0] = factinv[0] = 1;
	FOR(i,1,1010000){
		fact[i] = (fact[i-1] * i) % mod;
		factinv[i] = (factinv[i-1] * inv[i]) % mod;
	}
}
LL solve(map<LL,LL> &m,LL N,LL K){
	LL sum=0;
	for(map<LL,LL>::reverse_iterator it=m.rbegin();it!=m.rend();it++){
		LL f=it->first,s=it->second;
		//	cout<<"f "<<f<<s<<endl;
		while(s--){
			N--;
			sum=((sum%mod)+((f%mod)*(comb(N,K-1)%mod))%mod)%mod;
			// cout<<" sum ="<<sum<<endl;
		}

	}
	return sum;
}
int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.out","wt",stdout);
	int T;
	preprocess();
	cin>>T;
	for(int i=1;i<=T;i++){
		int N,K;
		cin>>N>>K;
		LL n;
		map<LL,LL> m;

		REP(j,N)
		{
			cin>>n;
			if(m[n]==0)
				m[n]=1;
			else
				m[n]++;

		}
		cout<<"Case #"<<i<<": "<<solve(m,N,K)<<endl;
	}
	return 0;
}
