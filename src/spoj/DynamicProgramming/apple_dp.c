/*A table composed of N x M cells, each having a certain quantity of apples, is given.
You start from the upper-left corner. At each step you can go down or right one cell.
Find the maximum number of apples you can collect.


For i = 0 to N - 1
   For j = 0 to M - 1
   S[i][j] = A[i][j] +
      max(S[i][j-1], if j>0 ; S[i-1][j], if i>0 ; 0)

Output S[n-1][m-1]

*/
#include<stdio.h>
#define FOR(a,b,i) for(i=a;i<=b;i++)
int main()
{
    int row,col,i,j,a,b;
    printf("Enter the no of row and column:");
    scanf("%d%d",&row,&col);
    int a[row][col];
    int c[row][col];
    FOR(0,row-1,i)
    {
        FOR(0.col,j)
        {
            scanf("%d",&a[i][j]);
            c[i][j]=a[i][j];
        }
    }

    FOR(0,row-1,i)
    {
        FOR(0.col,j)
        {
          c[i][j]=a[i][j]+( a=i>0?c[i-1][j]:0 >= b=j>0?c[i][j-1]:0?a:b) ;
        }
    }
    printf("maximum no of apple:%d",c[row-1][col-1]);
}

