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
#define N 100
#define N1 10100

typedef int I;
typedef long long int LL;

int R[N+1][N+1],C1[N+1][N+1],C2[N+1][N+1];
char visit[N+1][N+1];
I n=((N+1)*(N+1)),dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},row,col;


//typedef int qelmtyp;
struct point
{
    int x;
    int y;
}c1,c2,r;
struct Q
{   struct point items[N1+1];
    int front,end;
};
typedef struct Q *Queue ;

int empty(Queue q)
{
    return (q->end==q->front)? 1:0;
}
void insert(Queue q,struct point elm)
{
    if(q->end==n)
      q->end=1;
    else
       (q->end)++;
    if(q->end==q->front){
       printf("q overflow");
       exit(1);
    }
    q->items[q->end].x=elm.x;
    q->items[q->end].y=elm.y;
}

struct point pop(Queue q)
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







void bfs(struct point start,int mat[][N+1])
{
    Queue q;
    q=(struct Q*)malloc(sizeof(struct Q));
    q->front=q->end=n;

    I j;
    struct point tmp,i;
    //memset(dist,0,sizeof(int)*(n+1));
   // memset(visit,0,sizeof(int)*(n+1));
    //mcl(visit);
    insert(q,start);
    visit[start.x][start.y]=1;
    while(!empty(q))
    {
        tmp=pop(q);
       // printf("tmp :%d  %d\n",tmp.x,tmp.y);

        FOR(j,0,3){
           i.x=tmp.x+dx[j];
           i.y=tmp.y+dy[j];
          if( i.x>=1 && i.y>=1 && i.x<=row && i.y<=col && visit[i.x][i.y]==0)
          { //printf("i :%d  %d\n",i.x,i.y);
              mat[i.x][i.y]=mat[tmp.x][tmp.y]+1;
              visit[i.x][i.y]=1;
              insert(q,i);
          }
        }

    }
    free(q);

}

int main()
{
   I i,k,l,j,safe=0;
   struct point stc1,stc2,str;
   // n=(N+1)*(N+1);

       gi(row);
       gi(col);


       gi(l);
       FOR(j,1,l)
        {
            //FOR(i,0,row)
              // FOR(k,0,col)
                // visit[i][k]=C1[i][k]=C2[i][k]=R[i][k]=0;
            scanf("%d%d%d%d%d%d",&str.x,&str.y,&stc1.x,&stc1.y,&stc2.x,&stc2.y);
          //  printf("%d%d\n",str.x,str.y);

         safe=0;
         R[str.x][str.y]=0;
         C1[stc1.x][stc1.y]=0;
         C2[stc2.x][stc2.y]=0;

         FOR(i,0,row)
               FOR(k,0,col)
                 visit[i][k]=0;
         bfs(str,R);
        /*  FOR(i,0,row){
               FOR(k,0,col)
                 printf(" %d ",R[i][k]);
               printf("\n");
          }
          printf("\n\n");*/

         FOR(i,0,row)
               FOR(k,0,col)
                 visit[i][k]=0;
         bfs(stc1,C1);
           /* FOR(i,0,row){
               FOR(k,0,col)
                 printf(" %d ",C1[i][k]);
               printf("\n");
          }
          printf("\n\n");*/

         FOR(i,0,row)
               FOR(k,0,col)
                 visit[i][k]=0;
         bfs(stc2,C2);
        /*   FOR(i,0,row){
               FOR(k,0,col)
                 printf(" %d ",C2[i][k]);
               printf("\n");
          }
          printf("\n\n");*/

         FOR(i,1,row)
         {
             if((R[i][1]< C1[i][1] && R[i][1]< C2[i][1])||
                (R[i][col]< C1[i][col] && R[i][col]< C2[i][col])||
                ((R[i][1]>C1[i][1] && (C1[i][1]-R[i][1])%2!=0)&&
                (R[i][1]>C2[i][1] && (C2[i][1]-R[i][1])%2!=0))||
                ((R[i][col]>C1[i][col] && (C1[i][col]-R[i][col])%2!=0)&&
                (R[i][col]>C2[i][col] && (C2[i][col]-R[i][col])%2!=0)))
            {
               safe=1;
               break;
             }
         }

         if(!safe)
            FOR(i,2,col)
           {
             if((R[1][i]< C1[1][i] && R[1][i]< C2[1][i])||
                (R[row][i]< C1[row][i] && R[row][i]< C2[row][i])||
                ((R[1][i]>C1[1][i] && (C1[1][i]-R[1][i])%2!=0)&&
                (R[1][i]>C2[1][i] && (C2[1][i]-R[1][i])%2!=0))||
                ((R[row][i]>C1[row][i] && (C1[row][i]-R[row][i])%2!=0)&&
                (R[row][i]>C2[row][i] && (C2[row][i]-R[row][i])%2!=0)))
            {
               safe=1;
               break;
             }
           }

        if(safe)
           printf("YES\n");
        else
           printf("NO\n");


        }

   return 0;
}
