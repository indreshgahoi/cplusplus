#include<stdio.h>
int rec_a(int n)
{
	return(n<=5 ? n : (2*rec_a(n-3)));
}
int main()
{
	int k;
	scanf("%d",&k);
	printf("\nmaximum no of a is:%d",rec_a(k));
}

