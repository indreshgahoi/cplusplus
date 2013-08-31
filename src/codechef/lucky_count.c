#include<stdio.h>
int a[100005];
int b[100005];

void setarray(int n)
{
    int k,i=0,j=0,id=n;
    while(n)
    {
        k=n%10;
        n=n/10;
        if(k==4)
         i++;
        else if(k==7)
               j++;

    }
    a[id]=i+a[id-1];
    b[id]=j+b[id-1];
}
int main ()
{
    int t,n,i,j,sum;
    a[0]=b[0]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
          setarray(i);
          sum=0;
         for(i=0;i<n;i++)
           for(j=i+1;j<=n;j++)
             {
                 if((a[j]-a[i])==(b[j]-b[i]))
                  sum++;
             }
             for(i=1;i<=n;i++)
               printf("%d ",a[i]);
                printf("\n\n");
             for(i=1;i<=n;i++)
               printf("%d ",b[i]);
        printf("\n%d\n",sum);
    }
    return 0;
}
