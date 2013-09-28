#include<stdio.h>
int findkth(int a[],int s1,int len1,int b[],int s2,int len2,int k)
{
	int e1,e2;
	if(len1<=0)
		return(b[k-1]);
	if(len2<=0)
		return(a[k-1]);
	if(k<2)
		return(a[s1]<b[s2]?a[s1]:b[s2]);
	e1=k/2;
	e2=k-e1;
	if(e1>len1)
	{
		e1=len1;
		e2=k-e1;
	}
	if(e2>len2)
	{
		e2=len2;
		e1=k-e2;
	}
	if(a[s1+e1-1]<=b[s2+e2-1])
		return(findkth(a,s1+e1,len1-e1,b,s2,len2,k-e1));
	else

		return(findkth(a,s1,len1,b,s2+e2,len2-e2,k-e2));



}
int main(void)
{
	int a[100],b[100],i,k,m,n;
	fscanf(stdin,"%d",&n);
	fscanf(stdin,"%d",&m);
	for(i=0;i<=n-1;i++)
		fscanf(stdin,"%d",(a+i));
	for(i=0;i<=m-1;i++)
		fscanf(stdin,"%d",(b+i));
	fscanf(stdin,"%d",&k);
	k=findkth(a,0,n,b,0,m,k);
	fprintf(stdout,"the kth element in sorted aray  %d",k);
	return 0;


}
