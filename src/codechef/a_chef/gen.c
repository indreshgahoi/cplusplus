#include<stdio.h>
int main()
{
long long int sum=0;
long long int sumc[1001]={0};
int n,k,i,j;
long long int mod=1000000007;
scanf("%d",&n);
while(n--)
{
long long int su[1001]={0};
scanf("%d",&k);
if(sumc[k])
{
if(k!=1)
printf("%lld\n",sumc[k]+1);
else
printf("1\n");
continue;
}
else
{
su[1]=1;
i=1;
sum=0;
sumc[1]=1;
while(i!=1000)
{
for(j=i;j>=1;j--)
{
su[j+1]=(su[j+1]+su[j])%mod;
su[j]=(su[j]*j)%mod;
sumc[i+1]=(sumc[i+1]%mod+su[j+1]%mod)%mod;
}
i++;
}
if(k!=1)
printf("%lld\n",sumc[k]+1);
else
printf("1\n");
}
}

return 0;
}
