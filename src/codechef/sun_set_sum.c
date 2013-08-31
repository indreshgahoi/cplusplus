#include<stdio.h>

int count,w[10],d,x[10];

void subset(int cs,int k,int r)
{
   int i;
   x[k]=1;
   if((cs+w[k])>d)
    {
       printf("\n Subset solution = %d\n",++count);
       for(i=0; i<=k; i++)
       {
         if(x[i]==1)
         printf("%d\n",w[i]);
       }
     }
  else if(cs+w[k]+w[k+1] <=d)
        subset(cs+w[k],k+1,r-w[k]);
    if((cs+r-w[k]>=d)&&(cs+w[k+1])<=d)
    {
      x[k]=0;
      subset(cs,k+1,r-w[k]);
    }
}

int main()
{
    int sum=0,i,n;
    printf("enter no of elements\n");
    scanf("%d",&n);
   for(i=0; i<n; i++)
      w[i]=i+1;

    count =0;
    subset(0,0,n);
    return 0;
    getch();
}
