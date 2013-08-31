int minDiff(int arr[],int a,int b,int n)
{
int i;
int last=-1;
int last2=-1;
int diff=32767;
if(a==b)
{
for(i=0;i<=n-1;i++)
{
if(arr[i]==b)
{
if(last!=-1)
{diff=min(diff,abs(i-last));
last=i;}
else
{
last=i;
}

}

}
}

else
{
for(i=0;i<=n-1;i++)
{
if(arr[i]==a)
last=i;
if(arr[i]==b)
last1=i;
if(last!=-1 && last1!=-1)
diff=min(diff,abs(last-last1))
}
}
return diff;

}