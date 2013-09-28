void selectionSort(int arr[],int n)
{
	int i,j,temp,loc;
	int min=32768;
	for(i=0;i<=n-2;i++)
	{
		for(j=i;j<=n-1;j++)
		{
			if(min>arr[j])
			{min=arr[j];
			loc=j;
			}
		}
		temp=arr[loc];
		arr[loc]=arr[i];
		arr[i]=temp;
		min=32768;
	}
}
int main(void)
{
	int n,i;
	int arr[100];
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&arr[i]);
	selectionSort(arr,n);
	for(i=0;i<=n-1;i++)
		printf("%d\n",arr[i]);
	return 0;
}

