#include<stdio.h>
#include<string.h>

long long int solve(long long int N ,long long int K)
{
    long long int i=1ll ,sum=0;

    for(i=1;i<=K;i++)
      sum +=K%i;

     return (sum+((N-K)*K));


}



int main()
{
    long long int N,K,res;
   {
       scanf("%lld%lld",&N,&K);
       res=solve(N,K);
       printf("%lld\n",res);
   }

    return 0;
}
