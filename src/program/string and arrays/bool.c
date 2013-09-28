#include<stdio.h>
int main()
{
	int a[2];
	scanf("%d%d",&a[0],&a[1]);
	a[a[1]]=a[a[0]];
	printf("\n%d %d",a[0],a[1]);
	return(0);
}
