#include<stdio.h>
int phi(int n)
{
  int i,j,result=n;
  for(i=2;i*i<=n;i++)
  {
      if(n%i==0)
      {
          result-=result/i;
          while(n%i==0)n/=i;
      }

  }
  if(n>1)result-=result/n;
  return result;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        printf("%d\n",phi(k));
    }
    return 0;
}
