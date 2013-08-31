#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n)   for(i=0;i<n;i++)
#define EVER          while(1)
#define true 1
#define false 0
#define  dbgi(x)  printf(#x" = %d\n",x);
#define  dbgll(x) printf(#x" = %ll\n",x);
#define gi(i)         scanf("%d",&i);
#define gll(i)        scanf("%lld",&i);
#define gd(i)         scanf("%f",&i);
#define gui(i)        scanf("%u",&i);
#define gull(i)       scanf("%ull",&i);
#define gs(s)         scanf("%s",s);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));

#define N 10010
typedef int I;
typedef long long int LL;

char adj[N+1][N+1];
char visit[N+1];
I dist[N+1],n;
//typedef int qelmtyp;
struct Q
{   I items[N+1];
    int front,end;
};
typedef struct Q *Queue ;

int empty(Queue q)
{
    return (q->end==q->front)? 1:0;
}
void insert(Queue q,I elm)
{
    if(q->end==n)
      q->end=1;
    else
       (q->end)++;
    if(q->end==q->front){
       printf("q overflow");
       exit(1);
    }
    q->items[q->end]=elm;
}

I pop(Queue q)
{
    if(empty(q))
    {
       printf("q underflow");
       exit(1);
    }
    if(q->front==n)
     q->front=1;
    else
    q->front++;
   return q->items[q->front];
}







I bfs(I start)
{
   /* Queue q;
    q=(struct Q*)malloc(sizeof(struct Q));
    q->front=q->end=n;*/
    queue<int> myqueue;
    I tmp,i;
    memset(dist,0,sizeof(int)*(n+1));
    memset(visit,0,sizeof(int)*(n+1));
    //mcl(visit);
    myqueue.insert(start);
    visit[start]=1;
    while(!myqueue.empty())
    {
        tmp= myqueue.front();
        myqueue.pop();
        FOR(i,1,n)
          if(tmp!=i && adj[tmp][i] && visit[i]==0)
          {
              dist[i]=dist[tmp]+1;
              visit[i]=1;
              myqueue.insert(i);
          }

    }
    int max=1;
    FOR(i,1,n)
      if(dist[i]>dist[max])
       max=i;
  return max;
}

int main()
{
   I p,q,i,root,res,ans;
   //adj=(char**)malloc(sizeof(char)*(N+1)*(N+1));
   memset(adj,0,sizeof(char)*(n+1)*(n+1));
       gi(n);

       FOR(i,1,n-1)
        {
            gdi(p,q)
            adj[p+1][q+1]=adj[q+1][p+1]=1;
        }

        root=1;
        ans=bfs(root);
        pi(ans);
        res=bfs(ans);
        pi(res);
        res=dist[res];
        pi(res);

   return 0;
}
