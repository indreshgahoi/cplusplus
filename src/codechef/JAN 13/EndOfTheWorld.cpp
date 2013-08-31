/*
 * EndOfTheWorld.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: indresh
 */
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
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
#include <string.h>
using namespace std;
#define MAX_INT 1000000
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define si(i)      int i; scanf("%d",&i);
#define gi(i)       scanf("%d",&i);
#define SET(x,a) memset(x,a,sizeof(x));
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF 100000000000000000LL
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define f first
#define s second
typedef long long LL;

// FAST I/O
#define MAXX 10000000
char *ipos, *opos, InpFile[MAXX], OutFile[MAXX], DIP[30];

inline int input_int(int flag = 0){
while(*ipos <= 32) ++ipos;
if ( flag ) return (*ipos++ - '0');
int x = 0, neg = 0; char c;
while( true ) {
c = *ipos++; if(c == '-') neg = 1;
else{
if(c <= 32) return neg ? -x : x;
x = (x << 1) + (x << 3) + c - '0';
}
}
}

inline LL input_LL(int flag = 0){
while(*ipos <= 32) ++ipos;
if ( flag ) return (*ipos++ - '0');
LL x = 0, neg = 0; char c;
while( true ) {
c = *ipos++; if(c == '-') neg = 1;
else{
if(c <= 32) return neg ? -x : x;
x = (x << 1) + (x << 3) + c - '0';
}
}
}

inline void input_st(char *s){
while(*ipos <= 32) ++ipos;
int pos = 0;char c;
while( true ) {
c = *ipos++;
if(c <= 32) {s[pos] = '\0'; break;}
else s[pos++] = c;
}
}

inline void output(int x){
int y;
int dig = 0;
while(x || !dig) {y = x / 10; DIP[dig++] = x - ((y << 3) + (y << 1)) + '0'; x = y;}
while(dig--) *opos++ = DIP[dig];
}
inline void InitFASTIO(){
ipos = InpFile; opos = OutFile;
fread(InpFile, MAXX, 1, stdin);
}
inline void FlushFASTIO(){
fwrite(OutFile, opos - OutFile, 1, stdout);
}
//End of FAST I/O


// Main code start
bool open[355][355];
int num[350][350];
int prime[10000005];
int n;
inline void preprocess()
{
    int i,j;
  memset(prime,1,sizeof(prime));
  prime[1]=0;
  prime[0]=0;
  int count=1;
  int sq=(int)sqrt(10000000+.0)+1;
 // printf("%d",sq);
  for(i=2;i<=10000000;i++)
    if(prime[i])
	{ prime[i]=count++;
	  for(j=2*i;i<=sq && j<=10000000 ;j=j+i)
	      prime[j]=0;

	}
 // printf("%d",count);
}
inline void dfsodd(int i,int j){
	stack<pair<int,int> > st;
		st.push(make_pair(i,j));
		while(!st.empty()){
			pair<int,int> p=st.top();
			st.pop();
			if(p.f<0 || p.s<0 || p.f>=n || p.s>=n|| open[p.f][p.s] || !(num[p.f][p.s]&1))
					continue;
			    open[p.f][p.s]=1;
				st.push(make_pair(p.f-1,p.s));
				st.push(make_pair(p.f+1,p.s));
				st.push(make_pair(p.f,p.s-1));
				st.push(make_pair(p.f,p.s+1));
		}
}
inline void dfseven(int i,int j){


	stack<pair<int,int> > st;
	st.push(make_pair(i,j));
	while(!st.empty()){
		pair<int,int> p=st.top();
		st.pop();
		if(p.f<0 || p.s<0 || p.f>=n || p.s>=n|| open[p.f][p.s] || (num[p.f][p.s]&1))
			continue;
		    open[p.f][p.s]=1;
			st.push(make_pair(p.f-1,p.s));
			st.push(make_pair(p.f+1,p.s));
			st.push(make_pair(p.f,p.s-1));
			st.push(make_pair(p.f,p.s+1));
	}
}
int main(){

	InitFASTIO();
    preprocess();
    int T=input_int();
    while(T--){
    n=input_int();
    SET(open,0);
    long long ans=0l;
    REP(i,n)
     REP(j,n){
      num[i][j]=input_int();
      if(prime[num[i][j]]){
    	  open[i][j]=1;
          		ans+=(prime[num[i][j]]-1l);
      }
    }

	REP(i,n)
	 REP(j,n){
    	if(open[i][j])
    		continue;

    	int t=num[i][j];

            if(t&1)
    	      ans+=((t>>1)+2),dfsodd(i,j);
    	    else
    	      ans+=((t>>1)),dfseven(i,j);

     }
	//output(ans); *opos++ = '\n';
	printf("%lld\n",ans);

    }
   // FlushFASTIO();
	return 0;
}

