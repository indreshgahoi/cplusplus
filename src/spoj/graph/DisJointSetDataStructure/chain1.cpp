#include<cstdio>
using namespace std;
static const int maxn=50000;
int F[maxn],P[maxn],n;

void set(int n)
{
    for(int i=0;i<n;i++)
      F[i]=i,P[i]=0;
}
int find(int x)
{
    if(F[x]==x) return x;
    find(F[x]);
     P[x]+=P[F[x]];P[x]%=3;
     return F[x]=F[F[x]];
}
bool judge(int t, int x,int y)
{
    if(x>=n || y>=n) return false;
    int i=find(x),j=find(y);
    if(i==j) return P[x]==(P[y]+t)%3;
    else
    {
        F[i]=j;
        P[i]=(t-P[x]+P[y])+9;
        P[i]%=3;
        return true;
    }
}

void solve()
{
    int k,t,x,y,ans=0,m=1;
    scanf("%d%d",&n,&k);set(n);
    while(k--)
    {
        scanf("%d%d%d",&t,&x,&y);
        ans+=!judge(t-1,x-1,y-1);
        printf("%d %d\n",m,ans);
        m++;
    }
    /*for(int i=0;i<n;i++)
    {
       printf("%d: %d %d\n",i,F[i],P[i]);
    }*/
    printf("%d\n",ans);

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
