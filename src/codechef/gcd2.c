#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if(b==0)
      return a;
else
     return gcd(b,a%b);
}

int main()
{
    unsigned long long a,l,gp[26];
    char b[251];
    int t,c,len,i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld%s",&a,b);
        if (a == 0)
           {
            printf("%s\n",b);
            continue;
            }

    len=strlen(b)-5;
     c=0;
    for(i=len;i>=0;i-=5,c++)
    {
        gp[c]=atol(b+i);
        b[i]='\0';
    }
    gp[c]=atol(b);
     c++;
    i=c-1;
   l=gp[i];

   while(i>=0)
   {
       if(l<a)
       {
           i--;
           if(i<0)
             break;
           l=l*100000+gp[i];
       }

       l=l%a;
   }
   printf("%lld\n",gcd(a,l));

    }
  return 0;
}
