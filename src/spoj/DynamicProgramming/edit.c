#include<stdio.h>
#define N 1009
char str[N];
int main()
{
    int i,j,k,t,len,min1,min2;
    char u,v;
   // scanf("%d",&t);
    while(~scanf("%s",str+1))
    {

      len=strlen(str+1);
      min1=min2=0;u=v=str[1];j=2;
      for(i=1;i<=len;)
      {
        if(str[i]>=97&&str[i]<=122)min1++;
        if(j<=len&&str[j]>=65&&str[j]<=90)min1++;
        j+=2;i+=2;
      }j=2;
      for(i=1;i<=len;)
      {
        if(str[i]>=65&&str[i]<=90)min2++;
        if(j<=len&&str[j]>=97&&str[j]<=122)min2++;
        j+=2;i+=2;
      }
     /* for(i=2;i<=len;i++)
      {
        if(str[i]<=u)
        {
          u=130;
          min1++;
        }
         else
             u=str[i];
        if(str[i]>=v)
        {
          v=0;
          min2++;
        }
        else
            v=str[i];
      }*/
      printf("%d\n",(min1<min2?min1:min2));
    }
}
