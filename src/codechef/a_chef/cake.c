#include<stdio.h>
#define M 1000000007
#define N 1005
long long int x[N],sum[N];
void preprocess()
{
    long long int i,j,summ,a,b;x[1]=1;
    for(i=2;i<N;i++)
    {
      summ=x[1];a=x[1];
      for(j=2;j<=i;j++)
      {
         b=(j*x[j]+a)%M;
         a=x[j];
         x[j]=b;summ=(summ+b)%M;
      }
      sum[i]=summ;
    }
}
int main()
{

   long long int i,j,t,n;
   preprocess();sum[1]=1;
   scanf("%lld",&t);
   while(t--)
   {
      scanf("%lld",&n);
      printf("%lld\n",sum[n]);
   }
   return 0;
}
