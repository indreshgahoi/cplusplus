#include<stdio.h>
int main()
{
  long long int t,a,b,tmp;
     get(t);
   while(t--)
   {
       scanf("%lld%lld",&a,&b);
       if(a<b){
        t=a;
        a=b;
        b=t;
       }
       while(b)
       {
           t=b;
           b=a%b;
           a=t;
       }
       printf("%lld\n",a);
   }
   return 0;
}
