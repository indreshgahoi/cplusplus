/*
 * BeautifulStrings.cpp
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

#define FOR(i,s,e) for(int i=s;i<e;i++)
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

char s[502];

int buff[27];
int res=0;
void solve(){
	int i=0;
	while(s[i]){
		if(islower(s[i]))
		 buff[s[i]-'a']++;
		else if(isupper(s[i]))
               buff[s[i]-'A']++;
		i++;
	}
	sort(buff,buff+26);
   for(int j=26;j>=1;j--)
	res+=j*buff[j-1];
}
int main(){
	freopen("beautiful_stringstxt","rt",stdin);
	freopen("BeautifulStrings.out","wt",stdout);
 si(T)
 T++;
 gets(s);
 FOR(i,1,T){
	 gets(s);

	 FOR(j,0,26)
	 buff[j]=0;
	 res=0;
	 solve();
	 printf("Case #%d: %d\n",i,res);
 }

	return(0);
}

