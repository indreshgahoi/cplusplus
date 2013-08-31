long int b[300000]={0};
long int a[300000]={0};
long int br[300000]={0};
long int ar[300000]={0};
long int sumy=0;
long int sumo=0;
long int heapsizea=0;
long int heapsizeb=0;

long int left(long int i)
{
return(2*i);
}
long int right(long int i)
{
i=2*i+1;
return(i);
}
long int parents(long int i)
{
return(i/2);

}


long int getmax()
{
return(a[1]);
}

long int getmin()
{
return(b[1]);
}

void insertmax(long int i,long int r)
{
long int parent,temp;
a[heapsizea]=i;
ar[heapsizea]=r;
parent=heapsizea/2;
if(parent==0)
{
return;
}
temp=heapsizea;
while(a[parent]<a[temp] && parent!=0)
{
long int temp2,temp3;
temp2=a[parent];
temp3=ar[parent];
a[parent]=a[temp];
ar[parent]=ar[temp];
a[temp]=temp2;
ar[temp]=temp3;
temp=parent;
parent=parents(temp);
}
return;
}

void insertmin(long int i,long int r)
{
long int parent,temp;
b[heapsizeb]=i;
br[heapsizeb]=r;
parent=heapsizeb/2;
if(parent==0)
{
return;
}
temp=heapsizeb;
while(b[parent]>b[temp] && parent!=0)
{
long int temp2,temp3;
temp2=b[parent];
temp3=br[parent];
b[parent]=b[temp];
br[parent]=br[temp];
b[temp]=temp2;
br[temp]=temp3;
temp=parent;
parent=parents(temp);
}
return;
}


void minheapify(long int i)
{
long int smallest;
long int l=left(i);
long int r=right(i);
if(l<=heapsizeb && b[l]<b[i])
{
smallest=l;
}
else
{
smallest=i;
}
if(r<=heapsizeb && b[r]<b[smallest])
{
smallest=r;
}
if(smallest!=i)
{
long int temp,temp2;
temp=b[smallest];
temp2=br[smallest];
b[smallest]=b[i];
br[smallest]=br[i];
b[i]=temp;
br[i]=temp2;
minheapify(smallest);
}
return;
}

void maxheapify(long int i)
{
long int largest;
long int l=left(i);
long int r=right(i);
if(l<=heapsizea && a[l]>a[i])
{
largest=l;
}
else
{
largest=i;
}
if(r<=heapsizea && a[r]>a[largest])
{
largest=r;
}
if(largest!=i)
{
long int temp,temp2;
temp=a[largest];
temp2=ar[largest];
a[largest]=a[i];
ar[largest]=ar[i];
a[i]=temp;
ar[i]=temp2;
maxheapify(largest);
}
return;
}
void extractmax()
{
a[1]=a[heapsizea];
ar[1]=ar[heapsizea];
heapsizea--;
maxheapify(1);

}
void extractmin()
{
b[1]=b[heapsizeb];
br[1]=b[heapsizeb];
heapsizeb--;
minheapify(1);
}

int main()
{
long int n,j,diff,r,ab,i;
scanf("%ld",&n);
for(j=1;j<=n;j++)
{
scanf("%ld",&ab);
scanf("%ld",&r);
if(j%2!=0)
{
long int temp,temp3;
heapsizea++;
if(heapsizeb!=0)
{
temp=getmin();
if(temp<ab)
{
temp3=br[1];
extractmin();
sumo=sumo-temp3;
heapsizeb++;
insertmin(ab,r);
sumo=sumo+r;
r=temp3;
ab=temp;
}
}
insertmax(ab,r);
sumy=sumy+r;
}
else
{
long int temp2,temp3;
heapsizeb++;
temp2=getmax();
if(temp2>ab)
{
temp3=ar[1];
extractmax();

sumy=sumy-temp3;
heapsizea++;
insertmax(ab,r);
sumy=sumy+r;
r=temp3;
ab=temp2;
}
insertmin(ab,r);
sumo=sumo+r;

}

diff=sumo-sumy;
if(diff<0)
{
diff=-1*diff;
}
printf("%d\n",diff);
}

return(0);
}