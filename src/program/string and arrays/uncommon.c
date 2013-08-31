
// printing the uncommon elements of two sorted arrays
// just a merging like technique if commion jus increase the pivot of both points else
// incrementing the lowes one

void print2sortedarrays(int a[],int b[],int n,int m)
{
int i,j;
i=0;
j=0;
while(i<=n-1 || j<=m-1)
{
if(a[i]==b[j])
{i++;j++;
continue;
}
if(a[i]<b[j])
{
printf("%d",a[i]);
i++;
}
if(a[i>b[j]])
{
printf("%d",b[j]);
j++;
}
}
return;
}
int main(void)
{
int n,m,i,j;
int a[1000],b[1000];
scanf("%d",&n);
for(i=0;i<=n-1;i++)
scanf("%d",&a[i]);
scanf("%d",&m);
for(i=0;i<=n-1;i++)
scanf("%d",&b[i]);
print2sortedarrays(a,b,n,m);
return 0;


}