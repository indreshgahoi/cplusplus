/http://www.codechef.com/MAY12/problems/TWSTR
//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) int((a).size())
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define all(c) (c).begin(), (c).end()
#define maX(a,b) (a>b?a:b)
#define miN(a,b) (a<b?a:b)
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) lower_bound(all(arr),ind)-arr.begin())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;
typedef vector< PII > VPII;
/*Main Code*/
int main()
{
//freopen("twstr.txt","r",stdin);
int n,d;
char *p;
s(n);
VPII pri(n);
char in[n][2000];
REP(i,n)
{
ss(in[i]);
s(d);
pri[i]=mp(d,i);
}
sort(all(pri));
//reverse(all(pri));
int q;
s(q);
char str[2000];
REP(i,q)
{
int ok=0;
ss(str);
int j;
for(j=n-1;j>=0;j--)
{
int match=1;
int slen=strlen(str);
int inlen=strlen(in[pri[j].second]);
for(int m=0;m<slen && m<inlen;m++)if(in[pri[j].second][m]!=str[m]){match=0;break;}
if(match){ok=1;break;}
//p=strstr(in[pri[j].second],str);
//if(p==in[pri[j].second])break;
}
if(ok)cout<<in[pri[j].second]<<endl;
else printf("NO\n");
}
return 0;
}
