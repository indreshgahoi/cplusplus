#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 10005
#define LOGMAXN 15
#define dg(v) printf(#v"=%d\n",v);
using namespace std;

int N,root;
int flag[MAXN+1],c[MAXN+1];
int INF=10000000;
int T[MAXN+1],L[MAXN+1],P[MAXN+1][LOGMAXN];
vector< pair<int,int> > adj[MAXN+1];
//c for cost
// L for level
// T[i] holds the parent of node i

void dfs(int cur)
{
    flag[cur]=true;
    int size=adj[cur].size();
    for(int i=0;i<size;i++)
    {
        if(!flag[adj[cur][i].first])
        {
            c[adj[cur][i].first]=c[cur]+adj[cur][i].second;
            T[adj[cur][i].first]=cur;
            L[adj[cur][i].first]=L[cur]+1;
           // dg(cur);

            dfs(adj[cur][i].first);
           // dg(i);
           // dg(adj[cur][i].first);
        }

    }
}

void preprocess()
  {
      int i, j;

  //we initialize every element in P with -1
      for (i = 1; i <= N; i++)
          for (j = 0; 1 << j <= N; j++)
              P[i][j] = -1;

  //the first ancestor of every node i is T[i]
      for (i = 1; i <= N; i++)
          P[i][0] = T[i];

  //bottom up dynamic programing
      for (j = 1; 1 << j <= N; j++)
         for (i = 1; i <= N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }

  int LCA(int p, int q)
  {
      int tmp, log, i;

  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
         log--;

//we find the ancestor of node p situated on the same level
//with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

//we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
     // puts("LCA");
      //dg(p);
      //dg(T[p]);
      return T[p];
  }

int kth(int p,int q,int la ,int k)
{ // we compute kth node form n1 to n2
    //int log ;
    int i;
    if(p==la)
    {
        k=L[q]-L[la]+1-k;
        swap(p,q);
    }
    else if(q==la)
    {

    }
    else if(L[p]-L[la]+1<k)
    {
        k=L[p]+L[q]-2*L[la]-k+2;
        swap(p,q);
    }
   // for(log=1;1<<log<=L[p];log++);
     //log--;
     k--;//kth ancestor is equal to kth node
     if(k==0)
       return p;
     i=0;
     while(k!=(1<<i))
     {

        for(i=0;1<<i<=k;i++);
        i--;
        if((1<<i)==k)
         return P[p][i];
        k-=(1<<i);
        p=P[p][i];

     }

    return P[p][i];

}




int main()
{
    int test ,n1,n2,la,a,b,c1,k;
    char s1[10];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            adj[i].clear(),c[i]=INF,flag[i]=false;
        }
        for(int i=1;i<=N-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c1);
              adj[a].push_back(make_pair(b,c1));
              adj[b].push_back(make_pair(a,c1));
        }

        root=rand()%N+1;
        L[root]=0;
        c[root]=0;
       // dg(root);
        dfs(root);
        T[root]=-1;
        preprocess();

        while(true){
            scanf("%s",s1);

        if(s1[1]=='T'){

          scanf("%d%d%d",&n1,&n2,&k);
          la=LCA(n1,n2);
          printf("%d\n",kth(n1,n2,la,k));

         }
        else if(s1[1]=='I'){
             scanf("%d%d",&n1,&n2);
             la=LCA(n1,n2);
             //printf("la=%d\n",la);
             //puts("hello");
            // dg(n1);
            // dg(n2);
            // dg(la);
            // dg(c[n1]);
             //dg(c[n2]);
             printf("%d\n",c[n1]+c[n2]-(2*c[la]));
         }
         else if(s1[1]=='O')
         {
             break;
         }
     }
     }

    return 0;
}
