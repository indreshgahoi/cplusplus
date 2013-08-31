#include<stdio.h>
#include<stdlib.h>
#define N 65
int a[100000000000];
char s[N];
int modular_exponent(int a,long long b,long long n)
{
    int c,d=1,i;
    itoa(b,s,2);
    printf("%s %d",s,strlen(s));
    for(i=strlen(s)-1;i>=0;i--)
    {
      d=(d*d)%n;
      if(s[i]==1)
      d=(d*a)%n;
    }printf("  %d\n",d);
    return d;
}
int main()
{

  int i,t;
  long long n;
  scanf("%d",&t);
  while(t-->0)
  {
      scanf("%lld",&n);
      if(modular_exponent(2,n-1,n)%n!=1)printf("COMPOSITE\n");
      else printf("PRIME\n");
  }
  return 0;
}
