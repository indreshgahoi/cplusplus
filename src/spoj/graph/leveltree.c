#include<stdio.h>
#include<math.h>

int main()
{
    long long int t,i,n,j,mul;

    for(i=1l;scanf("%lld",&n);i++)
    {   if(n==0)
         break;
        if(n==1)
        printf("Case 1, N = 2, # of different labelings = 1\n");
        else{
            mul=1;
           for(j=1;j<=n-2;j++)
           {
              mul=mul*n;
           }

        printf("Case %lld, N = %lld, # of different labelings = %lld\n",i,n,mul);

        }
    }
    return 0;
}
