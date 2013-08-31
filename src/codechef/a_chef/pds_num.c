#include<stdio.h>
#define N 100000000
long long pds[N];
int main()
{

    long long int i,j,k,n=0,sum=0,mult;
    for(i=1;i<1000000000;i++)
    {
      sum=0;k=i;mult=1;
      while(k>0)
      {
        sum+=k%10;mult*=k%10;k/=10;
      }
      if(mult%sum==0)
      {
          printf("%lld %lld\n",++n,i);
      }
    }
    return 0;
}
