# include<stdio.h>

int getmedian(int a[],int n)
{
	if(n%2==0)
		return((a[n/2]+a[n/2-1])/2);
	else
		return a[n/2];
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int min(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}



int median(int a1[],int a2[],int n)
{
	int m1,m2;
	if(n<=0)
		return -1;

	if(n==1)
		return((a1[0]+a2[0])/2);

	if(n==2)
	{

		return((max(a1[0],a2[0])+min(a1[1],a2[1]))/2);
	}

	m1=getmedian(a1,n);
	m2=getmedian(a2,n);
	if(m1==m2)
		return m1;


	if(m1<m2)
		return median(a1+n/2,a2,n-n/2);
	else
		return median(a1,a2+n/2,n-n/2);
}



int main(void)
{
	int i;
	int a1[10],a2[10];
	int n,medians;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a1[i]);

	for(i=0;i<=n-1;i++)
		scanf("%d",&a2[i]);

	medians=median(a1,a2,n);

	puts("the median of 2 sorted inputteds arrays is");
	printf("%d",medians);
	return 0;

}
