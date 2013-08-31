#include<stdio.h>
int main()
{
    int T;
    unsigned long long N,res;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&N);
        res=(((3*(N*N)+N)/2))%1000007;
        printf("%lld\n",res);
    }
    return 0;
}
