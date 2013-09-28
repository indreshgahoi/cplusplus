#include<stdio.h>
void merge(int a[],int n,int b[],int m,int count)
{
	int k=n-1;
	int i=count-1;
	int j=m-1;
	while(i>=0 ||j>=0)
	{
		a[i]=i>=0?a[i]:-32767;
		b[j]=j>=0?b[j]:-32767;
		if(a[i]>=b[j])
		{
			a[k--]=a[i--];
		}
		else
		{
			a[k--]=b[j--];
		}
	}
}

int main(void)
{
	int i,j,k,count,n,m;
	int a[100],b[100];
	fscanf(stdin,"%d%d",&n,&count);
	for(i=0;i<=count-1;i++)
		fscanf(stdin,"%d",(a+i));
	fscanf(stdin,"%d",&m);
	for(i=0;i<=m-1;i++)
		fscanf(stdin,"%d",(b+i));
	merge(a,n,b,m,count);
	i=0;
	while(i!=n)
	{fprintf(stdout,"%d",a[i]);
	i++;}
	return 0;
}
