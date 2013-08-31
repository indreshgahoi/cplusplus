#include<stdio.h>
#define MAX 1000000000
int main()
{
    int i,num,mul,cnt=0,sum,k;
    for(i=111111111;i<=MAX;i++)
    {
        num=i;
        sum=0;
        mul=1;
        while(num)
        {   k=num%10;
           if(!k)
              break;
            sum=sum+k;
            mul=mul*k;
            num/=10;
        }
        if(!num && mul%sum==0){
         printf("%d: %d, \n",++cnt,i);}
    }

    return 0;
}
