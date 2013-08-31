#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long int A=1,B=1,temp;

int main()
{
  int T,n,p;
  scanf("%d",&T);
  while(T--)
  {
      A=1;B=1;
     scanf("%d%d",&n,&p);
    for(int i=2;i<=n;i++)
    {
        temp=B;
        B=(A+2*B)%p;
        A=(A+temp)%p;
    }
    printf("%lld/%lld\n",A,B);

  }
 return 0;
}
