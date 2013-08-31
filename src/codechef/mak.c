#include<stdio.h>
#include<string.h>
int max_so_far[100];
int a[100];
void maxSubArraySum(int size)
{
   int id=0, max_ending_here = 0;
   memset(max_so_far,0 , sizeof(max_so_far));
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
    // if(max_ending_here < 0)
        //max_ending_here = 0;
     if(max_so_far[id] < max_ending_here){

        max_so_far[id++] = max_ending_here;
        }
    }

}

/*Driver program to test maxSubArraySum*/
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
