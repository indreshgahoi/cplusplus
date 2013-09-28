/*this program seacrhes the occurences of a perticular number in an sorted array in O(logn)
complexity very easy just using the binary search twice nothing else.*/

#include<stdio.h>
int firstI(int key,int *a,int n,int low,int high)
{

	int mid=(low+high)/2;
	if((a[mid]==key && a[mid-1]<key)||(mid==0) )
		return mid;
	else if(a[mid]<key)
	{

		return(firstI(key,a,n,mid+1,high));
	}
	else
	{high=mid-1;
	return(firstI(key,a,n,low,mid-1));
	}
	return(-1);
}
int secondI(int key,int *a,int n,int low,int high)
{

	int mid;
	mid=(low+high)/2;
	if((a[mid]==key && a[mid+1]>key)||mid==n-1)
		return mid;
	else if(a[mid]>key)
	{
		return(secondI(key,a,n,low,mid-1));
	}
	else
	{

		return(secondI(key,a,n,mid+1,high));
	}
	return -1;

}
int main()
{
	int *a,n,i,f,s,key;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&a[i]);
	printf("enter the alue to search");
	scanf("%d",&key);
	f=firstI(key,a,n,0,n-1);
	s=secondI(key,a,n,0,n-1);
	printf("\n The no of Occurence of %d is %d",key,s-f+1);
	return 0;
}

