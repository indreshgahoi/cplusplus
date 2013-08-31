#include<iostream>
#include<cstdio>

int a[1005];

void solve(int n)
{
    int count=0;
    int max=a[1],min;
    min=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]> max)
        {
            count++;
            max=a[i];
        }
        else if(a[i]<min)
        {
            min=a[i];
            count++;
        }

    }
    printf("%d",count);
}

int main()
{
    int n;

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    solve(n);
}
