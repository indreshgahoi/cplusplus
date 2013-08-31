/* this program is to find the maximum sum sub array contiguous sub array should be :)
algorithm here is used known as the Kadane's algorithm*/
#include<stdio.h>
int kadanesum(int arr[],int n,int *maxstart,int *maxend)
{
int sum=0;
int i,j,maxsum=-32766;
j=0;
for(i=0;i<=n-1;i++)
{
sum=sum+arr[i];
if(sum>maxsum)
{
*maxstart=j;
*maxend=i;
maxsum=sum;
}
if(sum<0)
{
j=i+1;
sum=0;
}
}
return maxsum;
}
int main(void)
{
int arr[100];
int maxstart=0,maxend=0;
int n,i,max;
scanf("%d",&n);
for(i=0;i<=n-1;i++)
scanf("%d",&arr[i]);
max=kadanesum(arr,n,&maxstart,&maxend);
printf("the maximum sum is %d\n",max);
for(i=maxstart;i<=maxend;i++)
printf("%d  ",arr[i]);
return 0;
}