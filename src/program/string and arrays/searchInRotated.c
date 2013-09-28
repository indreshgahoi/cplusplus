int searchInRotated(int a[],int n,int key)
{
	int end=n-1;
	int start=0;
	int s=0;
	int e=n-1;
	int mid=0;
	if(a[0]>a[n-1])
	{
		while(s<=e)
		{
			mid=(s+e)/2;
			if(a[mid]>a[mid+1])
				break;
			else
			{
				if(a[mid]<a[e])
				{
					e=mid-1;
				}
				else
				{
					s=mid+1;
				}}}}
	if (mid==0)
	{
		while(start<=end)
		{
			mid=(start+end)/2;
			if(a[mid]==key)
				break;
			if(a[mid]>key)
				end=mid-1;
			else
				start=mid+1;
		}
		return mid;
	}
	else
	{
		if(key==a[mid])
			return mid;
		if(key>=a[mid+1] && key <=a[end])
		{
			start=mid+1;
			while(start<=end)
			{
				mid=(start+end)/2;
				if(a[mid]==key)
					break;
				if(a[mid]>key)
					end=mid-1;
				else
					start=mid+1;
			}
			return mid;
		}
		else
		{
			end=mid-1;
			while(start<=end)
			{
				mid=(start+end)/2;
				if(a[mid]==key)
					break;
				if(a[mid]>key)
					end=mid-1;
				else
					start=mid+1;
			}
			return mid;
		}
	}
}

int main(void)
{
	int k;
	int a[10]={6,7,8,9,10,1,2,3,4,5};
	k=searchInRotated(a,10,10);
	printf("position of %d is :%d",a[k],k);
	return 0;


}

