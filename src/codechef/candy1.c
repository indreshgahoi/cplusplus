#include<stdio.h>
#define puti(i) printf("%ld\n",i)
int a[10001];
int main()
{
    long int sum=0;
    int avg=0,re,num,l,t;
   int id=0;

   while(scanf("%d",&num) != -1)
    {
        if(num==-1)
         break;
        sum=0;
        avg=id=0;
        t=num;
        while(num--)
        {
            scanf("%d",(a+id));
           sum+=a[id++];
           }
        avg=sum/t;
        re=sum%t;
         if(re==0){
        sum=0;
        for(num=0;num<t;num++)
        {   l=a[num];
            if(l>avg)
            {
                sum+=(l-avg);
            }
        }
        printf("%ld\n",sum);
        }
        else{
        printf("-1\n");}

    }
  return 0;
}
