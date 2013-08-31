#include <iostream>
#include <cstdio>
using namespace std;


double z;
long long int gcd(long long int a,long long int b)
{
if(b==0)return a;
return gcd(b,a%b);
}

int main()
{

long long int a,b,c,d,k,x,y,t;
double m,n;
scanf("%lld",&t);
while(t--)
{
 scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
   x=a>b?gcd(a,b):gcd(b,a);
   y=c>d?gcd(c,d):gcd(d,c);
   b=x>y?gcd(x,y):gcd(y,x);

  m=x/b;
  n=m*y;
  m=k/n;
  a=(long long int)m;
    printf("%lld\n",(a<<1)+1);
  }
return 0;
}
