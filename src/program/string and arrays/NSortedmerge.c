// program to merge n dorted array
// here i am taing only 3 sorted arrays
// merging directly prints into the stdout stream
// this can be generalised very easily :)

int heap[4];
int heapsize;
int parent(int i)
{
return i/2;
}
int left(int i)
{
return 2*i;
}
int right(int i)
{
return 2*i+1;

}

void insertmin(int key)
{int parents;
int c;
heapsize++;
parents=parent(heapsize);
heap[heapsize]=key;
c=heapsize;
while(parents>=1 && heap[c]<heap[parents])
{
int temp;
temp=heap[parents];
heap[parents]=heap[c];
heap[c]=temp;
c=parents;
parents=parent(parents);
}
}
void minheapify(int i)
{
int lefts;
int rights;
int smallest=i;
lefts=left(i);
rights=right(i);
if(heapsize>=lefts && heap[i]>heap[lefts])
smallest=lefts;
if(heapsize>=rights && heap[smallest]>heap[rights])
smallest=rights;
if(smallest!=i)
{
int temp;
temp=heap[smallest];
heap[smallest]=heap[i];
heap[i]=temp;
minheapify(smallest);
}
return;
}
int extractmin()
{
int min;
min=heap[1];
heap[1]=heap[heapsize];
heapsize--;
minheapify(1);
return min;
}




void mergeNsorted(int a1[],int a2[],int a3[],int n1,int n2,int n3)
{
int i1,i2,key,i3;
i1=i2=i3=0;
insertmin(a1[i1]);
insertmin(a2[i2]);
insertmin(a3[i3]);
while(i1<n1-1 || i2<n2-1 || i3<n3-1)
{
key=extractmin();
printf("%d\n",key);
if(key==a1[i1] && i1 <n1-1)
{
i1++;
insertmin(a1[i1]);
continue;
}
if(key==a2[i2] && i2<n2-1)
{

i2++;
insertmin(a2[i2]);
continue;
}
if(key==a3[i3] && i3<n3-1)
{
i3++;
insertmin(a3[i3]);
}
}
key=extractmin();
printf("%d",key);
}

int main(void)
{
int a1[5]={1,7,9,16,19};
int a2[5]={2,17,20,25,29};
int a3[5]={3,6,8,12,15};
mergeNsorted(a1,a2,a3,5,5,5);

return 0;

}
