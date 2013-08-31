#include<stdio.h>
int isConsecutive(int *a,int n)
{
int visited[10000]={0},max=-32767,min=32767,i;
for(i=0;i<=n-1;i++)
{
if(visited[a[i]]==1)
return 0;
visited[a[i]]=1;
if(max<a[i])
max=a[i];
if(min>a[i])
min=a[i];
}
if(max-min+1==n)
return 1;
else
return 0;
}
int main()
{
int *a,n,i,c;
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
c=isConsecutive(a,n);
if(c)
printf("YA");
else
printf("NAA");
return 0;
}