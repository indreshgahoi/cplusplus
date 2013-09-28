/*a program to find maximum differnece between 
j-i such that j>i and a[j]>a[i] . this algorithm solves 
this problem with taking auxilary space O(n)and time O(n).*/

#include<stdio.h>

int max(int x, int y)
{
	return x > y? x : y;
}

int min(int x, int y)
{
	return x < y? x : y;
}


int maxdiff(int *a,int n)
{
	int *lmin,*rmax;
	lmin=(int*)malloc(sizeof(int)*n);
	rmax=(int*)malloc(sizeof(int)*n);
	lmin[0]=a[0];
	for(i=1;i<=n-1;i++)
	{
		lmin[i]=min(a[i],lmin[i-1]);
	}
	rmax[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
	{
		rmax[i]=max(a[i],rmax[i-1]);
	}

	i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n)
	{
		if (lmin[i] < rmax[j])
		{
			maxDiff = max(maxDiff, j-i);
			j = j + 1;
		}
		else
			i = i+1;
	}
	return(maxDiff);
}

int main()
{
	int *p,max;
	scanf("%d",&n);
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&p[i]);
	}
	max=maxdiff(p,n);
	printf("%d",max);
}
