#include<stdio.h>
#include<string.h>
char prime[1000001];
long long int sum[1000001];
void preprocess()
{
  long long int i,j;
  memset(prime,1,sizeof(prime));
  sum[0]=sum[1]=0;
  for(i=2;i<=1000000;i++)
    if(prime[i])
	{
	  for(j=2*i;j<=1000000 && i*i<=1000000;j=j+i)
	      prime[j]=0;
	sum[i]=sum[i-1]+i;	  
	}
    else
	{
        sum[i]=sum[i-1];
    }		

}
int main()
{
  int t,n;
  sum[0]=sum[1]=0;
  preprocess();
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    printf("%lld\n",sum[n-1]);	
  }
 return 0;
}
