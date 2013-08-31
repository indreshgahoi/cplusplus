#include<iostream>
#include<cstdio>
using namespace std;
#include<map>

map <int , long long> P;

long long Calculate_Pn(long long n)
{
  if (n < 0)
     return 0;

  long long Pn = P[n];

  if (Pn == 0)
  {
     long long k;
     for (k = 1; k <= n; k++)
     {
         // A little bit of recursion
         long long n1 = n - k * (3 * k - 1) / 2;
         long long n2 = n - k * (3 * k + 1) / 2;

         long long Pn1 = Calculate_Pn(n1);
         long long Pn2 = Calculate_Pn(n2);

         // elements are alternately added
         // and subtracted
         if (k % 2 == 1)
            Pn = Pn + Pn1 + Pn2;
         else
              Pn = Pn - Pn1 - Pn2;
    }
       P[n]=Pn;
  }
  return Pn;
}

int main()
{
    long long i;
    P[0]=1;
    while (scanf("%lld",&i)!=EOF)
          printf("%lld\n",Calculate_Pn(i));
}
