//http://www.codechef.com/MAY12/problems/TWSTR
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
    int t;
    for(s(t);t--;)
    {
        int n,m,q;
        scanf("%d%d",&n,&m);
        VI C(m);
        VVI NM(n,VI(m,0));
        REP(i,m)s(C[i]);
        REP(i,n)REP(j,m)s(NM[i][j]);
        int mn=INF,ret=0;
        REP(i,m)
        {
            int diff=0;
        REP(j,n)
        {
            q=90-NM[j][i];
            if(q<0)q=-q;
            diff+=q;
        }
        if(diff<mn)
        {
            mn=diff;
            ret=i;
            //cout<<ret<<endl;
        }
        }
        printf("1\n%d\n",ret+1);
    }
    return 0;
}
