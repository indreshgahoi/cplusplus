#include<stdio.h>
#define FOR(a,b,i) for(i=a;i<=b;i++)
int a[10001];


int main()
{
    int t,n,m,i,max,idx,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        l=0;
        FOR(1,n,i)
        {
         scanf("%d",&m);
         a[m]++;
         if(m>l)
           l=m;
        }
        max=a[1];
        idx=1;
        FOR(2,l,i)
        {
            if(a[i]>max)
            {
                max=a[i];
                idx=i;
            }
        }
        printf("%d %d\n",idx,max);
    }
}
