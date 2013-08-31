#include<stdio.h>
#define N 100
char str[N][N];
int n,len;
int main()
{
  int i,j,k,t,r,c;
  scanf("%d",&r);
  for(i=0;i<r;i++)scanf("%s",str[i]);
  printf("prnt the string\n");
  for(i=0;i<r;i++)
  {
      printf("%s\n",str[i]);
  }
}

