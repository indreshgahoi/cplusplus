/*
 * FindTheMin.cpp
 *
 *  Created on: Jan 27, 2013
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


using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long LL;
typedef vector<long long > vll;
typedef pair<int, int > pii;
typedef vector< pii > vpii;

long long n,k,a,b,c,r,ans;

long long gn(vector<long long > &m){
	multiset<long long> mset;
	set<long long> s;
	m.pb(a);
    mset.insert(a);
    for(int i=0;i<=k;i++)
   	s.insert(i);
    if(a<(k+1)){
      s.erase(a);
    }

    for(int i=1;i<k;i++){
	m.push_back(((m[i-1]*b)%r+c)%r);
	mset.insert(m[i]);
    if(m[i]<(k+1)){
         s.erase(m[i]);
    }
	}

	long long nextInsert=0,nextidx=0;

	for(int i=k;i<(2*k);i++)
	{

      nextInsert=(*s.begin());
      s.erase(s.begin());
	  mset.erase(mset.find(m[i-k]));
	  mset.insert(nextInsert);

	    if(m[i-k]<(k+1)){
	    	if(mset.find(m[i-k])==mset.end())
	        s.insert(m[i-k]);
	    }
	    m.push_back(nextInsert);


   }
 return m[k + (n-k-1) % (k+1)];
}
 long long solve(){

	 vector<long long> v;
	 return gn(v);

 }

 int main(){
	    freopen("FindTheMinimum.txt","rt",stdin);
	 	freopen("FindTheMinimum1.out","wt",stdout);
	 si(T)
	 FOR(i,1,T){
		scanf("%lld%lld%lld%lld%lld%lld",&n,&k,&a,&b,&c,&r);
		printf("Case #%d: %lld\n",i,solve());
	 }

	 return 0;
 }

