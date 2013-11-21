#include<cstdio>
#include<algorithm>
#include<vector>
#define N 10005
#define pb(a) push_back(a)
using namespace std;
vector<int> graph[N];
char p[N]={0},cycle=0;

void dfs(int s ,int pt)
{
	if(cycle)
		return;
	p[s]=1;
	for(int i=0;i<graph[s].size();i++)
	{
		if(p[graph[s][i]]==0 && !cycle){
			dfs(graph[s][i],s);}
		else if(graph[s][i]!=pt){
			cycle=1;
			return;
		}
	}
}
int main()
{
	int i,n,m,s,d;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&s,&d);
		graph[s].pb(d);
		graph[d].pb(s);
	}
	for(i=1;i<=n;i++)
	{ if(cycle)
		break;
	if(p[i]==0)
		dfs(i,0);

	}
	if(cycle)
		printf("NO");
	else
		printf("YES");


	return 0;
}
