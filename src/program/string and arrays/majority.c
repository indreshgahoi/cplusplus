// majority element of an array means a element found in array more than n+1 times
// moores voting algorithm :)
int mooresmajority(int arr[],int n)
{
int i,num=arr[0];
int count=1;
for(i=1;i<=n-1;i++)
{
if(num==arr[i])
count++;
else
count--;
if(count==0)
{
num=arr[i];
count=1;
}
}
return num;
}

void ismajority(int arr[],int n)
{
int num;
int i;
int count=0;
num=mooresmajority(arr,n);
for(i=0;i<=n;i++)
  if(arr[i]==num)
      count++;
if(count>n/2)
printf("the majoriy element is %d",num);
else
printf("majority element doesnt exist");
return;
}
int main(void)
{
int arr[100];
int n,i;
scanf("%d",&n);
for(i=0;i<=n-1;i++)
scanf("%d",&arr[i]);
ismajority(arr,n);
return 0;
}