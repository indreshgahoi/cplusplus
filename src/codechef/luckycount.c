#include<stdio.h>
int main ()
{
  int t,a,i,f1,f2,l,m,n;
  char  num[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",num);

        for(i=0,a=0,l=0,m=0,n=0;num[i]!='\0';i++)
        {   if(num[i]=='4' && !l)
              l=1;
            if(num[i]=='7' && !m)
              m=1;

            if(!(num[i]=='4' || num[i]=='7')){
              n=1;
              a++;
              }
        }
        if((l==0 || m==0)&& n==0)
         printf("1\n");
         else
        printf("%d\n",a);
    }
  return 0;
}
