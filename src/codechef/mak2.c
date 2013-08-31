#include<stdio.h>
#define FOR(a,b,i) for(i=a;i<=b;i++)



int Kadane(int* A,int n,int* pk,int* pl)
{
         *pk=0;
         *pl=0;
         int s=1<<31;
         int t=0;
         int i,j=0;
        for(i=0;i<n;i++)
        {
                 t=t+A[i];
                if(t>s)
               {
                       *pk=j;
                       *pl=i;
                       s=t;
               }
               if(t<0)
              {
                    t=0;
                    j=i+1;
              }
        }
        return s;
}


void maxSubArraySum(int size)
{
   int id=0, max_ending_here = 0;
   memset(max_so_far,0 , sizeof(max_so_far));
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
        max_ending_here = 0;
     if(max_so_far[id-1] < max_ending_here){

        max_so_far[id++] = max_ending_here;
        }
    }

}



int lis(int size)
{   int max=1,i,j,index;

    FOR(0,size-1,i)
      s[i]=a[i];
    FOR(1,size-1,i)
    {
        if(a[i]>=a[i-1])

        FOR(0,i-1,j)
        {
            if(a[i]>=a[j] && s[j]+1>s[i])
              s[i]=s[j]+1;
        }
    }
    FOR(0,9,i)
    {
        if(s[i]>=max)
        {
            max=s[i];
            index=i;
        }

    }
    FOR(0,9,i)
    {
       printf("a[%d]=%d  s[%d]=%d\n",i,a[i],i,s[i]);

    }
    printf("%d\n",index);
    return max;
}
int main()
{
   int t,n,k1,k2,k3,i;
scanf("%d",&t);
while(t--){
scanf("%d%d%d%d",&n,&k1,&k2,&k3);
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     maxSubArraySum(n);
     printf("%d %d %d",max_so_far[k1-1],max_so_far[k2-1],max_so_far[k3-1]);
printf("\n");
}
return(0);
}
