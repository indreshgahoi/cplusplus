#include<stdio.h>
#define N 102
int a[2][N][N];
void process(int n)
{
   int i,j,k,t=n;
   a[0][n-2][0]=2;a[0][n-2][1]=0;
   a[1][n-2][0]=1;a[1][n-2][1]=1;t=2;
   for(i=n-3;i>=0;i--)
   {
      for(j=0;j<t;j++)
      a[0][i][j]=a[0][i+1][j]+a[1][i+1][j];a[0][i][j]=0;
      for(j=1;j<t;j++)
      a[1][i][j]=a[0][i+1][j]+a[1][i+1][j-1];
      a[1][i][0]=a[0][i+1][0];a[1][i][j]=1;t++;
   }
}
int main()
{
    int i,j,n,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&j,&n,&k);
        process(n);
        printf("%d %d\n",j,a[0][0][k]+a[1][0][k]);
    }
    return 0;
}
