int heapsize;

int left(int i)
{
	return(2*i);
}

int right(int i)
{
	return(2*i+1);
}

void maxheapify(int *arr,int i)
{
	int largest;
	int l=left(i);
	int r=right(i);
	if(l<=heapsize && arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if(r<=heapsize && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		int temp;
		temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		maxheapify(arr,largest);
	}
}



void  buildheap(int *arr,int n)
{
	int i;
	for(i=n/2;i>0;i--)
	{
		maxheapify(arr,i);
	}
}

int* heapsort(int *arr,int n)
{
	int i;
	buildheap(arr,n);
	for(i=n;i>=2;i--)
	{
		int temp;
		temp=arr[heapsize];
		arr[heapsize]=arr[1];
		arr[1]=temp;
		heapsize--;
		maxheapify(arr,1);

	}
	return(arr);

}

int main()
{
	int n,*arr,i;

	scanf("%d",&n);
	heapsize=n;
	arr=(int *)malloc(sizeof(int)*(n+1));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	arr=heapsort(arr,n);
	for(i=1;i<=n;i++)
	{
		printf("%d\n",arr[i]);
	}
}

